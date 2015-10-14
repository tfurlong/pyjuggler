// PyJuggler is (C) Copyright 2002-2012 by Patrick Hartling
// Distributed under the GNU Lesser General Public License 2.1.  (See
// accompanying file COPYING.txt or http://www.gnu.org/copyleft/lesser.txt)

// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <vrj/Display/SimViewport.h>
#include <vrj/Display/Display.h>
#include <vrj/Draw/DrawSimInterface.h>
#include <vrj/Kernel/User.h>

// Using =======================================================================
using namespace boost::python;

// Declarations ================================================================
namespace pyj
{

struct vrj_SimViewport_Wrapper : vrj::SimViewport, wrapper<vrj::SimViewport>
{
   vrj_SimViewport_Wrapper()
      : vrj::SimViewport()
   {
      /* Do nothing. */ ;
   }

   virtual ~vrj_SimViewport_Wrapper()
   {
      /* Do nothing. */ ;
   }

   void updateProjections(const float p0)
   {
      try
      {
         if ( override updateProjections =
                 this->get_override("updateProjections") )
         {
            updateProjections(p0);
         }
         else
         {
            vrj::SimViewport::updateProjections(p0);
         }
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }
   }

   void default_updateProjections(const float p0)
   {
      vrj::SimViewport::updateProjections(p0);
   }
};

inline tuple vrj_SimViewport_getOriginAndSize_wrapper(vrj::SimViewport* vp)
{
   float xo, yo, xs, ys;
   vp->getOriginAndSize(xo, yo, xs, ys);
   return make_tuple(xo, yo, xs, ys);
}

}// namespace 


// Module ======================================================================
void _Export_SimViewport()
{
   class_<pyj::vrj_SimViewport_Wrapper, vrj::SimViewportPtr,
          bases<vrj::Viewport>, boost::noncopyable>
      ("SimViewport", no_init)
      .def("create", &vrj::SimViewport::create,
           "create() -> vrj.SimViewport\n"
           "Creates a SimViewport instance."
      )
      .def("updateProjections", &vrj::SimViewport::updateProjections,
           &pyj::vrj_SimViewport_Wrapper::default_updateProjections,
           "updateProjections(positionScale)\n"
           "Updates the projections.\n\n"
           "Arguments:\n"
           "positionScale -- Floating-point scale value for converting\n"
           "                 from Juggler units (meters) to the display\n"
           "                 units."
      )
      .def("getDrawSimInterface", &vrj::SimViewport::getDrawSimInterface)
      .staticmethod("create")
   ;
}
