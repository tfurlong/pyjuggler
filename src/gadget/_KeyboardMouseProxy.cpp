// PyJuggler is (C) Copyright 2002-2007 by Patrick Hartling
// Distributed under the GNU Lesser General Public License 2.1.  (See
// accompanying file COPYING.txt or http://www.gnu.org/copyleft/lesser.txt)

// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <gadget/Type/KeyboardMouseProxy.h>

// Using =======================================================================
using namespace boost::python;

// Declarations ================================================================
namespace pyj
{

struct gadget_KeyboardMouseProxy_Wrapper
   : gadget::KeyboardMouseProxy
   , wrapper<gadget::KeyboardMouseProxy>
{
   gadget_KeyboardMouseProxy_Wrapper(const gadget::KeyboardMouseProxy& p0)
      : gadget::KeyboardMouseProxy(p0)
   {
      /* Do nothing. */ ;
   }

   gadget_KeyboardMouseProxy_Wrapper()
      : gadget::KeyboardMouseProxy()
   {
      /* Do nothing. */ ;
   }

   virtual ~gadget_KeyboardMouseProxy_Wrapper()
   {
      /* Do nothing. */ ;
   }

   vpr::Interval getTimeStamp() const
   {
      try
      {
         if ( override getTimeStamp = this->get_override("getTimeStamp") )
         {
            return getTimeStamp();
         }
         return gadget::KeyboardMouseProxy::getTimeStamp();
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }

      return vpr::Interval();
   }

   vpr::Interval default_getTimeStamp() const
   {
      return gadget::KeyboardMouseProxy::getTimeStamp();
   }

   bool config(jccl::ConfigElementPtr p0)
   {
      try
      {
         if ( override config = this->get_override("config") )
         {
            return config(p0);
         }
         return gadget::KeyboardMouseProxy::config(p0);
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }

      return false;
   }

   bool default_config(jccl::ConfigElementPtr p0)
   {
      return gadget::KeyboardMouseProxy::config(p0);
   }

   void set(const std::string& p0, gadget::KeyboardMousePtr p1)
   {
      try
      {
         if ( override set = this->get_override("set") )
         {
            set(boost::ref(p0), p1);
         }
         else
         {
            gadget::KeyboardMouseProxy::set(p0, p1);
         }
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }
   }

   void default_set(const std::string& p0, gadget::KeyboardMousePtr p1)
   {
      gadget::TypedProxy<gadget::KeyboardMouse>::set(p0, p1);
   }

   bool refresh()
   {
      try
      {
         if ( override refresh = this->get_override("refresh") )
         {
            return refresh();
         }
         return gadget::KeyboardMouseProxy::refresh();
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }

      return false;
   }

   bool default_refresh()
   {
      return gadget::TypedProxy<gadget::KeyboardMouse>::refresh();
   }

   std::string getDeviceName() const
   {
      try
      {
         if ( override getDeviceName = this->get_override("getDeviceName") )
         {
            return getDeviceName();
         }
         return gadget::KeyboardMouseProxy::getDeviceName();
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }

      return std::string("UNKNOWN");
   }

   std::string default_getDeviceName() const
   {
      return gadget::TypedProxy<gadget::KeyboardMouse>::getDeviceName();
   }

   void updateData()
   {
      try
      {
         if ( override updateData = this->get_override("updateData") )
         {
            updateData();
         }
         else
         {
            gadget::Proxy::updateData();
         }
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }
   }

   void default_updateData()
   {
      gadget::Proxy::updateData();
   }

   bool isStupefied() const
   {
      try
      {
         if ( override isStupefied = this->get_override("isStupefied") )
         {
            return isStupefied();
         }
         return gadget::Proxy::isStupefied();
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }

      return false;
   }

   bool default_isStupefied() const
   {
      return gadget::Proxy::isStupefied();
   }
};

}// namespace 


// Module ======================================================================
void _Export_KeyboardMouseProxy()
{
   class_<pyj::gadget_KeyboardMouseProxy_Wrapper, gadget::KeyboardMouseProxyPtr>(
       "KeyboardMouseProxy",
       "A proxy class to keyboard/mouse devices used by the Input Manager.\n\n"
       "A keyboard/mouse proxy always points to a keyboard/mouse device\n"
       "and a unit number within that device.  The Input Manager can\n"
       "therefore keep an array of these around and treat them as\n"
       "keyboard/mouse devices that only return a single sub-device's\n"
       "amount of data (an event queue and individual keys)."
       ,
       no_init
      )
      .def("create", &gadget::KeyboardMouseProxy::create)
      .def("getTimeStamp", &gadget::KeyboardMouseProxy::getTimeStamp,
           &pyj::gadget_KeyboardMouseProxy_Wrapper::default_getTimeStamp,
           "getTimeStamp() -> vpr.Interval object\n"
           "Returns the time of the last update."
      )
      .def("config", &gadget::KeyboardMouseProxy::config,
           &pyj::gadget_KeyboardMouseProxy_Wrapper::default_config,
           "config(element) -> Boolean\n"
           "Configures this proxy using the given jccl.ConfigElement\n"
           "instance."
      )
      .def("set", &gadget::KeyboardMouseProxy::set,
           &pyj::gadget_KeyboardMouseProxy_Wrapper::default_set,
           "set(devName, devPtr)\n"
           "Sets the proxy to point to the given type-specific device.\n"
           "Pre-condition:\n"
           "devPtr must be a valid device of type gadget.Digital\n"
           "Post-condition:\n"
           "The proxy now references the given device.  The device name we\n"
           "are proxying is set to devPtr.getInstanceName()."
           "Arguments:\n"
           "devName -- The name of the device at which we are pointing.\n"
           "devPtr  -- Pointer to the device.  For gadget.Digital,\n"
           "           this points to an instance of gadget.Digital."
      )
      .def("refresh", &gadget::KeyboardMouseProxy::refresh,
           &pyj::gadget_KeyboardMouseProxy_Wrapper::default_refresh,
           "refresh() -> Boolean\n"
           "Refreshes the proxy.  This attempts to lookup the device that\n"
           "we are proxying.  If the lookup fails, then we become\n"
           "stupefied.  If not, then the proxy is pointed at this\n"
           "potentially new device."
      )
      .def("getDeviceName", &gadget::KeyboardMouseProxy::getDeviceName,
           &pyj::gadget_KeyboardMouseProxy_Wrapper::default_getDeviceName,
           "getDeviceName() -> string object\n"
           "Gets the name of the device that we are proxying."
      )
      .def("updateData", &gadget::Proxy::updateData,
           &pyj::gadget_KeyboardMouseProxy_Wrapper::default_updateData,
           "updateData()\n"
           "Updates the cached data copy from the device.  Copies the\n"
           "device data to local storage and transforms it if necessary."
      )
      .def("updateDataIfNeeded", &gadget::Proxy::updateDataIfNeeded,
           "updateDataIfNeeded()\n"
      )
      .def("resetData", &gadget::Proxy::resetData,
           "resetData()\n"
      )
      .def("isStupefied", &gadget::Proxy::isStupefied,
           &pyj::gadget_KeyboardMouseProxy_Wrapper::default_isStupefied,
           "isStupefied() -> Boolean\n"
           "Is the proxy currently stupefied?\n"
           "If the device we are proxying does not exist, then this will\n"
           "return True."
      )
      .def("getKeyboardMousePtr",
           &gadget::KeyboardMouseProxy::getKeyboardMousePtr,
           "getKeyboardMousePtr() -> gadget.KeyboardMouse object\n"
           "Returns the gadget.KeyboardMouse object held by this proxy."
      )
      .def("modifierOnly", &gadget::KeyboardMouseProxy::modifierOnly,
           "modifierOnly(modKey) -> Boolean\n"
           "Determines if the given modifier key is the only modifier\n"
           "pressed.\n"
           "Pre-conditions:\n"
           "The given key identifier must be one of gadget.Keys.NONE,\n"
           "gadget.Keys.KEY_ALT, gadget.Keys.KEY_CTRL, or\n"
           "gadget.Keys.KET_SHIFT.\n"
           "Arguments:\n"
           "modKey -- A gadget.Keys value that must be one of\n"
           "          gadget.Keys.NONE, gadget.Keys.KEY_ALT,\n"
           "          gadget.Keys.KEY_CTRL, or gadget.Keys.KEY_SHIFT.\n"
           "Returns:\n"
           "True is returned if the given modifier is the only modifier\n"
           "key pressed."
      )
      .def("keyPressed", &gadget::KeyboardMouseProxy::keyPressed,
           "keyPressed(keyId) -> int\n"
           "Returns the number of times the given key was pressesd during\n"
           "the last frame.  This can be used in a conditional expression\n"
           "to determine if the key was pressed at all."
           "Arguments:\n"
           "keyId -- A value from gadget.Keys identifiing the key whose\n"
           "         state will be queried.\n"
           "Returns:\n"
           "The number of times the named key was pressed since the last\n"
           "update."
      )
      .def("getEventQueue", &gadget::KeyboardMouseProxy::getEventQueue,
           "getEventQueue() -> list of gadget.Event objects\n"
           "Returns a copy of the current queue of events for the proxied\n"
           "device."
      )
      .def("getElementType", &gadget::KeyboardMouseProxy::getElementType)
      .def("getName", &gadget::Proxy::getName,
           return_value_policy<copy_const_reference>(),
           "getName() -> string object\n"
           "Gets the name of the proxy."
      )
      .def("setName", &gadget::Proxy::setName,
           "setName(name)\n"
           "Sets the name of the proxy.\n"
           "Arguments:\n"
           "name -- The name for this proxy as a string object."
      )
      .def("stupefy", &gadget::Proxy::stupefy,
           "stupefy(newState = True)\n"
           "Sets the stupefication state of this proxy.\n"
           "Keyword arguments:\n"
           "newState -- The new state of stupefication."
      )
      .staticmethod("create")
      .staticmethod("getElementType")
   ;
}
