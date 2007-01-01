// PyJuggler is (C) Copyright 2002-2007 by Patrick Hartling
// Distributed under the GNU Lesser General Public License 2.1.  (See
// accompanying file COPYING.txt or http://www.gnu.org/copyleft/lesser.txt)

// Includes ====================================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <gadget/Type/DigitalProxy.h>

// Using =======================================================================
using namespace boost::python;

// Declarations ================================================================
namespace pyj
{

struct gadget_DigitalProxy_Wrapper
   : gadget::DigitalProxy
   , wrapper<gadget::DigitalProxy>
{
   gadget_DigitalProxy_Wrapper(const gadget::DigitalProxy& p0)
      : gadget::DigitalProxy(p0)
   {
      /* Do nothing. */ ;
   }

   gadget_DigitalProxy_Wrapper()
      : gadget::DigitalProxy()
   {
      /* Do nothing. */ ;
   }

   virtual ~gadget_DigitalProxy_Wrapper()
   {
      /* Do nothing. */ ;
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
            gadget::DigitalProxy::updateData();
         }
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }
   }

   void default_updateData()
   {
      gadget::DigitalProxy::updateData();
   }

   vpr::Interval getTimeStamp() const
   {
      try
      {
         if ( override getTimeStamp = this->get_override("getTimeStamp") )
         {
            return getTimeStamp();
         }
         else
         {
            return gadget::DigitalProxy::getTimeStamp();
         }
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }

      return vpr::Interval();
   }

   vpr::Interval default_getTimeStamp() const
   {
      return gadget::DigitalProxy::getTimeStamp();
   }

   bool config(jccl::ConfigElementPtr p0)
   {
      try
      {
         if ( override config = this->get_override("config") )
         {
            return config(p0);
         }
         else
         {
            return gadget::DigitalProxy::config(p0);
         }
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }

      return false;
   }

   bool default_config(jccl::ConfigElementPtr p0)
   {
      return gadget::DigitalProxy::config(p0);
   }

   void set(const std::string& p0, gadget::Digital* p1)
   {
      try
      {
         if ( override set = this->get_override("set") )
         {
            set(boost::ref(p0), ptr(p1));
         }
         else
         {
            gadget::DigitalProxy::set(p0, p1);
         }
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }
   }

   void default_set(const std::string& p0, gadget::Digital* p1)
   {
      gadget::DigitalProxy::set(p0, p1);
   }

   bool refresh()
   {
      try
      {
         if ( override refresh = this->get_override("refresh") )
         {
            return refresh();
         }
         else
         {
            return gadget::DigitalProxy::refresh();
         }
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }

      return false;
   }

   bool default_refresh()
   {
      return gadget::DigitalProxy::refresh();
   }

   std::string getDeviceName() const
   {
      try
      {
         if ( override getDeviceName = this->get_override("getDeviceName") )
         {
            return getDeviceName();
         }
         else
         {
            return gadget::DigitalProxy::getDeviceName();
         }
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }

      return std::string("UNKNOWN");
   }

   std::string default_getDeviceName() const
   {
      return gadget::DigitalProxy::getDeviceName();
   }

   bool isStupefied() const
   {
      try
      {
         if ( override isStupefied = this->get_override("isStupefied") )
         {
            return isStupefied();
         }
         return gadget::DigitalProxy::isStupefied();
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }

      return false;
   }

   bool default_isStupefied() const
   {
      return gadget::DigitalProxy::isStupefied();
   }
};

}// namespace 


// Module ======================================================================
void _Export_DigitalProxy()
{
   class_<pyj::gadget_DigitalProxy_Wrapper>("DigitalProxy",
       "A proxy class to digital devices used by the Input Manager.\n\n"
       "A digital proxy always points to a digital device and a unit\n"
       "number within that device.  The Input Manager can therefore keep\n"
       "an array of these around and treat them as digital devices that\n"
       "only return a single sub-device's amount of data (one int)."
       ,
       init<>()
      )
      .def(init<const gadget::DigitalProxy&>())
      .def("updateData", &gadget::DigitalProxy::updateData,
           &pyj::gadget_DigitalProxy_Wrapper::default_updateData,
           "updateData()\n"
           "Updates the cached data copy from the device."
      )
      .def("updateDataIfNeeded", &gadget::Proxy::updateDataIfNeeded,
           "updateDataIfNeeded()\n"
      )
      .def("resetData", &gadget::Proxy::resetData,
           "resetData()\n"
      )
      .def("getTimeStamp", &gadget::DigitalProxy::getTimeStamp,
          &pyj::gadget_DigitalProxy_Wrapper::default_getTimeStamp,
          "getTimeStamp() -> vpr.Interval object\n"
          "Returns the time of the last update."
      )
      .def("config", &gadget::DigitalProxy::config,
           &pyj::gadget_DigitalProxy_Wrapper::default_config,
           "config(element) -> Boolean\n"
           "Configures this proxy using the given jccl.ConfigElement\n"
           "instance."
      )
      .def("set", &gadget::DigitalProxy::set,
           &pyj::gadget_DigitalProxy_Wrapper::default_set,
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
      .def("refresh", &gadget::DigitalProxy::refresh,
           &pyj::gadget_DigitalProxy_Wrapper::default_refresh,
           "refresh() -> Boolean\n"
           "Refreshes the proxy.  This attempts to lookup the device that\n"
           "we are proxying.  If the lookup fails, then we become\n"
           "stupefied.  If not, then the proxy is pointed at this\n"
           "potentially new device."
      )
      .def("getDeviceName", &gadget::DigitalProxy::getDeviceName,
           &pyj::gadget_DigitalProxy_Wrapper::default_getDeviceName,
           "getDeviceName() -> string object\n"
           "Gets the name of the device that we are proxying."
      )
      .def("isStupefied", &gadget::Proxy::isStupefied,
           &pyj::gadget_DigitalProxy_Wrapper::default_isStupefied,
           "isStupefied() -> Boolean\n"
           "Is the proxy currently stupefied?\n"
           "If the device we are proxying does not exist, then this will\n"
           "return True."
      )
      .def("getData", &gadget::DigitalProxy::getData,
           "getData() -> float\n"
           "Gets the current digital data value."
      )
      .def("getDigitalData", &gadget::DigitalProxy::getDigitalData,
           return_internal_reference<1>()
      )
      .def("getDigitalPtr", &gadget::DigitalProxy::getDigitalPtr,
           return_internal_reference<1>(),
           "getDigitalPtr() -> gadget.Digital object\n"
      )
      .def("getUnit", &gadget::DigitalProxy::getUnit,
           "getUnit() -> int\n"
           "Returns the unit index into the digital device from which this\n"
           "proxy is reading data."
      )
      .def("getElementType", &gadget::DigitalProxy::getElementType,
           "getElementType() -> string object"
      )
      .def("getName", &gadget::Proxy::getName,
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
      .staticmethod("getElementType")
   ;
}
