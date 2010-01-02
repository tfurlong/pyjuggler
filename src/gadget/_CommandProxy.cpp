// PyJuggler is (C) Copyright 2002-2010 by Patrick Hartling
// Distributed under the GNU Lesser General Public License 2.1.  (See
// accompanying file COPYING.txt or http://www.gnu.org/copyleft/lesser.txt)

// Includes ====================================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <gadget/Type/CommandProxy.h>

// Using =======================================================================
using namespace boost::python;

// Declarations ================================================================
namespace pyj
{

struct gadget_CommandProxy_Wrapper
   : gadget::CommandProxy
   , wrapper<gadget::CommandProxy>
{
   gadget_CommandProxy_Wrapper(const gadget::CommandProxy& p0)
      : gadget::CommandProxy(p0)
   {
      /* Do nothing. */ ;
   }

   gadget_CommandProxy_Wrapper()
      : gadget::CommandProxy()
   {
      /* Do nothing. */ ;
   }

   virtual ~gadget_CommandProxy_Wrapper()
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
            gadget::CommandProxy::updateData();
         }
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }
   }

   void default_updateData()
   {
      gadget::CommandProxy::updateData();
   }

   vpr::Interval getTimeStamp() const
   {
      try
      {
         if ( override getTimeStamp = this->get_override("getTimeStamp") )
         {
            return getTimeStamp();
         }
         return gadget::CommandProxy::getTimeStamp();
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }

      return vpr::Interval();
   }

   vpr::Interval default_getTimeStamp() const
   {
      return gadget::CommandProxy::getTimeStamp();
   }

   bool config(jccl::ConfigElementPtr p0)
   {
      try
      {
         if ( override config = this->get_override("config") )
         {
            return config(p0);
         }
         return gadget::CommandProxy::config(p0);
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }

      return false;
   }

   bool default_config(jccl::ConfigElementPtr p0)
   {
      return gadget::CommandProxy::config(p0);
   }

   void set(const std::string& p0, gadget::CommandPtr p1)
   {
      try
      {
         if ( override set = this->get_override("set") )
         {
            set(boost::ref(p0), p1);
         }
         else
         {
            gadget::CommandProxy::set(p0, p1);
         }
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }
   }

   void default_set(const std::string& p0, gadget::CommandPtr p1)
   {
      gadget::CommandProxy::set(p0, p1);
   }

   bool refresh()
   {
      try
      {
         if ( override refresh = this->get_override("refresh") )
         {
            return refresh();
         }
         return gadget::CommandProxy::refresh();
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }

      return false;
   }

   bool default_refresh()
   {
      return gadget::CommandProxy::refresh();
   }

   std::string getDeviceName() const
   {
      try
      {
         if ( override getDeviceName = this->get_override("getDeviceName") )
         {
            return getDeviceName();
         }
         return gadget::CommandProxy::getDeviceName();
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }

      return std::string("UNKNOWN");
   }

   std::string default_getDeviceName() const
   {
      return gadget::CommandProxy::getDeviceName();
   }

   bool isStupefied() const
   {
      try
      {
         if ( override isStupefied = this->get_override("isStupefied") )
         {
            return isStupefied();
         }
         return gadget::CommandProxy::isStupefied();
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }

      return false;
   }

   bool default_isStupefied() const
   {
      return gadget::CommandProxy::isStupefied();
   }
};

}// namespace 


// Module ======================================================================
void _Export_CommandProxy()
{
   class_<pyj::gadget_CommandProxy_Wrapper, gadget::CommandProxyPtr>(
       "CommandProxy",
       "A proxy class to command-oriented devices used by the Input\n"
       "Manager.\n\n"
       "A command proxy always points to a command-oriented device and a\n"
       "unit number within that device.  The Input Manager can therefore\n"
       "keep an array of these around and treat them as command-oriented\n"
       "devices that only return a single sub-device's amount of data (one\n"
       "int)."
       ,
       no_init
      )
      .def("create", &gadget::CommandProxy::create)
      .def("updateData", &gadget::CommandProxy::updateData,
           &pyj::gadget_CommandProxy_Wrapper::default_updateData,
           "updateData()\n"
           "Updates the cached data copy from the device."
      )
      .def("updateDataIfNeeded", &gadget::Proxy::updateDataIfNeeded,
           "updateDataIfNeeded()\n"
      )
      .def("resetData", &gadget::Proxy::resetData,
           "resetData()\n"
      )
      .def("getTimeStamp", &gadget::CommandProxy::getTimeStamp,
           &pyj::gadget_CommandProxy_Wrapper::default_getTimeStamp,
           "getTimeStamp() -> vpr.Interval object\n"
           "Returns the time of the last update."
      )
      .def("config", &gadget::CommandProxy::config,
           &pyj::gadget_CommandProxy_Wrapper::default_config,
           "config(element) -> Boolean\n"
           "Configures this proxy using the given jccl.ConfigElement\n"
           "instance."
      )
      .def("set", &gadget::CommandProxy::set,
           &pyj::gadget_CommandProxy_Wrapper::default_set,
           "set(devName, devPtr)\n"
           "Sets the proxy to point to the given type-specific device.\n"
           "Pre-condition:\n"
           "devPtr must be a valid device of type gadget.Command\n"
           "Post-condition:\n"
           "The proxy now references the given device.  The device name we\n"
           "are proxying is set to devPtr.getInstanceName().\n"
           "Arguments:\n"
           "devName -- The name of the device at which we are pointing.\n"
           "devPtr  -- Pointer to the device.  For gadget.Command,\n"
           "           this points to an instance of gadget.Command."
      )
      .def("refresh", &gadget::CommandProxy::refresh,
           &pyj::gadget_CommandProxy_Wrapper::default_refresh,
           "refresh() -> Boolean\n"
           "Refreshes the proxy.  This attempts to lookup the device that\n"
           "we are proxying.  If the lookup fails, then we become\n"
           "stupefied.  If not, then the proxy is pointed at this\n"
           "potentially new device."
      )
      .def("getDeviceName", &gadget::CommandProxy::getDeviceName,
           &pyj::gadget_CommandProxy_Wrapper::default_getDeviceName,
           "getDeviceName() -> string object\n"
           "Gets the name of the device that we are proxying."
      )
      .def("isStupefied", &gadget::Proxy::isStupefied,
           &pyj::gadget_CommandProxy_Wrapper::default_isStupefied,
           "isStupefied() -> Boolean\n"
           "Is the proxy currently stupefied?\n"
           "If the device we are proxying does not exist, then this will\n"
           "return True."
      )
      .def("getData", &gadget::CommandProxy::getData,
           "getData() -> float\n"
           "Gets the current command data value."
      )
      .def("getCommandData", &gadget::CommandProxy::getCommandData,
           return_internal_reference<1>()
      )
      .def("getCommandPtr", &gadget::CommandProxy::getCommandPtr,
           "getCommandPtr() -> gadget.Command object\n"
      )
      .def("getUnit", &gadget::CommandProxy::getUnit,
           "getUnit() -> int\n"
           "Returns the unit index into the command device from which this\n"
           "proxy is reading data."
      )
      .def("getElementType", &gadget::CommandProxy::getElementType,
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
