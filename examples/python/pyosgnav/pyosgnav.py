#!/usr/bin/env python

# PyJuggler is (C) Copyright 2002-2005 by Patrick Hartling
# Distributed under the GNU Lesser General Public License 2.1.  (See
# accompanying file COPYING.txt or http://www.gnu.org/copyleft/lesser.txt)

# File:          $RCSfile$
# Date modified: $Date$
# Version:       $Revision$

import sys
import gmtl
from OpenGL.GL import *
from PyOSG import *

import os

if os.name == 'mac':
   os.environ['NO_RTRC_PLUGIN'] = "1"
   os.environ['NO_PERF_PLUGIN'] = "1"

from PyJuggler import *


class NavData(vpr.SerializableObject):
   ''' Serializable data structure for holding the navigator data. '''
   def __init__(self):
#      vpr.SerializableObject.__init__(self)
      pass

   def readObject(self, reader):
      pos_data = []

      for x in range(16):
         pos_data.append(reader.readFloat())

      self.mCurPos.set(pos_data)

      return vpr.ReturnStatus.Code.Succeed

   def writeObject(self, writer):
      pos_data = self.mCurPos.getData()

      for x in range(16):
         writer.writeFloat(pos_data[x])

      return vpr.ReturnStatus.Code.Succeed

   mCurPos = gmtl.Matrix44f()

class NavMode:
   WALK = 0
   FLY  = 1

class OsgNavigator:
   def __init__(self):
      self.mActive = False
      self.mMode   = NavMode.FLY

      # How can we share this data across the nodes of a cluster?
      self.mNavData = NavData()

      self.mVelocity    = gmtl.Vec3f()
      self.mRotVelocity = gmtl.Matrix44f()

   def init(self):
      self.mActive = True

   def setWalkMode(self, walkMode):
      self.mMode = walkMode

   def setVelocity(self, vel):
      self.mVelocity = vel

   def setRotationalVelocity(self, rotVel):
      self.mRotVelocity = rotVel

   # Class member for an identity matrix.  This is a class member so that it
   # only has to be allocated and initialized exactly once instead of once per
   # frame.
   identity_mat = gmtl.Matrix44f()

   def update(self, delta):
      if delta > 2.0 or not self.mActive:
         print "Delta too big or not active; returning."
         return

#      if not self.mNavData.isLocal():
#         return

      # Clamp delta.
      if delta > 1.0:
         delta = 1.0

      # *** Rotation ***

      # Scale the rotation velocity (slerp) to get a time-based change.
      qrot = gmtl.Quatf()
      gmtl.set(qrot, self.mRotVelocity)

      scaled_qrot = gmtl.Quatf()
      src_rot     = gmtl.Quatf()
      delta_rot   = gmtl.Matrix44f()

      # Only compute if we don't have identity rotation.
      if not gmtl.isEqual(self.identity_mat, self.mRotVelocity, 0.001):
         gmtl.slerp(scaled_qrot, delta, src_rot, qrot, True)
         gmtl.set(delta_rot, scaled_qrot)

      if self.mMode == NavMode.WALK:
         euler = gmtl.EulerAngleXYZf(0.0, gmtl.makeYRot(delta_rot), 0.0)
         delta_rot = gmtl.makeRotMatrix44(euler)

      gmtl.postMult(self.mNavData.mCurPos, delta_rot)

      # *** Translation ***
      trans_delta = gmtl.Vec3f()

      if self.mMode == NavMode.WALK:
         self.mVelocity[1] = 0.0

      # XXX: This should work...
#      trans_delta = self.mVelocity * delta
      trans_delta[0] = self.mVelocity[0] * delta
      trans_delta[1] = self.mVelocity[1] * delta
      trans_delta[2] = self.mVelocity[2] * delta

      trans_matrix = gmtl.makeTransMatrix44(trans_delta)
      gmtl.postMult(self.mNavData.mCurPos, trans_matrix)

   def getCurPos(self):
      if self.mActive:
         return self.mNavData.mCurPos
      else:
         return gmtl.Matrix44f()

   def setCurPos(self, pos):
      if self.mActive:
         self.mNavData.mCurPos = pos

class PyOsgNav(vrj.OsgApp):
   def __init__(self, filename):
      vrj.OsgApp.__init__(self)

      self.mFileToLoad = filename

      self.mNavigator        = OsgNavigator()
      self.mLastPreFrameTime = vpr.Interval.now()

      self.mButton0 = gadget.DigitalInterface()
      self.mButton1 = gadget.DigitalInterface()
      self.mButton2 = gadget.DigitalInterface()
      self.mWand    = gadget.PositionInterface()

      # The top level nodes of the tree.
      self.mRootNode   = osg.Group()
      self.mNoNav      = osg.Group()
      self.mNavTrans   = osg.MatrixTransform()
      self.mModelTrans = osg.MatrixTransform()

   def initScene(self):
      self.mButton0.init("VJButton0")
      self.mButton1.init("VJButton1")
      self.mButton2.init("VJButton2")
      self.mWand.init("VJWand")

      self.__myInit()

   def getScene(self):
      return self.mRootNode

   # XXX: Not currently working because Boost.Python does not seem to know
   # about PyOSG.osgUtil.SceneView.
   def configSceneView(self, newSceneViewer):
      vrj.OsgApp.configSceneView(self, newSceneViewer)

      newSceneViewer.getLight().setAmbient(osgVec4(0.3, 0.3, 0.3, 1.0))
      newSceneViewer.getLight().setDiffuse(osgVec4(0.9, 0.9, 0.9, 1.0))
      newSceneViewer.getLight().setSpecular(osgVec4(1.0, 1.0, 1.0, 1.0))

   def preFrame(self):
      cur_time = self.mWand.getTimeStamp()
      diff_time = vpr.Interval(cur_time - self.mLastPreFrameTime)

      if self.mLastPreFrameTime.getBaseVal() >= cur_time.getBaseVal():
         diff_time.secf(0.0)

      time_delta = diff_time.secf()
      self.mLastPreFrameTime = cur_time

      wand_matrix = self.mWand.getData()

      # If we are pressing button 1, then translate in the direction that the
      # wand is pointing.
      if self.mButton0.getData() == gadget.Digital.State.ON:
         direction = gmtl.Vec3f()
         z_dir = gmtl.Vec3f(0.0, 0.0, -10.0)
         gmtl.xform(direction, wand_matrix, z_dir)

         self.mNavigator.setVelocity(direction)
      # Reset the velocity when we stop pressing the button.
      elif self.mButton0.getData() == gadget.Digital.State.TOGGLE_OFF:
         self.mNavigator.setVelocity(gmtl.Vec3f(0.0, 0.0, 0.0))

      if self.mButton1.getData() == gadget.Digital.State.TOGGLE_ON:
         print "Current position:", self.mNavigator.getCurPos()

      # If we are pressing button 2, then rotate in the direction that the
      # wand is pointing.
      if self.mButton2.getData() == gadget.Digital.State.ON:
         euler = gmtl.EulerAngleXYZf(0.0, gmtl.makeYRot(wand_matrix), 0.0)
         rot_mat = gmtl.makeRotMatrix44(euler)
         self.mNavigator.setRotationalVelocity(rot_mat)
      # Reset the rotational velocity when we stop pressing the button.
      elif self.mButton2.getData() == gadget.Digital.State.TOGGLE_OFF:
         self.mNavigator.setRotationalVelocity(gmtl.Matrix44f())

      self.mNavigator.update(time_delta)

   def latePreFrame(self):
      world_transform = gmtl.Matrix44f()
      gmtl.invertFull(world_transform, self.mNavigator.getCurPos())

      osg_current_matrix = osg.Matrix()
      osg_current_matrix.set(tuple(world_transform.getData()))
      self.mNavTrans.setMatrix(osg_current_matrix)

   def bufferPreDraw(self):
      glClearColor(0.0, 0.0, 0.0, 0.0)
      glClear(GL_COLOR_BUFFER_BIT)

   def __myInit(self):
      #           /-- mNoNav
      #  mRootNode
      #          \-- mNavTrans -- mModelTrans -- mModel

      self.mNavigator.init()

      self.mRootNode.addChild(self.mNoNav)
      self.mRootNode.addChild(self.mNavTrans)

      print "Attempting to load file:", self.mFileToLoad, "...",
      self.mModel = osgDB.readNodeFile(self.mFileToLoad)
      print "done."

      self.mModelTrans.preMult(osg.Matrix.rotate(gmtl.deg2Rad(-90.0),
                                                 1.0, 0.0, 0.0))

      if self.mModel is None:
         print "ERROR: Could not load file '", self.mFileToLoad, "'"
      else:
         # Add the model to the transform.
         self.mModelTrans.addChild(self.mModel)

      # Add the transform to the tree.
      self.mNavTrans.addChild(self.mModelTrans)

      # Run optimization over the scenegraph.
      optimizer = osgUtil.Optimizer()
      optimizer.optimize(self.mRootNode)

if __name__ == "__main__":
   app    = PyOsgNav(sys.argv[1])
   kernel = vrj.Kernel.instance()

   for arg in sys.argv[2:]:
      kernel.loadConfigFile(arg)

   kernel.start()
   kernel.setApplication(app)
   kernel.waitForKernelStop()
