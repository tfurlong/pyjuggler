// PyJuggler is (C) Copyright 2002-2012 by Patrick Hartling
// Distributed under the GNU Lesser General Public License 2.1.  (See
// accompanying file COPYING.txt or http://www.gnu.org/copyleft/lesser.txt)

// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <gadget/Type/CommandData.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
void _Export_CommandData()
{
   typedef gadget::CommandData::data_type data_type;
   class_<gadget::CommandData>("CommandData",
      "gadget.InputData subclass for command data.",
      init<>()
     )
     .def(init<const data_type&>())
     .def("getValue", &gadget::CommandData::getValue,
          return_value_policy<copy_const_reference>())
     .def("setValue", &gadget::CommandData::setValue)
     .def("setTime",
          (void (gadget::InputData::*)()) &gadget::InputData::setTime)
     .def("setTime",
          (void (gadget::InputData::*)(const vpr::Interval&)) &gadget::InputData::setTime)
     .def("getTime", &gadget::InputData::getTime,
          return_value_policy<copy_const_reference>())
   ;
}
