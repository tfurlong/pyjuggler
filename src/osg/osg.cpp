// PyJuggler is (C) Copyright 2002-2010 by Patrick Hartling
// Distributed under the GNU Lesser General Public License 2.1.  (See
// accompanying file COPYING.txt or http://www.gnu.org/copyleft/lesser.txt)

// Include =====================================================================
#include <boost/python.hpp>

// Exports =====================================================================
void _Export_App();

// Module ======================================================================
BOOST_PYTHON_MODULE(osg)
{
   boost::python::scope().attr("__doc__") =
      "PyJuggler.vrj.osg is an extension module written in Boost.Python that\n"
      "exposes the C++ class vrj::osg::App for use in the authoring of\n"
      "VR Juggler application objects based on Open Scene Graph.  To\n"
      "accomplish this, PyOSG must be used together with vrj.OsgApp.\n\n"
      "Refer to the VR Juggler 3.0 C++ documentation for general usage\n"
      "details:\n"
      "   http://www.vrjuggler.org/vrjuggler/docs.php"
   ;

   _Export_App();
}
