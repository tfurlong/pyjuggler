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
#include <vpr/IO/SerializableObject.h>
#include <vpr/IO/ObjectReader.h>
#include <pyjutil/InterpreterGuard.h>
#include <pyjutil/Debug.h>

// Using =======================================================================
using namespace boost::python;

// Declarations ================================================================
namespace pyj
{

struct vpr_ReadableObject_Wrapper
   : vpr::ReadableObject
   , wrapper<vpr::ReadableObject>
{
   virtual ~vpr_ReadableObject_Wrapper() throw ()
   {
      /* Do nothing. */ ;
   }

   void readObject(vpr::ObjectReader* p0) throw (vpr::IOException)
   {
      vpr::DebugOutputGuard og(pyjDBG_CXX, vprDBG_VERB_LVL,
                               "vpr_ReadableObject_Wrapper::readObject()\n",
                               "vpr_ReadableObject_Wrapper::readObject() done.\n");
      PyJuggler::InterpreterGuard guard;

      try
      {
         this->get_override("readObject")(ptr(p0));
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }
   }
};


}// namespace pyj


// Module ======================================================================
void _Export_ReadableObject()
{
   class_<pyj::vpr_ReadableObject_Wrapper, boost::noncopyable>
      ("ReadableObject")
      .def("readObject", pure_virtual(&vpr::ReadableObject::readObject),
           "readObject(reader)\n"
           "Template method for reading into this object from the given\n"
           "stream.\n"
           "<b>Post condition:</b> All object data is read from the reader."
      )
   ;
}
