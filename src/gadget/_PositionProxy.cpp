// PyJuggler is (C) Copyright 2002-2011 by Patrick Hartling
// Distributed under the GNU Lesser General Public License 2.1.  (See
// accompanying file COPYING.txt or http://www.gnu.org/copyleft/lesser.txt)

// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <gadget/Type/PositionProxy.h>

// Using =======================================================================
using namespace boost::python;

// Declarations ================================================================
namespace pyj
{

struct gadget_PositionProxy_Wrapper
   : gadget::PositionProxy
   , wrapper<gadget::PositionProxy>
{
   gadget_PositionProxy_Wrapper(const gadget::PositionProxy& p0)
      : gadget::PositionProxy(p0)
   {
      /* Do nothing. */ ;
   }

   gadget_PositionProxy_Wrapper()
      : gadget::PositionProxy()
   {
      /* Do nothing. */ ;
   }

   virtual ~gadget_PositionProxy_Wrapper()
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
            gadget::PositionProxy::updateData();
         }
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }
   }

   void default_updateData()
   {
      gadget::PositionProxy::updateData();
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

      return gadget::PositionProxy::getTimeStamp();
   }

   const vpr::Interval& default_getTimeStamp() const
   {
      return gadget::PositionProxy::getTimeStamp();
   }

   bool config(jccl::ConfigElementPtr p0)
   {
      try
      {
         if ( override config = this->get_override("config") )
         {
            return config(p0);
         }
         return gadget::PositionProxy::config(p0);
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }

      return false;
   }

   bool default_config(jccl::ConfigElementPtr p0)
   {
      return gadget::PositionProxy::config(p0);
   }

   void set(const std::string& p0, const gadget::PositionPtr& p1)
   {
      try
      {
         if ( override set = this->get_override("set") )
         {
            set(boost::ref(p0), p1);
         }
         else
         {
            gadget::PositionProxy::set(p0, p1);
         }
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }
   }

   void default_set(const std::string& p0, const gadget::PositionPtr& p1)
   {
      gadget::PositionProxy::set(p0, p1);
   }

   bool refresh()
   {
      try
      {
         if ( override refresh = this->get_override("refresh") )
         {
            return refresh();
         }
         return gadget::PositionProxy::refresh();
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }

      return false;
   }

   bool default_refresh()
   {
      return gadget::PositionProxy::refresh();
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

      return gadget::PositionProxy::getDeviceName();
   }

   const std::string& default_getDeviceName() const
   {
      return gadget::PositionProxy::getDeviceName();
   }

   bool isStupefied() const
   {
      try
      {
         if ( override isStupefied = this->get_override("isStupefied") )
         {
            return isStupefied();
         }
         return gadget::PositionProxy::isStupefied();
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }

      return false;
   }

   bool default_isStupefied() const
   {
      return gadget::PositionProxy::isStupefied();
   }

   virtual const gmtl::Matrix44f getData() const
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

      return gadget::PositionProxy::getData();
   }

   const gmtl::Matrix44f default_getData() const
   {
      return gadget::PositionProxy::getData();
   }
};

}// namespace 


// Module ======================================================================
void _Export_PositionProxy()
{
   class_<pyj::gadget_PositionProxy_Wrapper, gadget::PositionProxyPtr>(
       "PositionProxy",
       "A proxy class to positional devices used by the Input Manager.\n\n"
       "A position proxy always points to a positional device and a unit\n"
       "number within that device.  The Input Manager can therefore keep\n"
       "an array of these around and treat them as positional devices that\n"
       "only return a single sub-device's amount of data (one int)."
       ,
       no_init
      )
      .def("create", &gadget::PositionProxy::create)
      .def("updateData", &gadget::PositionProxy::updateData,
           &pyj::gadget_PositionProxy_Wrapper::default_updateData,
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
      .def("getTimeStamp", &gadget::PositionProxy::getTimeStamp,
           &pyj::gadget_PositionProxy_Wrapper::default_getTimeStamp,
           return_value_policy<copy_const_reference>(),
           "getTimeStamp() -> vpr.Interval object\n"
           "Returns the time of the last update."
      )
      .def("config", &gadget::PositionProxy::config,
           &pyj::gadget_PositionProxy_Wrapper::default_config,
           "config(element) -> Boolean\n"
           "Configures this proxy using the given jccl.ConfigElement\n"
           "instance."
      )
      .def("set", &gadget::PositionProxy::set,
           &pyj::gadget_PositionProxy_Wrapper::default_set,
           "set(devName, devPtr)\n"
           "Sets the proxy to point to the given type-specific device.\n"
           "Pre-condition:\n"
           "devPtr must be a valid device of type gadget.Digital\n"
           "Post-condition:\n"
           "The proxy now references the given device.  The device name we\n"
           "are proxying is set to devPtr.getInstanceName().\n"
           "Arguments:\n"
           "devName -- The name of the device at which we are pointing.\n"
           "devPtr  -- Pointer to the device.  For gadget.Digital,\n"
           "           this points to an instance of gadget.Digital."
      )
      .def("refresh", &gadget::PositionProxy::refresh,
           &pyj::gadget_PositionProxy_Wrapper::default_refresh,
           "refresh() -> Boolean\n"
           "Refreshes the proxy.  This attempts to lookup the device that\n"
           "we are proxying.  If the lookup fails, then we become\n"
           "stupefied.  If not, then the proxy is pointed at this\n"
           "potentially new device."
      )
      .def("getDeviceName", &gadget::PositionProxy::getDeviceName,
           &pyj::gadget_PositionProxy_Wrapper::default_getDeviceName,
           return_value_policy<copy_const_reference>(),
           "getDeviceName() -> string object\n"
           "Gets the name of the device that we are proxying."
      )
      .def("isStupefied", &gadget::Proxy::isStupefied,
           &pyj::gadget_PositionProxy_Wrapper::default_isStupefied,
           "isStupefied() -> Boolean\n"
           "Is the proxy currently stupefied?\n"
           "If the device we are proxying does not exist, then this will\n"
           "return True."
      )
      .def("getData",
           (const gmtl::Matrix44f (gadget::PositionProxy::*)() const) &gadget::PositionProxy::getData,
           &pyj::gadget_PositionProxy_Wrapper::default_getData,
           "getData() -> gmtl.Matrix44f object\n"
           "Gets the current positional data value from the device as a.\n"
           "matrix using feet as the scale factor.\n"
      )
      .def("getData",
           (const gmtl::Matrix44f (gadget::PositionProxy::*)(const float) const) &gadget::PositionProxy::getData,
           (args("scaleFactor") = gadget::PositionUnitConversion::ConvertToFeet),
           "getData(scaleFactor = gadget.PositionUnitConversion.ConvertToFeet) -> gmtl.Matrix44f object\n"
           "Gets the current positional data value from the device as a.\n"
           "matrix.  For example, getData(3.28) will return a matrix in\n"
           "feet.\n"
           "Keyword Arguments:\n"
           "scaleFactor -- Factor to convert from meters to the desired\n"
           "               units.  This paramter is optional.  If not\n"
           "               specified, it defaults to the conversion factor\n"
           "               from meters to feet."
      )
      .def("getUnit", &gadget::PositionProxy::getUnit,
           "getUnit() -> int\n"
           "Returns the unit index into the analog device from which this\n"
           "proxy is reading data."
      )
      .def("getTypedInputDevice", &gadget::PositionProxy::getTypedInputDevice,
           "getTypedInputDevice() -> gadget.Position object\n"
           "Returns the gadget.Position object held by this proxy."
      )
      .def("getElementType", &gadget::PositionProxy::getElementType,
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
