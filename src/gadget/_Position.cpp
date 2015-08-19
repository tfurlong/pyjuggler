// PyJuggler is (C) Copyright 2002-2012 by Patrick Hartling
// Distributed under the GNU Lesser General Public License 2.1.  (See
// accompanying file COPYING.txt or http://www.gnu.org/copyleft/lesser.txt)

// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>
#include <boost/python/suite/indexing/vector_indexing_suite.hpp>

// Includes ====================================================================
#include <vpr/IO/ObjectReader.h>
#include <vpr/IO/ObjectWriter.h>
#include <gadget/Type/Position.h>

// Using =======================================================================
using namespace boost::python;

// Declarations ================================================================
namespace pyj
{

struct gadget_Position_Wrapper : gadget::Position, wrapper<gadget::Position>
{
   gadget_Position_Wrapper()
      : gadget::Position()
   {
      /* Do nothing. */ ;
   }

   virtual ~gadget_Position_Wrapper()
   {
      /* Do nothing. */ ;
   }

   bool config(jccl::ConfigElementPtr p0)
   {
      try
      {
         if ( override config = this->get_override("config") )
         {
            return config(p0);
         }
         return gadget::Position::config(p0);
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }

      return false;
   }

   bool default_config(jccl::ConfigElementPtr p0)
   {
      return gadget::Position::config(p0);
   }

   void writeObject(vpr::ObjectWriter* p0)
   {
      try
      {
         if ( override writeObject = this->get_override("writeObject") )
         {
            writeObject(ptr(p0));
         }
         else
         {
            gadget::Position::writeObject(p0);
         }
      }
      catch (error_already_set)
      {
         PyErr_Print();
         throw vpr::IOException(
            "Python exception caught by pyj::gadget_Position_Wrapper::writeObject()",
            VPR_LOCATION
         );
      }
   }

   void default_writeObject(vpr::ObjectWriter* p0)
   {
      gadget::Position::writeObject(p0);
   }

   void readObject(vpr::ObjectReader* p0)
   {
      try
      {
         if ( override readObject = this->get_override("readObject") )
         {
            readObject(ptr(p0));
         }
         else
         {
            gadget::Position::readObject(p0);
         }
      }
      catch (error_already_set)
      {
         PyErr_Print();
         throw vpr::IOException(
            "Python exception caught by pyj::gadget_Position_Wrapper::readObject()",
            VPR_LOCATION
         );
      }
   }

   void default_readObject(vpr::ObjectReader* p0)
   {
      gadget::Position::readObject(p0);
   }
};

}// namespace 


// Module ======================================================================
void _Export_Position()
{
   class_<pyj::gadget_Position_Wrapper, gadget::PositionPtr, boost::noncopyable>(
       "Position",
       "gadget.Position is the abstract base class from which devices\n"
       "returning positional (translation and/or rotation) data must\n"
       "derive.  This is in addition to gadget.Input.  gadget.Input\n"
       "provides pure virtual function constraints in the following\n"
       "functions: startSampling(), stopSampling(), sample(), and\n"
       "updateData()\n\n"
       "gadget.Position adds the function getPositionDdta() for retrieving\n"
       "the received positional data.  This is similar to the additions\n"
       "made by gadget.Analog and gadget.Digital."
       ,
       no_init
      )
      .def("create", &gadget::Position::create)
      .def("config", &gadget::Position::config,
           &pyj::gadget_Position_Wrapper::default_config,
           "config(element) -> Boolean\n"
           "Configures this positional device.\n"
           "Arguments:\n"
           "element -- The config element for a positional device.  It\n"
           "           must derive from the base config element type\n"
           "           'positional_device'."
      )
      .def("writeObject", &gadget::Position::writeObject,
           &pyj::gadget_Position_Wrapper::default_writeObject,
           "writeObject(writer)\n"
           "Serializes this object."
      )
      .def("readObject", &gadget::Position::readObject,
           &pyj::gadget_Position_Wrapper::default_readObject,
           "readObject(reader)\n"
           "De-serializes this object."
      )
      .def("getPositionData", &gadget::Position::getPositionData,
           (args("devNum") = 0),
           return_value_policy<copy_const_reference>(),
           "getPositionData(devNum = 0) -> gadget.PositionData object\n"
           "Returns positional data.\n"
           "Keyword arguments:\n"
           "devNum -- The device unit numbmer to access.  This parameter\n"
           "          optional.  It defaults to 0."
      )
      .def("addPositionSample", &gadget::Position::addPositionSample,
           "addDigitalSample(sampleList)\n"
           "Helper method to add a collection of positional samples to the\n"
           "sample buffers for this device.  This MUST be called by all\n"
           "positional devices to add a new sample.  The data samples\n"
           "passed in will then be modified by any local filters, so the.\n"
           "data does not need to transformed before being passed in.\n"
           "Post-condition:\n"
           "The given samples are added to the buffers, and the local\n"
           "filters are run on the new samples.\n"
           "Arguments:\n"
           "sampleList -- The list of newly collected samples as a\n"
           "              gadget.PositionDataVec object."
      )
      .def("swapPositionBuffers", &gadget::Position::swapPositionBuffers,
           "swapDigitalBuffers()\n"
           "Swaps the positional data buffers.\n"
           "Post-condition:\n"
           "If the ready queue has values, then those values are copied\n"
           "from the ready queue to the stable queue.  If not, the stable\n"
           "queue is not changed."
      )
      .def("getPositionDataBuffer", &gadget::Position::getPositionDataBuffer,
           return_internal_reference<1>(),
           "getPositionDataBuffer() -> list of lists of DigitalData objects\n"
           "Returns the current stable sample buffers for this device."
      )
      .staticmethod("create")
   ;

   class_< std::vector<gadget::PositionData> >("PositionDataVec",
       "An indexable container of gadget.PositionData objects."
      )
      .def(vector_indexing_suite< std::vector<gadget::PositionData> >())
   ;
}
