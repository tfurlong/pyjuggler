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
#include <vpr/IO/Socket/InetAddr.h>

// Using =======================================================================
using namespace boost::python;

// Declarations ================================================================
namespace pyj
{

BOOST_PYTHON_FUNCTION_OVERLOADS(vpr_InetAddrBSD_getAllLocalAddrs_overloads_1_2, vpr::InetAddrBSD::getAllLocalAddrs, 1, 2)

}

// Module ======================================================================
void _Export_InetAddr()
{
   scope* vpr_InetAddr_scope = new scope(
   class_< vpr::InetAddrBSD >("InetAddr", init<  >())
        .def(init< const vpr::InetAddrBSD& >())
        .def_readonly("AnyAddr", &vpr::InetAddrBSD::AnyAddr)
        .def("getLocalHost", &vpr::InetAddrBSD::getLocalHost)
        .def("getAllLocalAddrs", &vpr::InetAddrBSD::getAllLocalAddrs, pyj::vpr_InetAddrBSD_getAllLocalAddrs_overloads_1_2())
        .def("setAddress", (void (vpr::InetAddrBSD::*)(const std::string&)  throw(vpr::UnknownHostException))&vpr::InetAddrBSD::setAddress)
        .def("setAddress", (void (vpr::InetAddrBSD::*)(const std::string&, const vpr::Uint16)  throw(vpr::UnknownHostException))&vpr::InetAddrBSD::setAddress)
        .def("setAddress", (void (vpr::InetAddrBSD::*)(const vpr::Uint32, const vpr::Uint16) )&vpr::InetAddrBSD::setAddress)
        .def("getLength", &vpr::InetAddrBSD::getLength)
        .def("setLength", &vpr::InetAddrBSD::setLength)
        .def("getFamily", &vpr::InetAddrBSD::getFamily)
        .def("setFamily", &vpr::InetAddrBSD::setFamily)
        .def("getPort", &vpr::InetAddrBSD::getPort)
        .def("setPort", &vpr::InetAddrBSD::setPort)
        .def("getAddressValue", &vpr::InetAddrBSD::getAddressValue)
        .def("getAddressString", &vpr::InetAddrBSD::getAddressString)
        .def("getHostname", (void (vpr::InetAddrBSD::*)(std::string&) const throw(vpr::UnknownHostException))&vpr::InetAddrBSD::getHostname)
        .def("getHostnames", (std::vector<std::basic_string<char, std::char_traits<char>, std::allocator<char> >,std::allocator<std::basic_string<char, std::char_traits<char>, std::allocator<char> > > > (vpr::InetAddrBSD::*)() const throw(vpr::UnknownHostException))&vpr::InetAddrBSD::getHostnames)
        .def("getHostname", (void (vpr::InetAddrBase::*)(std::string&) const)&vpr::InetAddrBase::getHostname)
        .def("getHostnames", (std::vector<std::basic_string<char, std::char_traits<char>, std::allocator<char> >,std::allocator<std::basic_string<char, std::char_traits<char>, std::allocator<char> > > > (vpr::InetAddrBase::*)() const)&vpr::InetAddrBase::getHostnames)
        .staticmethod("getAllLocalAddrs")
        .staticmethod("getLocalHost")
        .def( self == self )
        .def( self != self )
   );

   delete vpr_InetAddr_scope;
}
