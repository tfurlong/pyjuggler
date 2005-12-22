// PyJuggler is (C) Copyright 2002-2005 by Patrick Hartling
// Distributed under the GNU Lesser General Public License 2.1.  (See
// accompanying file COPYING.txt or http://www.gnu.org/copyleft/lesser.txt)

// File:          $RCSfile$
// Date modified: $Date$
// Version:       $Revision$

#include <stdlib.h>

#include <vpr/vpr.h>
#include <vpr/Thread/Thread.h>
#include <vpr/Util/Debug.h>

#include "Debug.h"
#include "InterpreterGuard.h"


namespace PyJuggler
{

vpr::TSObjectProxy<InterpreterGuard::State> InterpreterGuard::mState;

InterpreterGuard::State::State()
   : gilLocked(false)
#if ! HAVE_PY_GIL_STATE
   , pyState(NULL)
#endif
{
#if ! HAVE_PY_GIL_STATE
   vprDEBUG(pyjDBG_CXX, vprDBG_HVERB_LVL)
      << "InterpreterGuard::State constructor -- this->pyState: "
      << std::hex << this->pyState << std::dec << std::endl
      << vprDEBUG_FLUSH;
#endif
}

InterpreterGuard::State::~State()
{
#if ! HAVE_PY_GIL_STATE
   if ( NULL != pyState )
   {
      PyEval_AcquireThread(pyState);
      PyInterpreterState_Clear(pyState->interp);
      PyEval_ReleaseThread(pyState);
      PyInterpreterState_Delete(pyState->interp);
      PyThreadState_Delete(pyState);
      pyState = NULL;
   }
#endif
}

InterpreterGuard::InterpreterGuard()
   : mMyLock(false)
{
#if ! HAVE_PY_GIL_STATE
   if ( NULL == mState->pyState )
   {
      vprDEBUG(pyjDBG_CXX, vprDBG_VERB_LVL)
         << "Getting new thread state data\n" << vprDEBUG_FLUSH;

      // Use an existing interpreter object for creating the new thread
      // state to get proper sharing of information between threads.
      // XXX: PyInterpreterState_Head() is documented as only for use by
      // advanced debuggers.  There may be a better way to do this.
      mState->pyState = PyThreadState_New(PyInterpreterState_Head());
   }

   vprDEBUG(pyjDBG_CXX, vprDBG_HVERB_LVL)
      << "mState->pyState: " << std::hex << mState->pyState << std::dec
      << std::endl << vprDEBUG_FLUSH;
#endif

   if ( ! mState->gilLocked )
   {
      vprDEBUG(pyjDBG_CXX, vprDBG_VERB_LVL)
         << std::hex << this << std::dec << " locking\n" << vprDEBUG_FLUSH;

      // Lock the GIL.
#if HAVE_PY_GIL_STATE
      mState->gilState = PyGILState_Ensure();
#else
      PyEval_AcquireThread(mState->pyState);
#endif

      vprDEBUG(pyjDBG_CXX, vprDBG_VERB_LVL)
         << std::hex << this << std::dec << " locked\n" << vprDEBUG_FLUSH;

      mState->gilLocked = true;
      mMyLock           = true;
   }
}

InterpreterGuard::~InterpreterGuard()
{
   if ( mMyLock )
   {
      vprASSERT(mState->gilLocked && "GIL is not held, but I thought it was.");
      vprDEBUG(pyjDBG_CXX, vprDBG_VERB_LVL)
         << std::hex << this << std::dec << " unlocking\n" << vprDEBUG_FLUSH;

      // Unlock the GIL.
#if HAVE_PY_GIL_STATE
      PyGILState_Release(mState->gilState);
#else
      PyEval_ReleaseThread(mState->pyState);
#endif

      vprDEBUG(pyjDBG_CXX, vprDBG_VERB_LVL)
         << std::hex << this << std::dec << " unlocked\n" << vprDEBUG_FLUSH;

      mState->gilLocked = false;
   }
}

} // End of PyJuggler namespace
