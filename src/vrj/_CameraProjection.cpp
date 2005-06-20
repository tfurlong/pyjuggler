// PyJuggler is (C) Copyright 2002-2005 by Patrick Hartling
// Distributed under the GNU Lesser General Public License 2.1.  (See
// accompanying file COPYING.txt or http://www.gnu.org/copyleft/lesser.txt)

// File:          $RCSfile$
// Date modified: $Date$
// Version:       $Revision$

// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <vrj/Display/CameraProjection.h>

// Using =======================================================================
using namespace boost::python;

// Declarations ================================================================
namespace pyj
{

struct vrj_CameraProjection_Wrapper : vrj::CameraProjection
{
   vrj_CameraProjection_Wrapper(PyObject* self_,
                                const vrj::CameraProjection& p0)
      : vrj::CameraProjection(p0)
      , self(self_)
   {
      /* Do nothing. */ ;
   }

   vrj_CameraProjection_Wrapper(PyObject* self_)
      : vrj::CameraProjection()
      , self(self_)
   {
      /* Do nothing. */ ;
   }

   virtual ~vrj_CameraProjection_Wrapper()
   {
      /* Do nothing. */ ;
   }

   void calcViewMatrix(gmtl::Matrix44f& p0, const float p1)
   {
      try
      {
         call_method<void>(self, "calcViewMatrix", p0, p1);
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }
   }

   void default_calcViewMatrix(gmtl::Matrix44f& p0, const float p1)
   {
      vrj::CameraProjection::calcViewMatrix(p0, p1);
   }

   PyObject* self;
};

}// namespace 


// Module ======================================================================
void _Export_CameraProjection()
{
    class_<vrj::CameraProjection, bases<vrj::Projection>,
           pyj::vrj_CameraProjection_Wrapper>
      ("CameraProjection",
       "Projection class that simply takes a matrix for the camera position.",
       init<>()
      )
      .def(init<const vrj::CameraProjection&>())
      .def_readwrite("mVertFOV", &vrj::CameraProjection::mVertFOV)
      .def("calcViewMatrix",
           (void (vrj::CameraProjection::*)(gmtl::Matrix44f&, const float)) &vrj::CameraProjection::calcViewMatrix,
           (void (pyj::vrj_CameraProjection_Wrapper::*)(gmtl::Matrix44f&, const float)) &pyj::vrj_CameraProjection_Wrapper::default_calcViewMatrix,
           "calcViewMatrix(cameraPos, scaleFactor)\n"
           "Calculates the view matrix and frustum for the camera.\n"
           "Calculates a perspective transform for the given settings.\n"
           "Auto-calculates the aspect ratio from the current size of the\n"
           "window and viewport.\n\n"
           "Arguemnts:\n"
           "cameraPos   -- A gmtl.Matrix44f object that represents the\n"
           "               camera position.\n"
           "scaleFactor -- The scaling factor."
      )
   ;
}
