#!/usr/bin/env python

# PyJuggler is (C) Copyright 2002-2008 by Patrick Hartling
# Distributed under the GNU Lesser General Public License 2.1.  (See
# accompanying file COPYING.txt or http://www.gnu.org/copyleft/lesser.txt)

import sys
import gmtl
from OpenGL.GL import *
import osg

import os

if sys.platform == 'darwin':
   os.environ['NO_RTRC_PLUGIN'] = "1"
   os.environ['NO_PERF_PLUGIN'] = "1"

from PyJuggler import *
import PyJuggler.vrj.opengl as vrj.opengl
import PyJuggler.vrj.opensg as vrj.opensg


class PyOpenSGNav(vrj.opensg.App):
   def __init__(self, filename):
      vrj.opensg.App.__init__(self)

      self.mFileToLoad = filename

      self.mButton0 = gadget.DigitalInterface()
      self.mButton1 = gadget.DigitalInterface()
      self.mButton2 = gadget.DigitalInterface()
      self.mWandPos = gadget.PositionInterface()

      self.mVelocity = 0.0
      self.mSceneRoot = None

   def initScene(self):
      self.mButton0.init("VJButton0")
      self.mButton1.init("VJButton1")
      self.mButton2.init("VJButton2")
      self.mWandPos.init("VJWand")

      if self.mFileToLoad is None:
         model_root = osg.makeTorus(0.5, 2, 16, 16)
      else:
         print "Attempting to load file:", self.mFileToLoad, "...",
         model_root = osg.SceneFileHandler.the().read(self.mFileToLoad)
         print "done."

      # Light setup.
      # - Add directional light for scene
      # - Create a beacond for it and connect to that beacond
      light_node        = osg.Node.create()
      light_beacon      = osg.Node.create()
      light_core        = osg.DirectionalLight.create()
      light_beacon_core = osg.Transform.create()

      # Set up light beacon.
      light_pos = osg.Matrix()
      light_pos.setTransform(osg.Vec3f(2.0, 5.0, 4.0))

      osg.beginEditCP(light_beacon_core)
      light_beacon_core.setMatrix(light_pos)
      osg.endEditCP(light_beacon_core)

      osg.beginEditCP(light_beacon)
      light_beacon.setCore(light_beacon_core)
      osg.endEditCP(light_beacon)

      # Set up light node.
      osg.beginEditCP(light_node)
      light_node.setCore(light_core)
      light_node.addChild(light_beacon)
      osg.endEditCP(light_node)

      osg.beginEditCP(light_core)
      light_core.setAmbient(0.9, 0.8, 0.8, 1)
      light_core.setDiffuse(0.6, 0.6, 0.6, 1)
      light_core.setSpecular(1, 1, 1, 1)
      light_core.setDirection(0, 0, 1)
      light_core.setBeacon(light_node)
      osg.endEditCP(light_core)

      # Set up scene.
      # Add the loaded scene to the light node so that it is lit.
      osg.beginEditCP(light_node)
      light_node.addChild(model_root)
      osg.endEditCP(light_node)

      # Create the root part of the scene.
      self.mSceneRoot      = osg.Node.create()
      self.mSceneTransform = osg.Transform.create()

      osg.beginEditCP(self.mSceneRoot)
      self.mSceneRoot.setCore(self.mSceneTransform)
      self.mSceneRoot.addChild(light_node)
      osg.endEditCP(self.mSceneRoot)

   def getScene(self):
      return self.mSceneRoot

   def contextInit(self):
      vrj.opensg.App.contextInit(self)
      self._initGLState()

   sIncVel = 0.005      # Initial velocity
   sMaxVel = 0.5        # Maximum velocity

   def preFrame(self):
      if self.mButton0.getData() == gadget.Digital.State.ON:
         self.mVelocity = self.mVelocity + self.sIncVel
      elif self.mVelocity > 0:
         self.mVelocity = self.mVelocity - self.sIncVel

      if self.mVelocity < 0:
         self.mVelocity = 0
      if self.mVelocity > self.sMaxVel:
         self.mVelocity = self.sMaxVel

      if self.mButton1.getData() == gadget.Digital.State.ON:
         self.mVelocity = 0

      # Travel in model
      # - Find forward direction of wand
      # - Translate along that direction

      # Get the wand matrix
      # NOTE: We ask for the wand transformation matrix in the same units that
      # we are using for this application object.
      wand_mat = self.mWandPos.getData(self.getDrawScaleFactor())
      z_dir = gmtl.Vec3f(0.0, 0.0, self.mVelocity)
      trans = wand_mat * z_dir

      trans_mat = osg.Matrix.identity()
      trans_mat.setTranslate(trans[0], trans[1], trans[2])

      cur_mat = self.mSceneTransform.getMatrix()
      cur_mat.multLeft(trans_mat)
      osg.beginEditCP(self.mSceneTransform)
      self.mSceneTransform.setMatrix(cur_mat)
      #self.mSceneTransform.getMatrix().multLeft(trans_mat)
      osg.endEditCP(self.mSceneTransform)

   def bufferPreDraw(self):
      glClearColor(0.0, 0.0, 0.0, 0.0)
      glClear(GL_COLOR_BUFFER_BIT)

   def exit(self):
      self.mSceneRoot = None
      vrj.opensg.App.exit(self)

   def _initGLState(self):
      # OpenSG does not handle this yet. Being smart about it is non-trivial.
      glEnable(GL_NORMALIZE)

if __name__ == "__main__":
   if sys.argv[1].endswith(".jconf"):
      model     = None
      cfg_files = sys.argv[1:]
   else:
      model     = sys.argv[1]
      cfg_files = sys.argv[2:]

   app    = PyOpenSGNav(model)
   kernel = vrj.Kernel.instance()

   for arg in cfg_files:
      kernel.loadConfigFile(arg)

   kernel.start()
   kernel.setApplication(app)
   kernel.waitForKernelStop()
