// PyJuggler is (C) Copyright 2002-2012 by Patrick Hartling
// Distributed under the GNU Lesser General Public License 2.1.  (See
// accompanying file COPYING.txt or http://www.gnu.org/copyleft/lesser.txt)

// Include =====================================================================
#include <boost/python.hpp>

// Exports =====================================================================
void _Export_App();
void _Export_ContextData();
void _Export_DrawManager();

// Module ======================================================================
BOOST_PYTHON_MODULE(__opengl)
{
   boost::python::scope().attr("__doc__") =
      "PyJuggler.vrj.opengl is an extension module written in Boost.Python\n"
      "that exposes the C++ classes from the vrj::opengl namespace.  To use\n"
      "OpenGL with VR Juggler in Python, PyOpenGL must be used together with\n"
      "vrj.opengl.App.\n\n"
      "Refer to the VR Juggler 3.0 C++ documentation for general usage\n"
      "details:\n"
      "   http://www.vrjuggler.org/vrjuggler/docs.php"
   ;

   _Export_App();
   _Export_ContextData();
   _Export_DrawManager();
}
