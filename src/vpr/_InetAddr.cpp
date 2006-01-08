// PyJuggler is (C) Copyright 2002-2006 by Patrick Hartling
// Distributed under the GNU Lesser General Public License 2.1.  (See
// accompanying file COPYING.txt or http://www.gnu.org/copyleft/lesser.txt)

// File:          $RCSfile$
// Date modified: $Date$
// Version:       $Revision$

// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <vpr/IO/Socket/InetAddr.h>
#include <container_conversions.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
void _Export_InetAddr()
{
   scope* vpr_InetAddr_scope = new scope(
   class_< vpr::InetAddr >("InetAddr",
      "Cross-platform abstraction to Internet address structures.",
      init<>(
         "__init__()\n"
         "Default constructor. This initializes the memory for the\n"
         "encapsulated address structure.\n"
         "<b>Post condition:</b> The internal socket address structure has\n"
         "its memory zeroed, and the port and internet address are set to\n"
         "wildcard values.\n\n"
         "__init__(addr)\n"
         "Copy constructor.\n"
         "<b>Post condition:</b> A copy of the given vpr.InetAddr object is\n"
         "made in this object.\n"
         "Arguments:\n"
         "addr -- The vpr.InetAddr reference whose state will be copied into\n"
         "        this object."
      ))
      .def(init< const vpr::InetAddr& >())
      .def_readonly("AnyAddr", &vpr::InetAddr::AnyAddr,
           "Read-only vpr.InetAddr reference representing any internet\n"
           "address (INADDR_ANY)."
      )
      .def("getLocalHost", &vpr::InetAddr::getLocalHost,
           "getLocalHost() -> InetAddr object\n"
           "Returns a new vpr.InetAddr object holding the local host's\n"
           "default address with the port number set to 0."
      )
      .def("getAllLocalAddrs", &vpr::InetAddr::getAllLocalAddrs,
           (args("withLoopback") = false),
           "getAllLocalAddrs(withLoopback = False) -> list of InetAddr objects\n"
           "Retrieves all the IPv4 addresses associated with the local\n"
           "machine including the loopback address (127.0.0.1) if so\n"
           "indicated.\n"
           "Keyword arguments:\n"
           "withLoopback -- A Boolean flag indicating whether to include the\n"
           "                loopback address (127.0.0.1) in the returned\n"
           "                list. This parameter is optional and defaults to\n"
           "                False."
      )
      .def("setAddress",
           (void (vpr::InetAddr::*)(const std::string&) throw(vpr::UnknownHostException)) &vpr::InetAddr::setAddress,
           "setAddress(address)\n"
           "Sets the address for this objet using the given string. The given\n"
           "string must be of the form address:port where address can be a\n"
           "hostname or a dotted-decimal IPv4 address.\n"
           "Arguments:\n"
           "address -- A string giving the address and port number separated\n"
           "           by a colon. The address can be a hostname or a\n"
           "           dotted-decimal IPv4 address.\n\n"
           "setAddress(address, port)\n"
           "Sets the address for this object using the given address string\n"
           "and port number. The address string can be a hostname or a\n"
           "dotted-decimal IPv4 address.\n"
           "Arguments:\n"
           "address -- A string giving the address (either hostname or IPv4\n"
           "           address).\n"
           "port    -- The port to associate with this IPv4 address.\n\n"
           "setAddress(address, port)\n"
           "Sets the address for this object using the given address and port\n"
           "number. The address string can be a hostname or a dotted-decimal\n"
           "IPv4 address.\n"
           "Arguments:\n"
           "address -- A 32-bit integer IPv4 address.\n"
           "port    -- The port to associate with this IPv4 address."
      )
      .def("setAddress",
           (void (vpr::InetAddr::*)(const std::string&, const vpr::Uint16) throw(vpr::UnknownHostException)) &vpr::InetAddr::setAddress)
      .def("setAddress",
           (void (vpr::InetAddr::*)(const vpr::Uint32, const vpr::Uint16)) &vpr::InetAddr::setAddress)
      .def("getLength", &vpr::InetAddr::getLength,
           "getLength() -> integer\n"
           "Gets the length of the address structure (if supported by the\n"
           "host OS).\n"
           "<b>Post condition:</b> The length of the address structure is\n"
           "                       returned if the OS supports that feature.\n"
           "                       Otherwise, 0 is returned."
      )
      .def("setLength", &vpr::InetAddr::setLength,
           "setLength(length)\n"
           "Sets the length of the address structure (if the host OS allows\n"
           "such an operation.)\n"
           "<b>Post condition:</b> The length of the address structure is set\n"
           "                       to the given value if the OS supports that\n"
           "                       feature. Otherwise, this is a no-op."
      )
      .def("getFamily", &vpr::InetAddr::getFamily,
           "getFamily() -> integer\n"
           "Gets the protocol family of this address.\n"
           "<b>Pre condition:</b> The protocol family has been initialized\n"
           "                      properly."
      )
      .def("setFamily", &vpr::InetAddr::setFamily,
           "setFamily(family)\n"
           "Sets the protocol family of this address.\n"
           "<b>Post condition:</b> The given protocol family is mapped to\n"
           "                       the appropriate platform-specific protocol\n"
           "                       family value and stored.\n"
           "Arguments:\n"
           "family -- The protocol family value."
      )
      .def("getPort", &vpr::InetAddr::getPort,
           "getPort() -> integer\n"
           "Gets this address' port in host byte order.\n"
           "<b>Pre condition:</b> The port has been initialized properly in\n"
           "                      network byte order."
      )
      .def("setPort", &vpr::InetAddr::setPort,
           "setPort(port)\n"
           "Sets this address' port. The given port number must be in host\n"
           "byte order.\n"
           "<b>Pre condition:</b> The given port number is in host byte order.\n"
           "<b>Post condition:</b> The given port number is stored.\n"
           "Arguments:\n"
           "port -- An unsigned 16-bit integer port number for this address\n"
           "        in host byte order."
      )
      .def("getAddressValue", &vpr::InetAddr::getAddressValue,
           "getAddressValue() -> integer\n"
           "Gets this address' internet address in host byte order.\n"
           "<b>Pre condition:</b> The IP address has been initialized properly\n"
           "                      in network byte order."
      )
      .def("getAddressString", &vpr::InetAddr::getAddressString,
           "getAddressString() -> string\n"
           "Gets the IP address associated with this object as a "
           "human-readable string.\n"
           "That is, it returns a string in the \"dotted-decimal\" notation.\n"
           "<b>Pre condition:</b> This object contains a valid IP address."
      )
      .def("getHostname", &vpr::InetAddr::getHostname,
           "getHostname() -> string\n"
           "Returns the fully qualified hostname for this address."
      )
      .def("getHostnames", &vpr::InetAddr::getHostnames,
           "getHostnames() -> list\n"
           "Returns the fully qualified primary hostname for this address\n"
           "and all known aliases as a list of strings."
      )
      .staticmethod("getAllLocalAddrs")
      .staticmethod("getLocalHost")
      .def( self == self )
      .def( self != self )
   );

   delete vpr_InetAddr_scope;

   pyj::copyable_to_python<std::vector<std::string>, list>();
   pyj::copyable_to_python<std::vector<vpr::InetAddr>, list>();
}
