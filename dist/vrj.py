# PyJuggler is (C) Copyright 2002-2007 by Patrick Hartling
# Distributed under the GNU Lesser General Public License 2.1.  (See
# accompanying file COPYING.txt or http://www.gnu.org/copyleft/lesser.txt)

# Import everything from __vrj into our namespace.
from __vrj import *

# Attempt to import everything from __osgapp into our namespace.  If it fails,
# then Open Scene Graph is not available for use.  For people who don't want
# to use vrj.OsgApp, this is fine.  For those who do, they have to have
# OSG and PyOSG installed.
try:
   from __osgapp import *
except:
   pass

# Attempt to import everything from __opensgapp into our namespace. If it
# fails, then OpenSG is not available for use. For people who don't want to
# use vrj.OpenSGApp, this is fine. For those who do, they have to have OpenSG
# and PyOpenSG installed.
try:
   from __opensgapp import *
except:
   pass

__doc__ = '''PyJuggler.vrj is a module that imports the symbols from
PyJuggler.__vrj, PyJuggler.__osgapp, and PyJuggler.__opensgapp into its
namespace. PyJuggler.__osgapp and PyJuggler.__opensgapp are optional modules,
and importing one or both may fail if the module was not compiled or if the
Open Scene Graph and/or OpenSG libraries are not available at run time.

Refer to the PyJuggler.__vrj, PyJuggler.__osgapp, and PyJuggler.__opensgapp
modules for class documentation.
'''
