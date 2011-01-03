// PyJuggler is (C) Copyright 2002-2011 by Patrick Hartling
// Distributed under the GNU Lesser General Public License 2.1.  (See
// accompanying file COPYING.txt or http://www.gnu.org/copyleft/lesser.txt)

// Include =====================================================================
#include <boost/python.hpp>

// Exports =====================================================================
void _Export_App();

// Module ======================================================================
BOOST_PYTHON_MODULE(direct3d)
{
   boost::python::scope().attr("__doc__") =
      "PyJuggler.vrj.direct3d is an extension module written in Boost.Python\n"
      "that exposes the C++ classes from the vrj::direct3d namespace.  To\n"
      "use Direct3D with VR Juggler in Python, PyOpenGL must be used together\n"
      "with vrj.direct3d.App.\n\n"
      "Refer to the VR Juggler 3.0 C++ documentation for general usage\n"
      "details:\n"
      "   http://www.vrjuggler.org/vrjuggler/docs.php"
   ;

   _Export_App();
}
