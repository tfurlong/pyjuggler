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
#include <container_conversions.h>

// Using =======================================================================
using namespace boost::python;

// Declarations ================================================================
namespace pyj
{

BOOST_PYTHON_FUNCTION_OVERLOADS(vpr_InetAddr_getAllLocalAddrs_overloads_0_1, vpr::InetAddr::getAllLocalAddrs, 0, 1)

}

// Module ======================================================================
void _Export_InetAddr()
{
   scope* vpr_InetAddr_scope = new scope(
   class_< vpr::InetAddr >("InetAddr", init<  >())
        .def(init< const vpr::InetAddr& >())
        .def_readonly("AnyAddr", &vpr::InetAddr::AnyAddr)
        .def("getLocalHost", &vpr::InetAddr::getLocalHost)
        .def("getAllLocalAddrs", &vpr::InetAddr::getAllLocalAddrs, pyj::vpr_InetAddr_getAllLocalAddrs_overloads_0_1())
        .def("setAddress", (void (vpr::InetAddr::*)(const std::string&)  throw(vpr::UnknownHostException))&vpr::InetAddr::setAddress)
        .def("setAddress", (void (vpr::InetAddr::*)(const std::string&, const vpr::Uint16)  throw(vpr::UnknownHostException))&vpr::InetAddr::setAddress)
        .def("setAddress", (void (vpr::InetAddr::*)(const vpr::Uint32, const vpr::Uint16) )&vpr::InetAddr::setAddress)
        .def("getLength", &vpr::InetAddr::getLength)
        .def("setLength", &vpr::InetAddr::setLength)
        .def("getFamily", &vpr::InetAddr::getFamily)
        .def("setFamily", &vpr::InetAddr::setFamily)
        .def("getPort", &vpr::InetAddr::getPort)
        .def("setPort", &vpr::InetAddr::setPort)
        .def("getAddressValue", &vpr::InetAddr::getAddressValue)
        .def("getAddressString", &vpr::InetAddr::getAddressString)
        .def("getHostname", &vpr::InetAddr::getHostname)
        .def("getHostnames", &vpr::InetAddr::getHostnames)
        .staticmethod("getAllLocalAddrs")
        .staticmethod("getLocalHost")
        .def( self == self )
        .def( self != self )
   );

   delete vpr_InetAddr_scope;

   pyj::std_vector_copyable_to_list<std::string>();
   pyj::std_vector_copyable_to_list<vpr::InetAddr>();
}
