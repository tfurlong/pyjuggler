// PyJuggler is (C) Copyright 2002-2004 by Patrick Hartling
// Distributed under the GNU Lesser General Public License 2.1.  (See
// accompanying file COPYING.txt or http://www.gnu.org/copyleft/lesser.txt)

// File:          $RCSfile$
// Date modified: $Date$
// Version:       $Revision$

// Includes ====================================================================
#include <boost/python.hpp>
#include <jccl/Config/ConfigElement.h>

// Using =======================================================================
using namespace boost::python;


// Module ======================================================================
void _Export_ConfigElement()
{
    scope* jccl_ConfigElement_scope = new scope(
    class_< jccl::ConfigElement >("ConfigElement",
         "A unit of configuration information.\n"
         "References a config element DOM node and a definition for the given\n"
         "configuration element type."
         ,
         init<  >(
            "__init__()\n"
            "Default constructor.\n\n"
            "__init__(def)\n"
            "Constructs a ConfigElement matching the given definition.\n"
            "Arguments:\n"
            "def -- A ConfigDefinition object that refers to a valid\n"
            "       ConfigDefinition.\n\n"
            "__init__(elt)\n"
            "Copy constructor."
         )
        )
        .def(init< jccl::ConfigDefinitionPtr >())
        .def(init< const jccl::ConfigElement& >())
        .def("isValid", &jccl::ConfigElement::isValid)
        .def("assertValid", &jccl::ConfigElement::assertValid)
        .def("initFromNode", &jccl::ConfigElement::initFromNode,
             "initFromNode(elementNode) -> Boolean\n"
             "Initializes this element from an XML node.\n"
             "Constructs the element to reference the given element node.")
        .def("getChildElement", &jccl::ConfigElement::getChildElement,
             "getChildElement(path) -> ConfigElement\n"
             "Gets a child element from a property of self.\n"
             "Arguments:\n"
             "path -- The complete name of a child element in self.\n"
             "        The form is, for example, \"property_token/instance_name\".\n"
             "NOTE: This uses the name attribute of the elements.\n"
             "Returns:\n"
             "A ConfigElement pointing to the child element.  This may be\n"
             "a NULL ConfigElement if the child element name was not found.\n"
             "Check before use.")
        .def("getNum", &jccl::ConfigElement::getNum,
             "getNum(property) -> int\n"
             "Returns the number of values for the specified property.\n"
             "Arguments:\n"
             "property -- The token of a property in this element.\n"
             "Returns:\n"
             "The number of values that exist for the given property which\n"
             "may be zero.")
        .def("getName", &jccl::ConfigElement::getName,
             "getName() -> string\n"
             "Returns the instance name of this ConfigElement.")
        .def("getFullName", &jccl::ConfigElement::getFullName,
             "getFullName() -> string\n"
             "Returns the fully qualified, unique name of this element.\n"
             "This will be different from getName() when this element is a\n"
             "child of another element.  In that case, the name will be\n"
             "based on the element hierarchy and the property token.  The\n"
             "format in that case will be\n"
             "\"element name 0/proeprty_token_0/element name 1/property_token_1/...\"")
        .def("getVersion", &jccl::ConfigElement::getVersion,
             "getVersion() -> int\n"
             "Returns the version number of the definition used by this\n"
             "ConfigElement.")
        .def("getID", &jccl::ConfigElement::getID,
             "getID() -> string\n"
             "Returns the string that identifies self's ConfigDefinition.")
        .def("setProperty",
             (bool (jccl::ConfigElement::*)(const std::string&, const int, bool) )&jccl::ConfigElement::setProperty)
        .def("setProperty", (bool (jccl::ConfigElement::*)(const std::string&, int, jccl::ConfigElementPtr) )&jccl::ConfigElement::setProperty)
        .def("getElementPtrDependencies",
             &jccl::ConfigElement::getElementPtrDependencies,
             "getElementPtrDependencies() -> string list\n"
             "Returns a list of self's dependencies.\n"
             "Dependencies are any config element objects by an \"Element\n"
             "Pointer\" proeprty of self (or any element embedded in self).\n"
             "Returns:\n"
             "A list of the names of all config elements referenced by self,\n"
             "which can be used for dependency checking.")
        .def("getChildElements", &jccl::ConfigElement::getChildElements,
             "getChildElements() -> ConfigElement list\n"
             "Returns a list of self's child (embedded) elements.\n"
             "Returns:\n"
             "A list of ConfigElement objects that are the config elements\n"
             "embedded in self.")
        .def("getNode", &jccl::ConfigElement::getNode)
        .def(self_ns::str(self))
        .def( self == self )
        .def( self != self )
        .def( self < self )
    );
    register_ptr_to_python< boost::shared_ptr< jccl::ConfigElement > >();
    delete jccl_ConfigElement_scope;
}
