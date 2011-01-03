# PyJuggler is (C) Copyright 2002-2011 by Patrick Hartling
# Distributed under the GNU Lesser General Public License 2.1.  (See
# accompanying file COPYING.txt or http://www.gnu.org/copyleft/lesser.txt)

import string
__all__     = ["vrj", "cluster", "gadget", "snx", "jccl", "vpr"]
__build__   = 1
__version__ = '1.3.10.%d' % __build__
__date__    = string.join(string.split('$Date$')[1:3], ' ')
__author__  = 'Patrick Hartling <patrick.hartling@priority5.com>'
__doc__     = '''This is PyJuggler.  For information regarding PyJuggler see:
    http://www.vrjuggler.org/pyjuggler/

For information on VR Juggler see:
    http://www.vrjuggler.org'''
del string
