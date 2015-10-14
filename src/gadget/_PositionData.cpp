// PyJuggler is (C) Copyright 2002-2012 by Patrick Hartling
// Distributed under the GNU Lesser General Public License 2.1.  (See
// accompanying file COPYING.txt or http://www.gnu.org/copyleft/lesser.txt)

// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <gadget/Type/PositionData.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
void _Export_PositionData()
{
   typedef gadget::PositionData::data_type data_type;
   class_<gadget::PositionData>("PositionData",
       "gadget.InputData subclass for positional data.",
       init<>()
      )
      .def(init<const data_type&>())
      .def("getValue", &gadget::PositionData::getValue,
           return_value_policy<copy_const_reference>())
      .def("setValue", &gadget::PositionData::setValue)
      .def("setTime",
           (void (gadget::InputData::*)()) &gadget::InputData::setTime)
      .def("setTime",
           (void (gadget::InputData::*)(const vpr::Interval&)) &gadget::InputData::setTime)
      .def("getTime", &gadget::InputData::getTime,
           return_value_policy<copy_const_reference>())
   ;
}
