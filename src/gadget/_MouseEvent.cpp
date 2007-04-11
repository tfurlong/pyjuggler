// PyJuggler is (C) Copyright 2002-2007 by Patrick Hartling
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

// Declarations ================================================================
namespace pyj
{

struct gadget_MouseEvent_Wrapper
   : gadget::MouseEvent
   , wrapper<gadget::MouseEvent>
{
   gadget_MouseEvent_Wrapper(const gadget::MouseEvent& p0)
      : gadget::MouseEvent(p0)
   {
      /* Do nothing. */ ;
   }

   gadget_MouseEvent_Wrapper(const gadget::EventType p0,
                             const gadget::Keys p1, const int p2,
                             const int p3, const int p4, const int p5,
                             const int p6, const long unsigned int p7)
      : gadget::MouseEvent(p0, p1, p2, p3, p4, p5, p6, p7)
   {
      /* Do nothing. */ ;
   }

   gadget_MouseEvent_Wrapper()
      : gadget::MouseEvent()
   {
      /* Do nothing. */ ;
   }

   virtual ~gadget_MouseEvent_Wrapper()
   {
      /* Do nothing. */ ;
   }

   void writeObject(vpr::ObjectWriter* p0)
   {
      try
      {
         if ( override writeObject = this->get_override("writeObject") )
         {
            writeObject(ptr(p0));
         }
         else
         {
            gadget::MouseEvent::writeObject(p0);
         }
      }
      catch (error_already_set)
      {
         PyErr_Print();
         throw vpr::IOException(
            "Python exception caught by pyj::gadget_MouseEvent_Wrapper::writeObject()",
            VPR_LOCATION
         );
      }
   }

   void default_writeObject(vpr::ObjectWriter* p0)
   {
      gadget::MouseEvent::writeObject(p0);
   }

   void readObject(vpr::ObjectReader* p0)
   {
      try
      {
         if ( override readObject = this->get_override("readObject") )
         {
            readObject(ptr(p0));
         }
         else
         {
            gadget::MouseEvent::readObject(p0);
         }
      }
      catch (error_already_set)
      {
         PyErr_Print();
         throw vpr::IOException(
            "Python exception caught by pyj::gadget_MouseEvent_Wrapper::readObject()",
            VPR_LOCATION
         );
      }
   }

   void default_readObject(vpr::ObjectReader* p0)
   {
      gadget::MouseEvent::readObject(p0);
   }
};

}// namespace 


// Module ======================================================================
void _Export_MouseEvent()
{
   scope* gadget_MouseEvent_scope = new scope(
   class_<pyj::gadget_MouseEvent_Wrapper, bases<gadget::Event> >
      ("MouseEvent",
       "Mouse event class.  This captures the state of the mouse when any\n"
       "mouse event occurs.  This includes button presses, button\n"
       "releases, and mouse motion."
       ,
       init<>(
          "__init__()\n"
          "Default constructor needed in order to use the templated\n"
          "EventFactory without modification.\n\n"
          "__init__(type, button, x, y, globalX, globalY, state, time)\n"
          "Initializes data members.\n"
          "Arguments:\n"
          "type    -- The type of this event (a mouse button press, a mouse\n"
          "           a mouse button release, or a mouse move).\n"
          "button  -- The button that generated the event.\n"
          "x       -- The X coordinate of the mouse within the window.\n"
          "y       -- The Y coordinate of the mouse within the window.\n"
          "globalX -- The X coordinate of the mouse relative to the root\n"
          "           window (i.e., the desktop).\n"
          "globalY -- The Y coordinate of the mouse relative to the root\n"
          "           window (i.e., the desktop).\n"
          "state   -- The mask of mouse buttons and any modifiers being\n"
          "           pressed.  This should be constructed using the\n"
          "           bitwise OR of gadget.ModifierMask and\n"
          "           gadget.ButtonMask values.\n"
          "time    -- The time at which this event occurred.  This should\n"
          "           be as accurate as possible, preferrably acquired\n"
          "           from the operating system or windowing event system\n"
          "           event data structure.  The time at which the event\n"
          "           was processed is not an acceptable value."
       )
      )
      .def(init<const gadget::MouseEvent&>())
      .def(init<const gadget::EventType, const gadget::Keys, const int,
                const int, const int, const int, const int,
                const long unsigned int>())
      .def("writeObject", &gadget::MouseEvent::writeObject,
           &pyj::gadget_MouseEvent_Wrapper::default_writeObject,
           "writeObject(writer)\n"
           "Serializes this event using the given vpr.ObjectWriter."
      )
      .def("readObject", &gadget::MouseEvent::readObject,
           &pyj::gadget_MouseEvent_Wrapper::default_readObject,
           "readObject(reader)\n"
           "De-serializes this event using the given vpr.ObjectReader."
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
