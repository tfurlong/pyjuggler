// PyJuggler is (C) Copyright 2002-2010 by Patrick Hartling
// Distributed under the GNU Lesser General Public License 2.1.  (See
// accompanying file COPYING.txt or http://www.gnu.org/copyleft/lesser.txt)

// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <vpr/IO/ObjectReader.h>
#include <vpr/IO/ObjectWriter.h>
#include <gadget/Devices/KeyboardMouseDevice/InputArea.h>
#include <gadget/Type/KeyboardMouse/KeyEvent.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
void _Export_KeyEvent()
{
   scope* gadget_KeyEvent_scope = new scope(
   class_<gadget::KeyEvent, bases<gadget::Event> >
      ("KeyEvent",
       "Key press or release event class.",
       no_init
      )
      .def("getKey", &gadget::KeyEvent::getKey,
           "getKey() -> gadget.Key object\n"
           "Gets the key that was pressed while generating this event."
      )
      .def("getModifierMask", &gadget::KeyEvent::getModifierMask,
           "getModifierMask() -> int\n"
           "Returns the modifier mask for this event.  This tells which\n"
           "modifier keys (if any) were pressed at the same time as the\n"
           "key that was pressed or released.  The mask is the bitwise OR\n"
           "of values in the enumeration gadget.ModifierMask."
      )
      .def("getKeyChar", &gadget::KeyEvent::getKeyChar,
           "getKeyChar() -> character\n"
           "Returns the ASCII character corresponding to the key that was\n"
           "pressed."
      )
      .def("getKeyUnicode", &gadget::KeyEvent::getKeyUnicode,
           "getKeyUnicode() -> Unicode character\n"
           "Returns the Unicode character corresponding to the key that was\n"
           "pressed."
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

   register_ptr_to_python< boost::shared_ptr<gadget::KeyEvent> >();
   delete gadget_KeyEvent_scope;
}
