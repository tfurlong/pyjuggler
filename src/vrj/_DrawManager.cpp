// PyJuggler is (C) Copyright 2002-2008 by Patrick Hartling
// Distributed under the GNU Lesser General Public License 2.1.  (See
// accompanying file COPYING.txt or http://www.gnu.org/copyleft/lesser.txt)

// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <vrj/Draw/DrawManager.h>
#include <vrj/Kernel/App.h>
#include <pyjutil/InterpreterGuard.h>
#include <pyjutil/Debug.h>

// Using =======================================================================
using namespace boost::python;

// Declarations ================================================================
namespace pyj
{

struct vrj_DrawManager_Wrapper
   : vrj::DrawManager
   , wrapper<vrj::DrawManager>
{
   virtual ~vrj_DrawManager_Wrapper()
   {
      /* Do nothing. */ ;
   }

   void draw()
   {
      vpr::DebugOutputGuard og(
         pyjDBG_CXX, vprDBG_VERB_LVL,
         "vrj_DrawManager_Wrapper::draw()\n",
         "vrj_DrawManager_Wrapper::draw() done.\n"
      );
      PyJuggler::InterpreterGuard guard;

      try
      {
         if ( override draw = this->get_override("draw") )
         {
            draw();
         }
         else
         {
            vrj::DrawManager::draw();
         }
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }
   }

   // void default_draw()
   // {
   //    vrj::DrawManager::draw();
   // }

   void sync()
   {
      vpr::DebugOutputGuard og(
         pyjDBG_CXX, vprDBG_VERB_LVL,
         "vrj_DrawManager_Wrapper::sync()\n",
         "vrj_DrawManager_Wrapper::sync() done.\n"
      );
      PyJuggler::InterpreterGuard guard;

      try
      {
         if ( override sync = this->get_override("sync") )
         {
            sync();
         }
         else
         {
            vrj::DrawManager::sync();
         }
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }
   }

   // void default_sync()
   // {
   //    vrj::DrawManager::sync();
   // }

   void initAPI()
   {
      vpr::DebugOutputGuard og(
         pyjDBG_CXX, vprDBG_VERB_LVL,
         "vrj_DrawManager_Wrapper::initAPI()\n",
         "vrj_DrawManager_Wrapper::initAPI() done.\n"
      );
      PyJuggler::InterpreterGuard guard;

      try
      {
         if ( override initAPI = this->get_override("initAPI") )
         {
            initAPI();
         }
         else
         {
            vrj::DrawManager::initAPI();
         }
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }
   }

   // void default_initAPI()
   // {
   //    vrj::DrawManager::initAPI();
   // }

   void addDisplay(vrj::DisplayPtr display)
   {
      vpr::DebugOutputGuard og(
         pyjDBG_CXX, vprDBG_VERB_LVL,
         "vrj_DrawManager_Wrapper::addDisplay()\n",
         "vrj_DrawManager_Wrapper::addDisplay() done.\n"
      );
      PyJuggler::InterpreterGuard guard;

      try
      {
         if ( override addDisplay = this->get_override("addDisplay") )
         {
            addDisplay(display);
         }
         else
         {
            vrj::DrawManager::addDisplay(display);
         }
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }
   }

   // void default_addDisplay(vrj::DisplayPtr display)
   // {
   //    vrj::DrawManager::addDisplay(display);
   // }

   void removeDisplay(vrj::DisplayPtr display)
   {
      vpr::DebugOutputGuard og(
         pyjDBG_CXX, vprDBG_VERB_LVL,
         "vrj_DrawManager_Wrapper::removeDisplay()\n",
         "vrj_DrawManager_Wrapper::removeDisplay() done.\n"
      );
      PyJuggler::InterpreterGuard guard;

      try
      {
         if ( override removeDisplay = this->get_override("removeDisplay") )
         {
            removeDisplay(display);
         }
         else
         {
            vrj::DrawManager::removeDisplay(display);
         }
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }
   }

   // void default_removeDisplay(vrj::DisplayPtr display)
   // {
   //    vrj::DrawManager::removeDisplay(display);
   // }

   void closeAPI()
   {
      vpr::DebugOutputGuard og(
         pyjDBG_CXX, vprDBG_VERB_LVL,
         "vrj_DrawManager_Wrapper::closeAPI()\n",
         "vrj_DrawManager_Wrapper::closeAPI() done.\n"
      );
      PyJuggler::InterpreterGuard guard;

      try
      {
         if ( override closeAPI = this->get_override("closeAPI") )
         {
            closeAPI();
         }
         else
         {
            vrj::DrawManager::closeAPI();
         }
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }
   }

   // void default_closeAPI()
   // {
   //    vrj::DrawManager::closeAPI();
   // }

   void setApp(vrj::App* app)
   {
      vpr::DebugOutputGuard og(
         pyjDBG_CXX, vprDBG_VERB_LVL,
         "vrj_DrawManager_Wrapper::setApp()\n",
         "vrj_DrawManager_Wrapper::setApp() done.\n"
      );
      PyJuggler::InterpreterGuard guard;

      try
      {
         if ( override setApp = this->get_override("setApp") )
         {
            setApp(app);
         }
         else
         {
            vrj::DrawManager::setApp(app);
         }
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }
   }

   // void default_setApp(vrj::App* app)
   // {
   //    vrj::DrawManager::setApp(app);
   // }
};

}  // namespace pyj

void _Export_DrawManager()
{
   class_<pyj::vrj_DrawManager_Wrapper, boost::noncopyable>(
      "DrawManager",
      "Concrete Singleton Class for OpenGL drawing.  Responsible for all\n"
      "OpenGL-based rendering.\n\n"
      "vrj::DrawManager is an active object.  It manages OpenGL\n"
      "pipes and windows.  In addition, it triggers rendering, swapping, and\n"
      "syncing of the windows under its control.\n\n"
      "All access to the OpenGL rendering structures has to happen from the\n"
      "control thread or in the case of context sensitive functions, from\n"
      "the control thread of the managed pipes.  Because of this, the object\n"
      "uses queues to hold new windows.",
      no_init
      )
      .def("draw", &vrj::DrawManager::draw,
           &pyj::vrj_DrawManager_Wrapper::draw,
           "draw()\n"
           "Enable a frame to be drawn."
      )
      .def("sync", &vrj::DrawManager::sync,
           &pyj::vrj_DrawManager_Wrapper::sync,
           "sync()\n"
           "Blocks until the end of the frame."
      )
      .def("initAPI", &vrj::DrawManager::initAPI,
           &pyj::vrj_DrawManager_Wrapper::initAPI,
           "initAPI()\n"
           "Initializes the drawing API (if not already running)."
      )
      .def("addDisplay", &vrj::DrawManager::addDisplay,
           &pyj::vrj_DrawManager_Wrapper::addDisplay,
           "addDisplay(display)\n"
           "Callback when display is added to Display Manager.\n"
           "Arguments:\n"
           "display -- A vrj.Display instance."
      )
      .def("removeDisplay", &vrj::DrawManager::removeDisplay,
           &pyj::vrj_DrawManager_Wrapper::removeDisplay,
           "removeDisplay(display)\n"
           "Callback when display is removed from Display Manager.\n"
           "Arguments:\n"
           "display -- A vrj.Display instance."
      )
      .def("closeAPI", &vrj::DrawManager::closeAPI,
           &pyj::vrj_DrawManager_Wrapper::closeAPI,
           "closeAPI()\n"
           "Initializes the drawing API (if not already running)."
      )
      .def("setApp", &vrj::DrawManager::setApp,
           &pyj::vrj_DrawManager_Wrapper::setApp,
           "setApp(app)\n"
           "Sets the application with which this Draw Manager will interact.\n"
           "Arguments:\n"
           "app -- A vrj.App instance."
      )
      // .def("getApp", &vrj::DrawManager::getApp,
      //      return_internal_reference<>(),
      //      "getApp() -> vrj.App object\n"
      //      "Returns the app we are rendering."
      // )
      // .def("instance", &vrj::DrawManager::instance,
      //      return_value_policy<reference_existing_object>(),
      //      "vrj.DrawManager.instance() -> vrj.DrawManager object\n"
      //      "Returns the singleton VR Juggler OpenGL Draw Manager reference."
      // )
      // .staticmethod("instance")
   ;
}
