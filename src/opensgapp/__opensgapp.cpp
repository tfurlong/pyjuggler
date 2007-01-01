// PyJuggler is (C) Copyright 2002-2007 by Patrick Hartling
// Distributed under the GNU Lesser General Public License 2.1.  (See
// accompanying file COPYING.txt or http://www.gnu.org/copyleft/lesser.txt)

// Include =====================================================================
#include <boost/python.hpp>

// Exports =====================================================================
void _Export_OpenSGApp();

// Module ======================================================================
BOOST_PYTHON_MODULE(__opensgapp)
{
   boost::python::scope().attr("__doc__") =
      "PyJuggler.__opensgapp is an extension module written in Boost.Python\n"
      "that exposes the C++ class vrj::OpenSGApp. Upon successful loading,\n"
      "the symbols of this module are imported into the PyJuggler.vrj\n"
      "namespace for use in the authoring of VR Juggler application\n"
      "objects based on OpenSG. To accomplish this, PyOpenSG must be used\n"
      "together with vrj.OpenSGApp.\n\n"
      "Refer to the VR Juggler 2.0 C++ documentation for general usage\n"
      "details:\n"
      "   http://www.vrjuggler.org/vrjuggler/docs.php"
   ;

   _Export_OpenSGApp();
}
