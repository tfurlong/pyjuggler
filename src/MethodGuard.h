/*************** <auto-copyright.pl BEGIN do not edit this line> **************
 *
 * PyJuggler is (C) Copyright 2002, 2003 by Patrick Hartling
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 *
 * -----------------------------------------------------------------
 * File:          $RCSfile$
 * Date modified: $Date$
 * Version:       $Revision$
 * -----------------------------------------------------------------
 *
 *************** <auto-copyright.pl END do not edit this line> ***************/

#ifndef _PYJUGGLER_METHOD_GUARD_H_
#define _PYJUGGLER_METHOD_GUARD_H_

#include <Python.h>

#include <vpr/vpr.h>
#include <vpr/Thread/TSObjectProxy.h>


namespace PyJuggler
{

/**
 * Helper class for dealing with the ins and outs of multi-threaded C++ code
 * calling into Python code.  This class is designed for a very specific
 * purpose: an instance of PyJuggler::MethodGuard::State should exist as a
 * member variable of a class with virtual methods that pass through calls to
 * corresponding Python methods.  For each method where
 * boost::python::call_method<T>() may be invoked by a thread other than the
 * thread where the Python interpreter was started, an instance of
 * PyJuggler::MethodGuard should be created on the stack before
 * boost::python::call_method<T>() is invoked.  For those classes where it is
 * possible for recursive calls to Python code to be made from the same thread,
 * this class handles the locking and unlocking.
 */
class MethodGuard
{
private:
   /**
    * One instance of this class should exist for each thread that may call
    * through to a Python method.  It is recommended that some sort of
    * thread-specific data mechanism be used to manage which instance is
    * given to the PyJuggler::MethodGuard constructor for a given thread.
    */
   struct State
   {
      State();

      ~State();

      bool           gilLocked;
      PyThreadState* pyState;
   };

public:
   /**
    * Acquires the Python Global Interpreter Lock (GIL) for the invoking
    * thread.  If that thread already holds the GIL, then no action is taken.
    */
   MethodGuard();

   /**
    * Releases the Python Global Interpreter Lock (GIL) for the invoking thread
    * iff that thread holds the GIL and the constructor acquired the GIL.
    */
   ~MethodGuard();

private:
   /**
    * Thread-specific data structure for handling the Python thread data
    * information.  This is used to ensure that a single thread never locks
    * the GIL twice.
    */
   static vpr::TSObjectProxy<State> mState;

   /** Prevent copying. */
   MethodGuard(const MethodGuard& o)
   {
      /* Do nothing. */ ;
   }

   void operator=(const MethodGuard& o)
   {
      /* Do nothing. */ ;
   }

   bool   mMyLock;
};

} // End of PyJuggler namespace


#endif /* _PYJUGGLER_METHOD_GUARD_H_ */
