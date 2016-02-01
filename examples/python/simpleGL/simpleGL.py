#!/usr/bin/env python

# PyJuggler is (C) Copyright 2002-2012 by Patrick Hartling
# Distributed under the GNU Lesser General Public License 2.1.  (See
# accompanying file COPYING.txt or http://www.gnu.org/copyleft/lesser.txt)

import sys

# import logging
# logging.basicConfig(level=logging.DEBUG)

import OpenGL
# OpenGL.FULL_LOGGING = True
from OpenGL.GL import *
from OpenGL.arrays import vbo
from OpenGLContext.arrays import *
from OpenGL.GL import shaders
import gmtl
import numpy as np

import os
import pprint

if sys.platform == 'darwin':
    os.environ['NO_RTRC_PLUGIN'] = "1"
    os.environ['NO_PERF_PLUGIN'] = "1"

# NOTE: If you import the individual modules from PyJuggler, make sure to
# import PyJuggler.vrj first.
from PyJuggler import *
import PyJuggler.vrj as vrj
import PyJuggler.gadget as gadget


class SimpleGlApp(vrj.opengl.App):
    def __init__(self):
        vrj.opengl.App.__init__(self)

        self.mButton0 = gadget.DigitalInterface()
        self.mButton1 = gadget.DigitalInterface()
        self.mButton2 = gadget.DigitalInterface()
        self.mWand = gadget.PositionInterface()
        self.mHead = gadget.PositionInterface()

        self.mGrabbed = False
        self.frame    = 0

    def init(self):
        self.mButton0.init("DigitalProxy-Button0")
        self.mButton1.init("DigitalProxy-Button1")
        self.mButton2.init("DigitalProxy-Button2")
        self.mWand.init("SimPositionDevice-Wand")
        self.mHead.init("SimPositionDevice-Head")

    def getDrawScaleFactor(self):
        return gadget.PositionUnitConversion.ConvertToMeters

    def contextInit(self):
        self.initGLState()

        vertex_shader = shaders.compileShader("""#version 430
        uniform mat4 pvm_matrix;
        layout(location = 0) in vec3 vertex_position_modelspace;
        void main() {
            vec4 v = vec4(vertex_position_modelspace, 1);
            gl_Position = pvm_matrix * v;
        }""", GL_VERTEX_SHADER)

        fragment_shader = shaders.compileShader("""#version 430
        out vec4 fragment_color;
        void main() {
            fragment_color = vec4(0, 1, 0, 1);
        }""", GL_FRAGMENT_SHADER)

        self.shader = shaders.compileProgram(vertex_shader, fragment_shader)

        self.pvm_matrix = glGetUniformLocation(self.shader, 'pvm_matrix')

        self.vbo = vbo.VBO(
            array([
                -1.0, -1.0, -1.0,
                -1.0, -1.0, 1.0,
                -1.0, 1.0, 1.0,
                1.0, 1.0, -1.0,
                -1.0, -1.0, -1.0,
                -1.0, 1.0, -1.0,
                1.0, -1.0, 1.0,
                -1.0, -1.0, -1.0,
                1.0, -1.0, -1.0,
                1.0, 1.0, -1.0,
                1.0, -1.0, -1.0,
                -1.0, -1.0, -1.0,
                -1.0, -1.0, -1.0,
                -1.0, 1.0, 1.0,
                -1.0, 1.0, -1.0,
                1.0, -1.0, 1.0,
                -1.0, -1.0, 1.0,
                -1.0, -1.0, -1.0,
                -1.0, 1.0, 1.0,
                -1.0, -1.0, 1.0,
                1.0, -1.0, 1.0,
                1.0, 1.0, 1.0,
                1.0, -1.0,-1.0,
                1.0, 1.0, -1.0,
                1.0, -1.0, -1.0,
                1.0, 1.0, 1.0,
                1.0, -1.0, 1.0,
                1.0, 1.0, 1.0,
                1.0, 1.0, -1.0,
                -1.0, 1.0, -1.0,
                1.0, 1.0, 1.0,
                -1.0, 1.0, -1.0,
                -1.0, 1.0, 1.0,
                1.0, 1.0, 1.0,
                -1.0, 1.0, 1.0,
                1.0, -1.0, 1.0,
            ], 'f')
        )

        self.vertex_array_id = 0
        glGenVertexArrays(1, self.vertex_array_id)
        glBindVertexArray(self.vertex_array_id)

    def preFrame(self):
        if self.mButton0.getData():
            self.mGrabbed = True
        else:
            self.mGrabbed = False

    def bufferPreDraw(self):
        glClearColor(0.1, 0.1, 0.1, 1.0)
        glClear(GL_COLOR_BUFFER_BIT)

    def draw(self):
        glClear(GL_DEPTH_BUFFER_BIT)
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE)

        user_data = self.getDrawManager().currentUserData()
        projection = user_data.getProjection()
        print(projection)

        pv_matrix_data = self.getPVMatrix()
        print(pv_matrix_data)

        pv_matrix = gmtl.Matrix44f()
        pv_matrix.set(pv_matrix_data)

        box_rotate = gmtl.Matrix44f()
        box_translate = gmtl.Matrix44f()
        box_transform = gmtl.Matrix44f()

        # Move the box to the wand's position if the box is grabbed.
        if self.mGrabbed:
            wand_transform = self.mWand.getData()
            gmtl.setRot(box_rotate, gmtl.makeRotEulerAngleXYZ(wand_transform))
            box_translate = gmtl.makeTrans(gmtl.makeTransVec3(wand_transform))
        else:
            box_offset = gmtl.Vec3f(0.0, 0.0, -2.0)
            gmtl.setRot(box_rotate, gmtl.EulerAngleXYZf(0.0, 0.0, 0.0))
            box_translate = gmtl.makeTransMatrix44(box_offset)

        gmtl.mult(box_transform, box_rotate, box_translate)
        pvm_matrix = gmtl.Matrix44f()
        gmtl.mult(pvm_matrix, pv_matrix, box_transform)

        shaders.glUseProgram(self.shader)
        glUniformMatrix4fv(self.pvm_matrix, 1, GL_FALSE, pvm_matrix.getData())

        glEnableVertexAttribArray(0)
        self.vbo.bind()
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, None)
        glDrawArrays(GL_TRIANGLES, 0, 12*3)
        glDisableVertexAttribArray(0)
        self.vbo.unbind()
        # glDisableClientState(GL_VERTEX_ARRAY)

    def initGLState(self):
        glLight(GL_LIGHT0, GL_AMBIENT, [0.1, 0.1, 0.1, 1.0])
        glLight(GL_LIGHT0, GL_DIFFUSE, [0.8, 0.8, 0.8, 1.0])
        glLight(GL_LIGHT0, GL_SPECULAR, [1.0, 1.0, 1.0, 1.0])
        glLight(GL_LIGHT0, GL_POSITION, [0.0, 0.75, 0.75, 0.0])

        glMaterial(GL_FRONT, GL_AMBIENT, [0.7, 0.7, 0.7, 1.0])
        glMaterial(GL_FRONT, GL_DIFFUSE, [1.0, 0.5, 0.8, 1.0])
        glMaterial(GL_FRONT, GL_SPECULAR, [1.0, 1.0, 1.0, 1.0])
        glMaterial(GL_FRONT, GL_SHININESS, [50.0])
        glMaterial(GL_FRONT, GL_EMISSION, [0.0, 0.0, 0.0, 1.0])

        glEnable(GL_DEPTH_TEST)
        glEnable(GL_NORMALIZE)
        # glEnable(GL_LIGHTING)
        glEnable(GL_LIGHT0)
        # glEnable(GL_COLOR_MATERIAL)
        glShadeModel(GL_SMOOTH)

def main():
    app = SimpleGlApp()
    kernel = vrj.Kernel.instance()

    for arg in sys.argv[1:]:
        kernel.loadConfigFile(arg)

    kernel.start()
    kernel.setApplication(app)
    kernel.waitForKernelStop()

if __name__ == "__main__":
    main()
