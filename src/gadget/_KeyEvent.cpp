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
#include <vpr/IO/ObjectReader.h>
#include <vpr/IO/ObjectWriter.h>
#include <gadget/Type/EventWindow/KeyEvent.h>

// Using =======================================================================
using namespace boost::python;

// Declarations ================================================================
namespace pyj {

struct gadget_KeyEvent_Wrapper: gadget::KeyEvent
{
    gadget_KeyEvent_Wrapper(PyObject* self_, const gadget::KeyEvent& p0):
        gadget::KeyEvent(p0), self(self_) {}

    gadget_KeyEvent_Wrapper(PyObject* self_, const gadget::EventType& p0, const gadget::Keys& p1, const int& p2, const long unsigned int& p3):
        gadget::KeyEvent(p0, p1, p2, p3), self(self_) {}

    gadget_KeyEvent_Wrapper(PyObject* self_, const gadget::EventType& p0, const gadget::Keys& p1, const int& p2, const long unsigned int& p3, char p4):
        gadget::KeyEvent(p0, p1, p2, p3, p4), self(self_) {}

    gadget_KeyEvent_Wrapper(PyObject* self_):
        gadget::KeyEvent(), self(self_) {}

    vpr::ReturnStatus writeObject(vpr::ObjectWriter* p0) {
        try
        {
            return call_method< vpr::ReturnStatus >(self, "writeObject", p0);
        }
        catch(error_already_set)
        {
            PyErr_Print();
        }

        return vpr::ReturnStatus::Fail;
    }

    vpr::ReturnStatus default_writeObject(vpr::ObjectWriter* p0) {
        return gadget::KeyEvent::writeObject(p0);
    }

    vpr::ReturnStatus readObject(vpr::ObjectReader* p0) {
        try
        {
            return call_method< vpr::ReturnStatus >(self, "readObject", p0);
        }
        catch(error_already_set)
        {
            PyErr_Print();
        }

        return vpr::ReturnStatus::Fail;
    }

    vpr::ReturnStatus default_readObject(vpr::ObjectReader* p0) {
        return gadget::KeyEvent::readObject(p0);
    }

    PyObject* self;
};

}// namespace 


// Module ======================================================================
void _Export_KeyEvent()
{
    scope* gadget_KeyEvent_scope = new scope(
    class_< gadget::KeyEvent, bases< gadget::Event >, pyj::gadget_KeyEvent_Wrapper >("KeyEvent", init<  >())
        .def(init< const gadget::KeyEvent& >())
        .def(init< const gadget::EventType&, const gadget::Keys&, const int&, const long unsigned int&, optional< char > >())
        .def("writeObject", (vpr::ReturnStatus (gadget::KeyEvent::*)(vpr::ObjectWriter*) )&gadget::KeyEvent::writeObject, (vpr::ReturnStatus (pyj::gadget_KeyEvent_Wrapper::*)(vpr::ObjectWriter*))&pyj::gadget_KeyEvent_Wrapper::default_writeObject)
        .def("readObject", (vpr::ReturnStatus (gadget::KeyEvent::*)(vpr::ObjectReader*) )&gadget::KeyEvent::readObject, (vpr::ReturnStatus (pyj::gadget_KeyEvent_Wrapper::*)(vpr::ObjectReader*))&pyj::gadget_KeyEvent_Wrapper::default_readObject)
        .def("getKey", &gadget::KeyEvent::getKey, return_value_policy< copy_const_reference >())
        .def("getModifierMask", &gadget::KeyEvent::getModifierMask, return_value_policy< copy_const_reference >())
        .def("getKeyChar", &gadget::KeyEvent::getKeyChar, return_value_policy< copy_const_reference >())
        .def("type", &gadget::Event::type, return_value_policy< copy_const_reference >())
        .def("setType", &gadget::Event::setType)
        .def("time", &gadget::Event::time, return_value_policy< copy_const_reference >())
    );
    register_ptr_to_python< boost::shared_ptr< gadget::KeyEvent > >();
    delete gadget_KeyEvent_scope;

}
