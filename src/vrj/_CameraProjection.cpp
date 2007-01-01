// PyJuggler is (C) Copyright 2002-2007 by Patrick Hartling
// Distributed under the GNU Lesser General Public License 2.1.  (See
// accompanying file COPYING.txt or http://www.gnu.org/copyleft/lesser.txt)

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

struct vrj_CameraProjection_Wrapper
   : vrj::CameraProjection
   , wrapper<vrj::CameraProjection>
{
   vrj_CameraProjection_Wrapper(const vrj::CameraProjection& p0)
      : vrj::CameraProjection(p0)
   {
      /* Do nothing. */ ;
   }

   vrj_CameraProjection_Wrapper()
      : vrj::CameraProjection()
   {
      /* Do nothing. */ ;
   }

   virtual ~vrj_CameraProjection_Wrapper()
   {
      /* Do nothing. */ ;
   }

   void calcViewMatrix(const gmtl::Matrix44f& p0, const float p1)
   {
      try
      {
         if ( override calcViewMatrix = this->get_override("calcViewMatrix") )
         {
            calcViewMatrix(boost::ref(p0), p1);
         }
         else
         {
            vrj::CameraProjection::calcViewMatrix(p0, p1);
         }
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }
   }

   void default_calcViewMatrix(const gmtl::Matrix44f& p0, const float p1)
   {
      vrj::CameraProjection::calcViewMatrix(p0, p1);
   }
};

}// namespace 


// Module ======================================================================
void _Export_CameraProjection()
{
   class_<pyj::vrj_CameraProjection_Wrapper, bases<vrj::Projection> >
      ("CameraProjection",
       "Projection class that simply takes a matrix for the camera position.",
       init<>()
      )
      .def(init<const vrj::CameraProjection&>())
      .def_readwrite("mVertFOV", &vrj::CameraProjection::mVertFOV)
      .def("calcViewMatrix", &vrj::CameraProjection::calcViewMatrix,
           &pyj::vrj_CameraProjection_Wrapper::default_calcViewMatrix,
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
