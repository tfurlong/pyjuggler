// PyJuggler is (C) Copyright 2002-2012 by Patrick Hartling
// Distributed under the GNU Lesser General Public License 2.1.  (See
// accompanying file COPYING.txt or http://www.gnu.org/copyleft/lesser.txt)

#ifndef _PYJUGGLER_INTERPRETER_GUARD_H_
#define _PYJUGGLER_INTERPRETER_GUARD_H_

#include "wrap_python.h"

#include <vpr/vpr.h>
#include <vpr/Thread/TSObjectProxy.h>

// DLL-related macros.  These are based on the macros used by NSPR.
#ifdef VPR_OS_Win32

#   if defined(__GNUC__)
#       undef _declspec
#       define _declspec(x) __declspec(x)
#   endif

#   define PYJUTIL_EXPORT(__type)      _declspec(dllexport) __type
#   define PYJUTIL_EXPORT_CLASS        _declspec(dllexport)
#   define PYJUTIL_EXPORT_DATA(__type) _declspec(dllexport) __type
#   define PYJUTIL_IMPORT(__type)      _declspec(dllimport) __type
#   define PYJUTIL_IMPORT_DATA(__type) _declspec(dllimport) __type
#   define PYJUTIL_IMPORT_CLASS        _declspec(dllimport)

#   define PYJUTIL_EXTERN(__type)         extern _declspec(dllexport) __type
#   define PYJUTIL_IMPLEMENT(__type)      _declspec(dllexport) __type
#   define PYJUTIL_EXTERN_DATA(__type)    extern _declspec(dllexport) __type
#   define PYJUTIL_IMPLEMENT_DATA(__type) _declspec(dllexport) __type

#   define PYJUTIL_CALLBACK
#   define PYJUTIL_CALLBACK_DECL
#   define PYJUTIL_STATIC_CALLBACK(__x) static __x

#else

#   define PYJUTIL_EXPORT(__type)      __type
#   define PYJUTIL_EXPORT_CLASS
#   define PYJUTIL_EXPORT_DATA(__type) __type
#   define PYJUTIL_IMPORT(__type)      __type
#   define PYJUTIL_IMPORT_DATA(__type) __type
#   define PYJUTIL_IMPORT_CLASS

#   define PYJUTIL_EXTERN(__type)         extern __type
#   define PYJUTIL_IMPLEMENT(__type)      __type
#   define PYJUTIL_EXTERN_DATA(__type)    extern __type
#   define PYJUTIL_IMPLEMENT_DATA(__type) __type

#   define PYJUTIL_CALLBACK
#   define PYJUTIL_CALLBACK_DECL
#   define PYJUTIL_STATIC_CALLBACK(__x) static __x

#endif  /* VPR_OS_Win32 */

#ifdef _PYJUTIL_BUILD_
#   define PYJUTIL_API(__type)      PYJUTIL_EXPORT(__type)
#   define PYJUTIL_CLASS_API        PYJUTIL_EXPORT_CLASS
#   define PYJUTIL_DATA_API(__type) PYJUTIL_EXPORT_DATA(__type)
#else
#   define PYJUTIL_API(__type)      PYJUTIL_IMPORT(__type)
#   define PYJUTIL_CLASS_API        PYJUTIL_IMPORT_CLASS
#   define PYJUTIL_DATA_API(__type) PYJUTIL_IMPORT_DATA(__type)
#endif

// Python 2.3 has handy functions for managing GIL state. Boost.Python still
// supports Python 2.2, so we have this for backwards compatibility with
// Python 2.2.
#if PY_MAJOR_VERSION == 2 && PY_MINOR_VERSION < 3       /* Python 2.2 case */
#  define HAVE_PY_GIL_STATE 0
#else                                                   /* Python 2.3+ case */
#  define HAVE_PY_GIL_STATE 1
#endif

namespace PyJuggler
{

/**
 * Helper class for dealing with the ins and outs of multi-threaded C++ code
 * calling into the Python interpreter.  This class is designed for a very
 * specific purpose: an instance of PyJuggler::InterpreterGuard should exist
 * on the stack prior to any calls into the Python interpreter via Python/C
 * (or Boost.Python) when the calling thread is different from the thread
 * that started the interpreter.  Recursive locks (of a fashion) are allowed
 * by this class.  More specifically, it will not allow the same thread to
 * acquire the Global Interpreter Lock twice and in so doing prevents
 * deadlock.
 */
class PYJUTIL_CLASS_API InterpreterGuard
{
private:
   /**
    * One instance of this class should exist for each thread that may call
    * through to the Python interpreter.  A thread-specific data mechanism is
    * needed to manage which instance is used for a given thread.
    */
   struct State
   {
      State();

      ~State();

#if defined(HAVE_PY_GIL_STATE)
      PyGILState_STATE gilState; /**< The Pythoon GIL state for this thread. */
#else
      bool             gilLocked; /**< Indicates that the GIL is held. */
      PyThreadState*   pyState;   /**< The Python state info for this thread. */
#endif
   };

public:
   /**
    * Acquires the Python Global Interpreter Lock (GIL) for the invoking
    * thread.  If that thread already holds the GIL, then no action is taken.
    */
   InterpreterGuard();

   /**
    * Releases the Python Global Interpreter Lock (GIL) for the invoking thread
    * iff that thread holds the GIL and the constructor acquired the GIL.
    */
   ~InterpreterGuard();

private:
   /**
    * Thread-specific data structure for handling the Python thread data
    * information.  This is used to ensure that a single thread never locks
    * the GIL twice.
    */
#if defined(HAVE_PY_GIL_STATE)
   State mState;
#else
   static vpr::TSObjectProxy<State> mState;
#endif

   /** Prevent copying. */
   InterpreterGuard(const InterpreterGuard&)
   {
      /* Do nothing. */ ;
   }

   void operator=(const InterpreterGuard&)
   {
      /* Do nothing. */ ;
   }

#if ! HAVE_PY_GIL_STATE
   /** Indicates that this object was the one that acquired the GIL. */
   bool mMyLock;
#endif
};

} // End of PyJuggler namespace


#endif /* _PYJUGGLER_INTERPRETER_GUARD_H_ */
