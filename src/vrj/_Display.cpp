// PyJuggler is (C) Copyright 2002-2011 by Patrick Hartling
// Distributed under the GNU Lesser General Public License 2.1.  (See
// accompanying file COPYING.txt or http://www.gnu.org/copyleft/lesser.txt)

// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <jccl/Config/ConfigElement.h>
#include <vrj/Display/Display.h>
#include <vrj/Display/Viewport.h>

// Using =======================================================================
using namespace boost::python;

// Declarations ================================================================
namespace pyj
{

struct vrj_Display_Wrapper : vrj::Display, wrapper<vrj::Display>
{
   virtual ~vrj_Display_Wrapper()
   {
      /* Do nothing. */ ;
   }
};

static tuple vrj_Display_getOriginAndSize_wrapper(vrj::Display* disp)
{
   int xo, yo, xs, ys;
   disp->getOriginAndSize(xo, yo, xs, ys);
   return make_tuple(xo, yo, xs, ys);
}

}// namespace 


// Module ======================================================================
void _Export_Display()
{
   class_<pyj::vrj_Display_Wrapper, vrj::DisplayPtr, boost::noncopyable>(
       "Display",
       "Container class for viewports and window information.  This stores\n"
       "the size and location of the window and the viewports contained\n"
       "within."
       ,
       no_init
      )
      .def("create", &vrj::Display::create,
           "vrj.Display.create() -> vrj.DisplayPtr\n"
           "Creates a new vrj::Display object and wraps in a vrj::DisplayPtr."
      )
      .def("isActive", &vrj::Display::isActive,
           "isActive() -> Boolean\n"
           "Determines whether this display window is active."
      )
      .def("getName", &vrj::Display::getName,
           return_value_policy<copy_const_reference>(),
           "getName() -> string object\n"
           "Gets the name of this display window."
      )
      .def("getOriginAndSize", pyj::vrj_Display_getOriginAndSize_wrapper,
           "getOriginAndSize() -> (int, int, int, int)\n"
           "Returns the current origin and size of this display widnow as\n"
           "a tuple of four integers (x origin, y origin, width, height)."
      )
      .def("getPipe", &vrj::Display::getPipe,
           "getPipe() -> int\n"
           "Gets the graphics piope for this display window."
      )
      .def("getConfigElement", &vrj::Display::getConfigElement,
           "getConfigElement() -> jccl.ConfigElement object\n"
           "Gets the config element that configured this display window."
      )
      .def("getNumViewports", &vrj::Display::getNumViewports,
           "getNumViewports() -> int\n"
           "Gets the number of viewports contained within this window."
      )
      .def("getViewport", &vrj::Display::getViewport,
           "getViewport(vpNum) -> vrj.Viewport object\n"
           "Returns the requested viewprot from this display window.\n\n"
           "Pre-conditions:\n"
           "vpNum < self.getNumViewports()\n\n"
           "Arguments:\n"
           "vpNum -- The integer identifier of the requested viewport."
      )
//      .def(self_ns::str(self))
      .staticmethod("create")
   ;
}
