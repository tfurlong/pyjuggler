// PyJuggler is (C) Copyright 2002-2007 by Patrick Hartling
// Distributed under the GNU Lesser General Public License 2.1.  (See
// accompanying file COPYING.txt or http://www.gnu.org/copyleft/lesser.txt)

// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <vpr/IO/ObjectReader.h>
#include <vpr/IO/ObjectWriter.h>
#include <gadget/Type/KeyboardMouse/Event.h>

// Using =======================================================================
using namespace boost::python;

// Declarations ================================================================
namespace pyj
{

struct gadget_Event_Wrapper : gadget::Event, wrapper<gadget::Event>
{
   gadget_Event_Wrapper(const gadget::Event& p0)
      : gadget::Event(p0)
   {
      /* Do nothing. */ ;
   }

   virtual ~gadget_Event_Wrapper()
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
            gadget::Event::writeObject(p0);
         }
      }
      catch (error_already_set)
      {
         PyErr_Print();
         throw vpr::IOException(
            "Python exception caught by pyj::gadget_Event_Wrapper::writeObject()",
            VPR_LOCATION
         );
      }
   }

   void default_writeObject(vpr::ObjectWriter* p0)
   {
      gadget::Event::writeObject(p0);
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
            gadget::Event::readObject(p0);
         }
      }
      catch (error_already_set)
      {
         PyErr_Print();
         throw vpr::IOException(
            "Python exception caught by pyj::gadget_Event_Wrapper::readObject()",
            VPR_LOCATION
         );
      }
   }

   void default_readObject(vpr::ObjectReader* p0)
   {
      gadget::Event::readObject(p0);
   }
};

}// namespace 


// Module ======================================================================
void _Export_Event()
{
   scope* gadget_Event_scope = new scope(
   class_<pyj::gadget_Event_Wrapper>("Event",
       "Base event type that an event source may generate.  This class\n"
       "cannot be used directly.  Subclasses must be used instead."
       ,
       init<const gadget::Event&>()
      )
      .def("writeObject", &gadget::Event::writeObject,
           &pyj::gadget_Event_Wrapper::default_writeObject,
           "writeObject(writer)\n"
           "Serializes this object."
      )
      .def("readObject", &gadget::Event::readObject,
           &pyj::gadget_Event_Wrapper::default_readObject,
           "readObject(reader)\n"
           "De-serializes this object."
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
           "event type after creating this event using the EventFactory."
           "Arguments:\n"
           "type -- A gadget.EventType object or a subclass thereof."
      )
      .def("time", &gadget::Event::time,
           return_value_policy<copy_const_reference>(),
           "time() -> int\n"
           "Returns the time at which the event occurred."
      )
   );

   register_ptr_to_python< boost::shared_ptr<gadget::Event> >();
   delete gadget_Event_scope;
}
