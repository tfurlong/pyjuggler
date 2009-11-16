// PyJuggler is (C) Copyright 2002-2009 by Patrick Hartling
// Distributed under the GNU Lesser General Public License 2.1.  (See
// accompanying file COPYING.txt or http://www.gnu.org/copyleft/lesser.txt)

// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <gadget/Type/AnalogData.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
void _Export_AnalogData()
{
   class_<gadget::AnalogData>("AnalogData",
       "gadget.InputData subclass for analog data.",
       init<>()
      )
      .def(init<const gadget::AnalogData&>())
      .def(init<float>())
      .def("getAnalog", &gadget::AnalogData::getAnalog)
      .def("setAnalog", &gadget::AnalogData::setAnalog)
      .def("setTime",
           (void (gadget::InputData::*)()) &gadget::InputData::setTime)
      .def("setTime",
           (void (gadget::InputData::*)(const vpr::Interval&)) &gadget::InputData::setTime)
      .def("getTime", &gadget::InputData::getTime,
           return_value_policy<copy_const_reference>())
   ;
}
