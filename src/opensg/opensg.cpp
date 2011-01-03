// PyJuggler is (C) Copyright 2002-2011 by Patrick Hartling
// Distributed under the GNU Lesser General Public License 2.1.  (See
// accompanying file COPYING.txt or http://www.gnu.org/copyleft/lesser.txt)

// Include =====================================================================
#include <boost/python.hpp>

// Exports =====================================================================
void _Export_App();

// Module ======================================================================
BOOST_PYTHON_MODULE(opensg)
{
   boost::python::scope().attr("__doc__") =
      "PyJuggler.vrj.opensg is an extension module written in Boost.Python\n"
      "that exposes the C++ class vrj::opensg::App for use in the authoring\n"
      "of VR Juggler application objects based on OpenSG. To accomplish\n"
      "this, PyOpenSG must be used together with vrj.opensg.App.\n\n"
      "Refer to the VR Juggler 3.0 C++ documentation for general usage\n"
      "details:\n"
      "   http://www.vrjuggler.org/vrjuggler/docs.php"
   ;

   _Export_App();
}
