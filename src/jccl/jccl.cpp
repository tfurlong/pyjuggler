// PyJuggler is (C) Copyright 2002-2007 by Patrick Hartling
// Distributed under the GNU Lesser General Public License 2.1.  (See
// accompanying file COPYING.txt or http://www.gnu.org/copyleft/lesser.txt)

// Include =====================================================================
#include <boost/python.hpp>
#include <jccl/Util/Version.h>

// Exports =====================================================================
void _Export_ConfigDefinition();
void _Export_ConfigElement();
void _Export_ConfigElementHandler();
void _Export_ConfigManager();
void _Export_PropertyDefinition();
void _Export_VarType();

// Module ======================================================================
BOOST_PYTHON_MODULE(jccl)
{
   boost::python::scope().attr("__doc__") =
      "PyJuggler.jccl is an extension module written in Boost.Python that\n"
      "exposes some C++ classes from the JCCL library.  The exposed classes\n"
      "are those that tend to be of the most value for writing VR Juggler\n"
      "application objects.\n\n"
      "Refer to the JCCL and VR Juggler 2.0 C++ documentation for general\n"
      "usage details:\n"
      "   http://www.vrjuggler.org/jccl/docs.php\n"
      "   http://www.vrjuggler.org/vrjuggler/docs.php"
   ;
   boost::python::def("getVersionString", jccl::getVersionString,
                      "Returns the full JCCL version number as a string in\n"
                      "the form 'v<major>.<minor>.<patch>-<build> [...]\n"
                      "The regular expression to extract the version number\n"
                      "components is r'^v(\\d+)\\.(\\d+)\\.(\\d+)-(\\d+)'");
   boost::python::def("getVersionNumber", jccl::getVersionNumber,
                      "Returns the 9-digit JCCL version integer. This form\n"
                      "provides three digits for each of the major, minor,\n"
                      "and patch numbers with no leading zeros");

   _Export_ConfigDefinition();
   _Export_ConfigElement();
   _Export_ConfigElementHandler();
   _Export_ConfigManager();
   _Export_PropertyDefinition();
   _Export_VarType();
}
