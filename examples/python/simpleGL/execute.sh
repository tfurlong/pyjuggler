#!/bin/bash
# If PYTHONPATH hasn't been set, you'll need to set it here to point to where
# PyJuggler is located.
export PYTHONPATH=~/usr/lib64:~/usr/pythonlibs

# Set the library path so that any required libraries can be found at runtime.
# Note that the path to PyJuggler itself has to be there due to pyjutil.
export LD_LIBRARY_PATH=~/usr/lib64:~/usr/pythonlibs/PyJuggler

# Run your application with an argument pointing to the VRJuggler config
# file you would like to use.
./simpleGL.py --vrjmaster --jconf ~/smb-shared/tools/vrjuggler-config/desktop/desktop-cavesim.jconf
# ./simpleGL.py --help
