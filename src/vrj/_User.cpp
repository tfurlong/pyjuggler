// PyJuggler is (C) Copyright 2002-2011 by Patrick Hartling
// Distributed under the GNU Lesser General Public License 2.1.  (See
// accompanying file COPYING.txt or http://www.gnu.org/copyleft/lesser.txt)

// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <vrj/Kernel/User.h>

// Using =======================================================================
using namespace boost::python;


// Module ======================================================================
void _Export_User()
{
   class_<vrj::User, vrj::UserPtr, boost::noncopyable>("User",
       "Representation for Juggler user in multi-user environments.\n\n"
       "Each user has a system-assigned ID as well as a string name from\n"
       "the 'user' config element that created the user.  These IDs can be\n"
       "used to identify a user at set points in the execution of a VR\n"
       "Juggler application object where user information is given.\n\n"
       "The system-assigned ID number can also be used as an index into a\n"
       "program array (or other data structure) that stores user-specific\n"
       "data such as navigation matrices or input devices."
       ,
       no_init
      )
      .def("create", &vrj::User::create,
           "create() -> vrj.User\n"
           "Creates a vrj.User instance."
      )
      .def("getId", &vrj::User::getId,
           "getId() -> int\n"
           "Returns the ID of the user in the system.\n\n"
           "Post-conditions:\n"
           "-1 implies that the user has not been configured yet."
      )
      .def("getName", &vrj::User::getName,
           return_value_policy<copy_const_reference>(),
           "getName() -> string object\n"
           "Returns the name of thss user object."
      )
      .def("getHeadPosProxy", &vrj::User::getHeadPosProxy
      )
      .def("getHeadUpdateTime", &vrj::User::getHeadUpdateTime,
           "getHeadUpdateTime() -> vpr.Interval object\n"
           "Returns the time stamp of the last head tracker update."
      )
      .def("getInterocularDistance", &vrj::User::getInterocularDistance,
           "getInterocularDistance() -> float\n"
           "Gets the eye separation."
      )
      .staticmethod("create")
   ;
}
