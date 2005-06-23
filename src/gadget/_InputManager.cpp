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
#include <gadget/Type/Proxy.h>
#include <gadget/InputManager.h>

// Using =======================================================================
using namespace boost::python;

// Declarations ================================================================
namespace pyj
{

struct gadget_InputManager_Wrapper
   : gadget::InputManager
   , wrapper<gadget::InputManager>
{
   virtual ~gadget_InputManager_Wrapper()
   {
      /* Do nothing. */ ;
   }

   bool configAdd(jccl::ConfigElementPtr p0)
   {
      try
      {
         if ( override configAdd = this->get_override("configAdd") )
         {
            return configAdd(p0);
         }
         return gadget::InputManager::configAdd(p0);
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }

      return false;
   }

   bool default_configAdd(jccl::ConfigElementPtr p0)
   {
      return gadget::InputManager::configAdd(p0);
   }

   bool configRemove(jccl::ConfigElementPtr p0)
   {
      try
      {
         if ( override configRemove = this->get_override("configRemove") )
         {
            return configRemove(p0);
         }
         return gadget::InputManager::configRemove(p0);
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }

      return false;
   }

   bool default_configRemove(jccl::ConfigElementPtr p0)
   {
      return gadget::InputManager::configRemove(p0);
   }

   bool configCanHandle(jccl::ConfigElementPtr p0)
   {
      try
      {
         if ( override configCanHandle = this->get_override("configCanHandle") )
         {
            return configCanHandle(p0);
         }
         return gadget::InputManager::configCanHandle(p0);
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }

      return false;
   }

   bool default_configCanHandle(jccl::ConfigElementPtr p0)
   {
      return gadget::InputManager::configCanHandle(p0);
   }

   int configProcessPending()
   {
      try
      {
         if ( override configProcessPending =
                 this->get_override("configProcessPending") )
         {
            return configProcessPending();
         }
         return jccl::ConfigElementHandler::configProcessPending();
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }

      return 0;
   }

   int default_configProcessPending()
   {
      return jccl::ConfigElementHandler::configProcessPending();
   }
};


}// namespace 


// Module ======================================================================
void _Export_InputManager()
{
   class_<pyj::gadget_InputManager_Wrapper, boost::noncopyable>
      ("InputManager",
       "The Input Manager holds and managed all Gadgeteer input devices.\n\n"
       "The Input Manager handles all the details behind organizing the\n"
       "input devices in the library.  It provides an API for adding\n"
       "devices by their JCCL config element and deleting them by their\n"
       "element (or just their string name).\n\n"
       "Proxies are used to abstract away from the devices so any type and\n"
       "number of devices may be accessed in the same way.  These proxies\n"
       "are also set up by config elements and should be accessed by\n"
       "number rather than by name (for speed reasons)."
       ,
       no_init
      )
      .def("configAdd", &gadget::InputManager::configAdd,
           &pyj::gadget_InputManager_Wrapper::default_configAdd,
           "configAdd(element) -> Boolean\n"
           "Adds the element to the configuration.\n"
           "Pre-condition:\n"
           "configCanHandle(element) == True\n"
      )
      .def("configRemove", &gadget::InputManager::configRemove,
           &pyj::gadget_InputManager_Wrapper::default_configRemove,
           "configRemove(element) -> Boolean\n"
           "Removes the element from the current configuration.\n"
           "Pre-condition:\n"
           "configCanHandle(element) == True\n"
           "Post-condition:\n"
           "   (element is proxy) ==> (returns == False)\n"
           "   (element is device) ==> (device is removed && proxies are\n"
           "                           stupefied)\n"
           "   (element is proxy_alias) ==> (proxy_alias is removed &&\n"
           "                                devInterfaces.refreshAll())"
      )
      .def("configCanHandle", &gadget::InputManager::configCanHandle,
           &pyj::gadget_InputManager_Wrapper::default_configCanHandle,
           "configCanHandle(element) -> Boolean\n"
           "Can we handle the given element?\n"
           "Returns:\n"
           "True is returned if we can handle the given element.  False\n"
           "is returned otherwise."
      )
      .def("configProcessPending",
           &jccl::ConfigElementHandler::configProcessPending,
           &pyj::gadget_InputManager_Wrapper::default_configProcessPending,
           "configProcessPending(element) -> Boolean\n"
           "Checks if this handler can process the given config element.\n"
           "Typically, an implementation of this method will check the\n"
           "element's definition ID to decide if it knows how to deal with\n"
           "it.\n"
           "Arguments:\n"
           "element -- The current config element that is ready to be\n"
           "           processed.\n"
           "Returns:\n"
           "True is returned if and only if this handler can process the\n"
           "given element."
      )
      .def("instance", &gadget::InputManager::instance,
           return_value_policy<reference_existing_object>(),
           "gadget.InputManager.instance() -> gadget.InputManager object\n"
           "Returns the singleton Input Manager reference."
      )
      .def("getDisplaySystemElement",
           &gadget::InputManager::getDisplaySystemElement,
           "getDisplaySystemElement() -> jccl.ConfigElement object"
      )
      .def("configureDevice", &gadget::InputManager::configureDevice,
           "configureDevice(element) -> Boolean\n"
           "Loads the device for the given element.\n"
           "Returns:\n"
           "True is returned if the device was configured and added."
      )
      .def("updateAllDevices", &gadget::InputManager::updateAllDevices,
           "updateAllDevices()\n"
           "Updates the data in all the devices.  This calls updateData()\n"
           "on all the devices in the device table."
      )
      .def("updateAllProxies", &gadget::InputManager::updateAllProxies,
           "updateAllProxies()\n"
           "Updates all proxies by grabbing the correct data and\n"
           "transforming it."
      )
      .def("getDevice", &gadget::InputManager::getDevice,
           return_internal_reference<1>(),
           "getDevice(deviceName) -> gadget.Input object\n"
           "Returns a gadget.Input object to the named device.\n"
           "Returns:\n"
           "None is returned if the device is not found."
      )
      .def("addDevice", &gadget::InputManager::addDevice,
           "addDevice(devPtr) -> Boolean\n"
           "Addds the given device to the Input Manager.  The given device\n"
           "should not already be in the array of registered devices.\n"
           "Post-condition:\n"
           "mDevTable ' = union of mDevTable and devPtr\n"
           "Arguemnts:\n"
           "devPtr -- An object whose base type is gadget.Input.\n"
           "Returns:\n"
           "False is returned if device addition fails."
      )
      .def("addRemoteDevice", &gadget::InputManager::addRemoteDevice,
           "Adds a remote device to the Input Manager.  The given device\n"
           "should not already be in the array of registered devices.\n"
           "Post-condition:\n"
           "mDevTable ' = union of mDevTable and devPtr\n"
           "Arguemnts:\n"
           "devPtr -- An object whose base type is gadget.Input.\n"
           "Returns:\n"
           "False is returned if device addition fails."
      )
      .def("removeDevice",
           (bool (gadget::InputManager::*)(const std::string&)) &gadget::InputManager::removeDevice,
           "remoteDevice(devName) -> Boolean\n"
           "Removes the named device from the Input Manager.\n"
           "Post-condition:\n"
           "mDevTable[devName] == None\n"
           "Arguments:\n"
           "devName -- A string naming the device to be removed.\n"
           "Returns:\n"
           "True is returned on success.\n\n"
           "removeDevice(devPtr) -> Boolean\n"
           "Removes the device identified by the given gadget.Input\n"
           "object.\n"
           "Arguments:\n"
           "devPtr -- The device object to remove."
      )
      .def("removeDevice",
           (bool (gadget::InputManager::*)(const gadget::Input*)) &gadget::InputManager::removeDevice)
      .def("addProxy", &gadget::InputManager::addProxy,
           "addProxy(proxy) -> Boolean\n"
           "Adds the given gadget.Proxy object to the proxy table.\n"
           "Arguments:\n"
           "proxy -- The given proxy object to add.  It is added using the\n"
           "         name returned by proxy.getName()\n"
           "Returns:\n"
           "True is returned if the proxy was added correctly."
      )
      .def("getProxy", &gadget::InputManager::getProxy,
           return_internal_reference<1>(),
           "getProxy(proxyName) -> gadget.Proxy object\n"
           "Gets a proxy having the given name (or alias).\n"
           "Arguments:\n"
           "proxyName -- A string identifier that is a proxy name or alias.\n"
           "Returns:\n"
           "None is returned if the named proxy is not found."
      )
      .def("refreshAllProxies", &gadget::InputManager::refreshAllProxies,
           "refreshAllProxies()\n"
           "Refreshes all the proxies to have them update the device at\n"
           "which they point."
      )
      .def("getInputLogger", &gadget::InputManager::getInputLogger,
           "getInputLogger() -> gadget.InputLogger object\n"
           "Gets the input logger connected to the Input Manager."
      )
      .staticmethod("instance")
//      .def(other<std::ostream>() << self)
   ;
}
