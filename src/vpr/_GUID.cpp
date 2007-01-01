// PyJuggler is (C) Copyright 2002-2007 by Patrick Hartling
// Distributed under the GNU Lesser General Public License 2.1.  (See
// accompanying file COPYING.txt or http://www.gnu.org/copyleft/lesser.txt)

// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <vpr/Util/GUID.h>

// Using =======================================================================
using namespace boost::python;

// Declarations ================================================================
namespace pyj
{

struct vpr_GUID_Wrapper : vpr::GUID, wrapper<vpr::GUID>
{
   vpr_GUID_Wrapper(const vpr::GUID::GenerateTag& p0)
      : vpr::GUID(p0)
   {
      /* Do nothing. */ ;
   }

   vpr_GUID_Wrapper()
      : vpr::GUID()
   {
      /* Do nothing. */ ;
   }

   vpr_GUID_Wrapper(const std::string& p0)
      : vpr::GUID(p0)
   {
      /* Do nothing. */ ;
   }

   vpr_GUID_Wrapper(const vpr::GUID& p0, const std::string& p1)
      : vpr::GUID(p0, p1)
   {
      /* Do nothing. */ ;
   }

   vpr_GUID_Wrapper(const vpr::GUID& p0)
      : vpr::GUID(p0)
   {
      /* Do nothing. */ ;
   }

   virtual ~vpr_GUID_Wrapper()
   {
      /* Do nothing. */ ;
   }
};

struct GuidPickle : pickle_suite
{
   static tuple getstate(const vpr::GUID& g)
   {
      return make_tuple(g.mGuid.packed.l0, g.mGuid.packed.l1,
                        g.mGuid.packed.l2, g.mGuid.packed.l3);
   }

   static void setstate(vpr::GUID& g, tuple state)
   {
      g.mGuid.packed.l0 = extract<vpr::Uint32>(state[0]);
      g.mGuid.packed.l1 = extract<vpr::Uint32>(state[1]);
      g.mGuid.packed.l2 = extract<vpr::Uint32>(state[2]);
      g.mGuid.packed.l3 = extract<vpr::Uint32>(state[3]);
   }
};

vpr::Int32 guid_hash(vpr::GUID* g)
{
   static vpr::GUID::hash hash;
   // Chop off the most significant bit and turn it into a signed Int.
   return vpr::Int32(0x7FFFFFFF & vpr::Uint32(hash(*g)));
}

}// namespace pyj


// Module ======================================================================
void _Export_GUID()
{
   scope* vpr_GUID_scope = new scope(
   class_<pyj::vpr_GUID_Wrapper, bases<vpr::SerializableObject> >("GUID",
       init<>(
          "__init__()\n"
          "Creates an empty GUID equal to PyJuggler.vpr.GUID.NullGUID.\n\n"
          "__init__(GenerateTag)\n"
          "Creates a new, non-empty GUID.\n\n"
          "__init__(guid_string)\n"
          "Generates a GUID from the given string representation of the GUID\n"
          "using a string.\n"
          "Format: \"8x-4x-4x-2x2x-2x2x2x2x2x2x\"\n\n"
          "Arguments:\n"
          "guid_string -- A string that is used to initialize a GUID.\n\n"
          "__init__(GUID, 'name')\n"
          "Generates a GUID based on the given name that is part of the\n"
          "namespace identified by the given namespace GUID."
       )
      )
      .def(init<const vpr::GUID::GenerateTag&>())
      .def(init<const std::string&>())
      .def(init<const vpr::GUID&, const std::string&>())
      .def(init<const vpr::GUID&>())
      .def_readonly("generateTag", &vpr::GUID::generateTag)
      .def_readonly("NullGUID", &vpr::GUID::NullGUID)
      .def("toString", &vpr::GUID::toString,
           "Converts this GUID to its corresponding string representation."
      )
      .def("generate", (void (vpr::GUID::*)()) &vpr::GUID::generate)
      .def("generate",
           (void (vpr::GUID::*)(const vpr::GUID &, const std::string&)) &vpr::GUID::generate
      )
      .def("__hash__", pyj::guid_hash)
      .def_pickle(pyj::GuidPickle())
      .def("__str__", &vpr::GUID::toString)
      .def("__eq__", &vpr::GUID::operator==)
      .def("__ne__", &vpr::GUID::operator!=)
      .def("__lt__", &vpr::GUID::operator<)
   );

   class_<vpr::GUID::GenerateTag>("GenerateTag",
                                  "Tag to the constructor to force generation.",
                                  init<>()
      )
      .def(init<const vpr::GUID::GenerateTag&>())
   ;

   class_<vpr::GUID::hash>("hash",
       "Hasher for vpr.GUID.  This can be used with std::hash_map and\n"
       "friends."
       ,
       init<>()
      )
      .def(init<const vpr::GUID::hash&>())
      .def("__call__", (::size_t (vpr::GUID::hash::*)(const vpr::GUID&) const)&vpr::GUID::hash::operator())
   ;

   delete vpr_GUID_scope;
}
