// PyJuggler is (C) Copyright 2002-2004 by Patrick Hartling
// Distributed under the GNU Lesser General Public License 2.1.  (See
// accompanying file COPYING.txt or http://www.gnu.org/copyleft/lesser.txt)

// File:          $RCSfile$
// Date modified: $Date$
// Version:       $Revision$

// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <gadgeteer-wrappers.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
void _Export_SpeechRecogStringInterface()
{
    class_< gadgetWrapper::SpeechRecogStringInterface >("SpeechRecogStringInterface",
         "Wrapper to provide an easier way to access digital speech\n"
         "recognition proxy objects from within user applications.  Users\n"
         "can simply declare a local interface variable and use it as a\n"
         "smart pointer for the proxy."
         ,
         init<  >()
        )
        .def(init< const gadgetWrapper::SpeechRecogStringInterface& >())
        .def("init", &gadgetWrapper::SpeechRecogStringInterface::init,
             "init(proxyName)\n"
             "Initializes this object.\n"
             "Arguments:\n"
             "proxyName -- String name of the digital speech recognition\n"
             "             proxy to connect to."
         )
        .def("refresh", &gadgetWrapper::SpeechRecogStringInterface::refresh,
             "refresh()\n"
             "Refreshes the interface based on the current configuration.\n"
             "Post-conditions:\n"
             "(mProxyIndex == -1) ==> Proxy not initialized yet.\n"
             "(mProxyIndex !- -1) ==> mProxyName has name of device and\n"
             "                        local proxy pionter is set to the\n"
             "                        digital speech recognition device."
         )
        .def("getProxyName",
             &gadgetWrapper::SpeechRecogStringInterface::getProxyName,
             "getProxyName() -> string object\n"
             "Returns the name of the proxy."
         )
        .def("isConnected",
             &gadgetWrapper::SpeechRecogStringInterface::isConnected,
             "isConnected() -> Boolean\n"
             "Identifies whether this device interface is connected to a\n"
             "proxy."
         )
        .def("getProxy", &gadgetWrapper::SpeechRecogStringInterface::getProxy,
             return_internal_reference< 1 >(),
             "getProxy() -> gadget.StringProxy object\n"
             "Returns the underlying proxy to which we are connected."
         )
        .def("getTimeStamp",
             &gadgetWrapper::SpeechRecogStringInterface::getTimeStamp,
             "getTimeStamp() -> vpr.Interval object\n"
             "Returns the time of the last update."
         )
        .def("getData", &gadgetWrapper::SpeechRecogStringInterface::getData,
             "getData() -> string object\n"
             "Gets the current string value from the device."
         )
    ;

}
