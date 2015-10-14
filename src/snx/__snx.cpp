// PyJuggler is (C) Copyright 2002-2012 by Patrick Hartling
// Distributed under the GNU Lesser General Public License 2.1.  (See
// accompanying file COPYING.txt or http://www.gnu.org/copyleft/lesser.txt)

// Include =====================================================================
#include <boost/python.hpp>
#include <snx/Util/Version.h>

// Exports =====================================================================
void _Export_sonix();
void _Export_SoundAPIInfo();
void _Export_SoundHandle();
void _Export_SoundImplementation();
void _Export_SoundInfo();

// Module ======================================================================
BOOST_PYTHON_MODULE(__snx)
{
   boost::python::scope().attr("__doc__") =
      "PyJuggler.snx is an extension module written in Boost.Python that\n"
      "exposes some C++ classes from the Sonix library.  The exposed classes\n"
      "are those that tend to be of the most value for writing VR Juggler\n"
      "application objects.\n\n"
      "Refer to the Sonix and VR Juggler 2.0 C++ documentation for general\n"
      "usage details:\n"
      "   http://www.vrjuggler.org/sonix/docs.php\n"
      "   http://www.vrjuggler.org/vrjuggler/docs.php"
   ;
   boost::python::def("getVersionString", snx::getVersionString,
                      "Returns the full Sonix version number as a string in\n"
                      "the form 'v<major>.<minor>.<patch>-<build> [...]\n"
                      "The regular expression to extract the version number\n"
                      "components is r'^v(\\d+)\\.(\\d+)\\.(\\d+)-(\\d+)'");
   boost::python::def("getVersionNumber", snx::getVersionNumber,
                      "Returns the 9-digit Sonix version integer. This form\n"
                      "provides three digits for each of the major, minor,\n"
                      "and patch numbers with no leading zeros");

   _Export_sonix();
   _Export_SoundAPIInfo();
   _Export_SoundHandle();
   _Export_SoundImplementation();
   _Export_SoundInfo();
}
