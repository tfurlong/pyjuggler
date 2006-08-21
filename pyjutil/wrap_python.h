// PyJuggler is (C) Copyright 2002-2006 by Patrick Hartling
// Distributed under the GNU Lesser General Public License 2.1.  (See
// accompanying file COPYING.txt or http://www.gnu.org/copyleft/lesser.txt)
//
// Based on: boost/python/detail/wrap_python.hpp from Boost.Python libary.
//
// NOTE: If you are using Boost.Python just go ahead and include the file from
// Boost.python before including anything from this library.

//  This file serves as a wrapper around <Python.h> which allows it to be
//  compiled with GCC 2.95.2 under Win32 and which disables the default MSVC
//  behavior so that a program may be compiled in debug mode without requiring a
//  special debugging build of the Python library.


//  To use the Python debugging library, #define PYJUTIL_DEBUG_PYTHON on the
//  compiler command-line.


#ifdef _DEBUG
# ifndef PYJUTIL_DEBUG_PYTHON
#  ifdef _MSC_VER  
    // VC8.0 will complain if system headers are #included both with
    // and without _DEBUG defined, so we have to #include all the
    // system headers used by pyconfig.h right here.
#   include <stddef.h>
#   include <stdarg.h>
#   include <stdio.h>
#   include <stdlib.h>
#   include <assert.h>
#   include <errno.h>
#   include <ctype.h>
#   include <wchar.h>
#   include <basetsd.h>
#   include <io.h>
#   include <limits.h>
#   include <float.h>
#   include <string.h>
#   include <math.h>
#   include <time.h>
#  endif
#  undef _DEBUG // Don't let Python force the debug library just because we're debugging.
#  define DEBUG_UNDEFINED_FROM_WRAP_PYTHON_H
# endif
#endif

# include <pyconfig.h>

//
// Get ahold of Python's version number
//
#include <patchlevel.h>
#include <Python.h>

#ifdef DEBUG_UNDEFINED_FROM_WRAP_PYTHON_H
# undef DEBUG_UNDEFINED_FROM_WRAP_PYTHON_H
# define _DEBUG
#endif

#if _MSC_VER
# pragma warning(disable:4786)
#endif


