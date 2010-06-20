// PyJuggler is (C) Copyright 2002-2010 by Patrick Hartling
// Distributed under the GNU Lesser General Public License 2.1.  (See
// accompanying file COPYING.txt or http://www.gnu.org/copyleft/lesser.txt)

// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <vpr/IO/ObjectReader.h>
#include <vpr/IO/ObjectWriter.h>
#include <gadget/Type/KeyboardMouse/MouseEvent.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
void _Export_MouseEvent()
{
   scope* gadget_MouseEvent_scope = new scope(
   class_<gadget::MouseEvent, bases<gadget::Event> >
      ("MouseEvent",
       "Mouse event class.  This captures the state of the mouse when any\n"
       "mouse event occurs.  This includes button presses, button\n"
       "releases, and mouse motion."
       ,
       no_init
      )
      .def("getButton", &gadget::MouseEvent::getButton,
           "getButton() -- gadget.Keys value\n"
      )
      .def("getX", &gadget::MouseEvent::getX,
           "getX() -> int\n"
           "Returns the X coordinate of the mouse pointer relative to the\n"
           "window."
      )
      .def("getY", &gadget::MouseEvent::getY,
           "getY() -> int\n"
           "Returns the Y coordinate of the mouse pointer relative to the\n"
           "window."
      )
      .def("getGlobalX", &gadget::MouseEvent::getGlobalX,
           "getGlobalX() -> int\n"
           "Returns the X coordinate of the mouse pointer relative to the\n"
           "root window (i.e., the desktop)."
      )
      .def("getGlobalY", &gadget::MouseEvent::getGlobalY,
           "getGlobalY() -> int\n"
           "Returns the Y coordinate of the mouse pointer relative to the\n"
           "root window (i.e., the desktop)."
      )
      .def("getState", &gadget::MouseEvent::getState,
           "getState() -> int\n"
           "Returns the state of the mouse buttons and keyboard modifier\n"
           "keys (CTRL, ALT, and SHIFT)."
      )
      .def("type", &gadget::Event::type,
           "type() -> gadget.EventType object\n"
           "Returns the type of this event.  This can be used for dynamic\n"
           "casting to more specific event types."
      )
      .def("setType", &gadget::Event::setType,
           "setType(type)\n"
           "Sets the type of this event.  This is needed because, while\n"
           "using an object reader to de-serialize a gadget.Event object,\n"
           "we cannot set the type during construction.  We must set the\n"
           "event type after creating this event using the EventFactory.\n"
           "Arguments:\n"
           "type -- A gadget.EventType object or a subclass thereof."
      )
      .def("time", &gadget::Event::time,
           "time() -> int\n"
           "Returns the time at which the event occurred."
      )
   );

   register_ptr_to_python< boost::shared_ptr<gadget::MouseEvent> >();
   delete gadget_MouseEvent_scope;
}
