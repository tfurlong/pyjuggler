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
#include <vpr/IO/ObjectReader.h>
#include <vpr/IO/ObjectWriter.h>
#include <gadget/Type/KeyboardMouse/KeyEvent.h>

// Using =======================================================================
using namespace boost::python;

// Declarations ================================================================
namespace pyj
{

struct gadget_KeyEvent_Wrapper : gadget::KeyEvent, wrapper<gadget::KeyEvent>
{
   gadget_KeyEvent_Wrapper(const gadget::KeyEvent& p0)
      : gadget::KeyEvent(p0)
   {
      /* Do nothing. */ ;
   }

   gadget_KeyEvent_Wrapper(const gadget::EventType& p0, const gadget::Keys& p1,
                           const int& p2, const long unsigned int& p3)
      : gadget::KeyEvent(p0, p1, p2, p3)
   {
      /* Do nothing. */ ;
   }

   gadget_KeyEvent_Wrapper(const gadget::EventType& p0, const gadget::Keys& p1,
                           const int& p2, const long unsigned int& p3, char p4)
      : gadget::KeyEvent(p0, p1, p2, p3, p4)
   {
      /* Do nothing. */ ;
   }

   gadget_KeyEvent_Wrapper()
       : gadget::KeyEvent()
   {
      /* Do nothing. */ ;
   }

   virtual ~gadget_KeyEvent_Wrapper() throw ()
   {
      /* Do nothing. */ ;
   }

   void writeObject(vpr::ObjectWriter* p0) throw (vpr::IOException)
   {
      try
      {
         if ( override writeObject = this->get_override("writeObject") )
         {
            writeObject(p0);
         }
         else
         {
            gadget::KeyEvent::writeObject(p0);
         }
      }
      catch (error_already_set)
      {
         PyErr_Print();
         throw vpr::IOException(
            "Python exception caught by pyj::gadget_KeyEvent_Wrapper::writeObject()",
            VPR_LOCATION
         );
      }
   }

   void default_writeObject(vpr::ObjectWriter* p0) throw (vpr::IOException)
   {
      gadget::KeyEvent::writeObject(p0);
   }

   void readObject(vpr::ObjectReader* p0) throw (vpr::IOException)
   {
      try
      {
         if ( override readObject = this->get_override("readObject") )
         {
            readObject(p0);
         }
         else
         {
            gadget::KeyEvent::readObject(p0);
         }
      }
      catch (error_already_set)
      {
         PyErr_Print();
         throw vpr::IOException(
            "Python exception caught by pyj::gadget_KeyEvent_Wrapper::readObject()",
            VPR_LOCATION
         );
      }
   }

   void default_readObject(vpr::ObjectReader* p0) throw (vpr::IOException)
   {
      gadget::KeyEvent::readObject(p0);
   }
};

}// namespace 


// Module ======================================================================
void _Export_KeyEvent()
{
   scope* gadget_KeyEvent_scope = new scope(
   class_<pyj::gadget_KeyEvent_Wrapper, bases<gadget::Event> >
      ("KeyEvent",
       "Key press or release event class.",
       init<>(
          "__init__()\n"
          "Default constructor needed in order to use the templated\n"
          "EventFactory without modification.\n\n"
          "__init__(type, key, mask, time, asciiKey = 0)\n"
          "Initializes data members.\n"
          "Arguments:\n"
          "type     -- The type of this event (either key press or key\n"
          "            release).\n"
          "key      -- The platform-specific value of the key that was\n"
          "            pressed or released.\n"
          "mask     -- The mask of modifiers pressed in addition to key.\n"
          "            This should be constructed using the bitwise OR of\n"
          "            gadget.ModifierMask values.\n"
          "time     -- The time at which this event occurred.  This should\n"
          "            be as accurate as possible, preferrably acquired\n"
          "            from the operating system or windowing event system\n"
          "            event data structure.  The time at which the event\n"
          "            was processed is not an acceptable value.\n"
          "asciiKey -- The ASCII value of the key associated with this\n"
          "            event.  This paramter is optional, and it defaults\n"
          "            to 0 if not specified."
       )
      )
      .def(init<const gadget::KeyEvent&>())
      .def(init<const gadget::EventType&, const gadget::Keys&, const int&,
                const long unsigned int&, optional<char> >())
      .def("writeObject", &gadget::KeyEvent::writeObject,
           &pyj::gadget_KeyEvent_Wrapper::default_writeObject,
           "writeObject(writer)\n"
           "Serializes this event using the given vpr.ObjectWriter."
      )
      .def("readObject", &gadget::KeyEvent::readObject,
           &pyj::gadget_KeyEvent_Wrapper::default_readObject,
           "readObject(reader)\n"
           "De-serializes this event using the given vpr.ObjectReader."
      )
      .def("getKey", &gadget::KeyEvent::getKey,
           return_value_policy<copy_const_reference>(),
           "getKey() -> gadget.Key object\n"
           "Gets the key that was pressed while generating this event."
      )
      .def("getModifierMask", &gadget::KeyEvent::getModifierMask,
           return_value_policy<copy_const_reference>(),
           "getModifierMask() -> int\n"
           "Returns the modifier mask for this event.  This tells which\n"
           "modifier keys (if any) were pressed at the same time as the\n"
           "key that was pressed or released.  The mask is the bitwise OR\n"
           "of values in the enumeration gadget.ModifierMask."
      )
      .def("getKeyChar", &gadget::KeyEvent::getKeyChar,
           return_value_policy<copy_const_reference>(),
           "getKeyChar() -> character\n"
           "Returns the ASCII character corresponding to the key that was\n"
           "pressed."
      )
      .def("type", &gadget::Event::type,
           return_value_policy<copy_const_reference>(),
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
           return_value_policy<copy_const_reference>(),
           "time() -> int\n"
           "Returns the time at which the event occurred."
      )
   );

   register_ptr_to_python< boost::shared_ptr<gadget::KeyEvent> >();
   delete gadget_KeyEvent_scope;
}
