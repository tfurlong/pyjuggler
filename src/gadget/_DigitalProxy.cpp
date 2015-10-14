// PyJuggler is (C) Copyright 2002-2012 by Patrick Hartling
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

   const vpr::Interval& getTimeStamp() const
   {
      try
      {
         if ( override getTimeStamp = this->get_override("getTimeStamp") )
         {
            return getTimeStamp();
         }
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }

      return gadget::DigitalProxy::getTimeStamp();
   }

   const vpr::Interval& default_getTimeStamp() const
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

   void set(const std::string& p0, const gadget::DigitalPtr& p1,
            const boost::optional<int>& p2 = boost::optional<int>())
   {
      try
      {
         if ( override set = this->get_override("set") )
         {
            set(boost::ref(p0), boost::ref(p1), boost::ref(p2));
         }
         else
         {
            gadget::DigitalProxy::set(p0, p1, p2);
         }
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }
   }

   void default_set(const std::string& p0, const gadget::DigitalPtr& p1,
                    const boost::optional<int>& p2 = boost::optional<int>())
   {
      gadget::DigitalProxy::set(p0, p1, p2);
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

   const std::string& getDeviceName() const
   {
      try
      {
         if ( override getDeviceName = this->get_override("getDeviceName") )
         {
            return getDeviceName();
         }
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }

      return gadget::DigitalProxy::getDeviceName();
   }

   const std::string& default_getDeviceName() const
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

   virtual gadget::DigitalState::State getData() const
   {
      try
      {
         if ( override getData = this->get_override("getData") )
         {
            return getData();
         }
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }

      return gadget::DigitalProxy::getData();
   }

   // const gadget::DigitalState::State default_getData() const
   // {
   //    return gadget::DigitalProxy::getData();
   // }
};

}// namespace


// Module ======================================================================
void _Export_DigitalProxy()
{
   class_<pyj::gadget_DigitalProxy_Wrapper
        , gadget::DigitalProxyPtr
        , boost::noncopyable
       >
      (
       "DigitalProxy",
       "A proxy class to digital devices used by the Input Manager.\n\n"
       "A digital proxy always points to a digital device and a unit\n"
       "number within that device.  The Input Manager can therefore keep\n"
       "an array of these around and treat them as digital devices that\n"
       "only return a single sub-device's amount of data (one int)."
       ,
       no_init
      )
      .def("create", &gadget::DigitalProxy::create)
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
           return_value_policy<copy_const_reference>(),
           "getTimeStamp() -> vpr.Interval object\n"
           "Returns the time of the last update."
      )
      .def("config", &gadget::DigitalProxy::config,
           &pyj::gadget_DigitalProxy_Wrapper::default_config,
           "config(element) -> Boolean\n"
           "Configures this proxy using the given jccl.ConfigElement\n"
           "instance."
      )
      // TODO: Expose boost::optional to Python...
      /*
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
           "devPtr  -- Pointer to the device.  For gadget.DigitalProxy,\n"
           "           this points to an instance of gadget.Digital.\n"
           "unitNum -- "
      )
      */
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
           return_value_policy<copy_const_reference>(),
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
           &pyj::gadget_DigitalProxy_Wrapper::getData,
           "getData() -> gadget.DigitalState.State\n"
           "Gets the current digital data value."
      )
      .def("getTypedInputDevice", &gadget::DigitalProxy::getTypedInputDevice,
           "getTypedInputDevice() -> gadget.Digital object\n"
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
