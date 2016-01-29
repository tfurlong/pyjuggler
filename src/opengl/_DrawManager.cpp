// PyJuggler is (C) Copyright 2002-2008 by Patrick Hartling
// Distributed under the GNU Lesser General Public License 2.1.  (See
// accompanying file COPYING.txt or http://www.gnu.org/copyleft/lesser.txt)

// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <vrj/Draw/OpenGL/DrawManager.h>
#include <vrj/Draw/OpenGL/App.h>
#include <pyjutil/InterpreterGuard.h>
#include <pyjutil/Debug.h>

// Using =======================================================================
using namespace boost::python;

// Declarations ================================================================
namespace pyj
{

struct vrj_opengl_DrawManager_Wrapper
   : vrj::opengl::DrawManager
   , wrapper<vrj::opengl::DrawManager>
{
   virtual ~vrj_opengl_DrawManager_Wrapper()
   {
      /* Do nothing. */ ;
   }

   void start()
   {
      vpr::DebugOutputGuard og(
         pyjDBG_CXX, vprDBG_VERB_LVL,
         "vrj_opengl_DrawManager_Wrapper::start()\n",
         "vrj_opengl_DrawManager_Wrapper::start() done.\n"
      );
      PyJuggler::InterpreterGuard guard;

      try
      {
         if ( override start = this->get_override("start") )
         {
            start();
         }
         else
         {
            vrj::opengl::DrawManager::start();
         }
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }
   }

   void default_start()
   {
      vrj::opengl::DrawManager::start();
   }

   void draw()
   {
      vpr::DebugOutputGuard og(
         pyjDBG_CXX, vprDBG_VERB_LVL,
         "vrj_opengl_DrawManager_Wrapper::draw()\n",
         "vrj_opengl_DrawManager_Wrapper::draw() done.\n"
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
            vrj::opengl::DrawManager::draw();
         }
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }
   }

   void default_draw()
   {
      vrj::opengl::DrawManager::draw();
   }

   void sync()
   {
      vpr::DebugOutputGuard og(
         pyjDBG_CXX, vprDBG_VERB_LVL,
         "vrj_opengl_DrawManager_Wrapper::sync()\n",
         "vrj_opengl_DrawManager_Wrapper::sync() done.\n"
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
            vrj::opengl::DrawManager::sync();
         }
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }
   }

   void default_sync()
   {
      vrj::opengl::DrawManager::sync();
   }

   void initAPI()
   {
      vpr::DebugOutputGuard og(
         pyjDBG_CXX, vprDBG_VERB_LVL,
         "vrj_opengl_DrawManager_Wrapper::initAPI()\n",
         "vrj_opengl_DrawManager_Wrapper::initAPI() done.\n"
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
            vrj::opengl::DrawManager::initAPI();
         }
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }
   }

   void default_initAPI()
   {
      vrj::opengl::DrawManager::initAPI();
   }

   void addDisplay(vrj::DisplayPtr display)
   {
      vpr::DebugOutputGuard og(
         pyjDBG_CXX, vprDBG_VERB_LVL,
         "vrj_opengl_DrawManager_Wrapper::addDisplay()\n",
         "vrj_opengl_DrawManager_Wrapper::addDisplay() done.\n"
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
            vrj::opengl::DrawManager::addDisplay(display);
         }
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }
   }

   void default_addDisplay(vrj::DisplayPtr display)
   {
      vrj::opengl::DrawManager::addDisplay(display);
   }

   void removeDisplay(vrj::DisplayPtr display)
   {
      vpr::DebugOutputGuard og(
         pyjDBG_CXX, vprDBG_VERB_LVL,
         "vrj_opengl_DrawManager_Wrapper::removeDisplay()\n",
         "vrj_opengl_DrawManager_Wrapper::removeDisplay() done.\n"
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
            vrj::opengl::DrawManager::removeDisplay(display);
         }
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }
   }

   void default_removeDisplay(vrj::DisplayPtr display)
   {
      vrj::opengl::DrawManager::removeDisplay(display);
   }

   void closeAPI()
   {
      vpr::DebugOutputGuard og(
         pyjDBG_CXX, vprDBG_VERB_LVL,
         "vrj_opengl_DrawManager_Wrapper::closeAPI()\n",
         "vrj_opengl_DrawManager_Wrapper::closeAPI() done.\n"
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
            vrj::opengl::DrawManager::closeAPI();
         }
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }
   }

   void default_closeAPI()
   {
      vrj::opengl::DrawManager::closeAPI();
   }

   void setApp(vrj::App* app)
   {
      vpr::DebugOutputGuard og(
         pyjDBG_CXX, vprDBG_VERB_LVL,
         "vrj_opengl_DrawManager_Wrapper::setApp()\n",
         "vrj_opengl_DrawManager_Wrapper::setApp() done.\n"
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
            vrj::opengl::DrawManager::setApp(app);
         }
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }
   }

   void default_setApp(vrj::App* app)
   {
      vrj::opengl::DrawManager::setApp(app);
   }

   bool configCanHandle(jccl::ConfigElementPtr p0)
   {
      try
      {
         if ( override configCanHandle = this->get_override("configCanHandle") )
         {
            return configCanHandle(p0);
         }
         return vrj::opengl::DrawManager::configCanHandle(p0);
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }

      return false;
   }

   bool default_configCanHandle(jccl::ConfigElementPtr p0)
   {
      return vrj::opengl::DrawManager::configCanHandle(p0);
   }

   bool configAdd(jccl::ConfigElementPtr p0)
   {
      try
      {
         if ( override configAdd = this->get_override("configAdd") )
         {
            return configAdd(p0);
         }
         return vrj::opengl::DrawManager::configAdd(p0);
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }

      return false;
   }

   bool default_configAdd(jccl::ConfigElementPtr p0)
   {
      return vrj::opengl::DrawManager::configAdd(p0);
   }

   bool configRemove(jccl::ConfigElementPtr p0)
   {
      try
      {
         if ( override configRemove = this->get_override("configRemove") )
         {
            return configRemove(p0);
         }
         return vrj::opengl::DrawManager::configRemove(p0);
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }

      return false;
   }

   bool default_configRemove(jccl::ConfigElementPtr p0)
   {
      return vrj::opengl::DrawManager::configRemove(p0);
   }

   int configProcessPending()
   {
      try
      {
         if ( override configProcessPending =
                 this->get_override("configProcessPending") )
         {
            return configProcessPending();
         }
         return jccl::ConfigElementHandler::configProcessPending();
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }

      return 0;
   }

   int default_configProcessPending()
   {
      return jccl::ConfigElementHandler::configProcessPending();
   }
};

int invokeCallback(object callable, const unsigned int threadID)
{
   return extract<int>(callable(threadID));
}

void setCpuAffinityStrategy(vrj::opengl::DrawManager* mgr, object callable)
{
   mgr->setCpuAffinityStrategy(boost::bind(invokeCallback, callable, _1));
}

}  // namespace pyj

void _Export_DrawManager()
{
   // vrj::DrawManager is not listed in bases<> because that class is not
   // exposed to Python.
   class_<pyj::vrj_opengl_DrawManager_Wrapper, boost::noncopyable>(
      "DrawManager",
      "Concrete Singleton Class for OpenGL drawing.  Responsible for all\n"
      "OpenGL-based rendering.\n\n"
      "vrj::opengl::DrawManager is an active object.  It manages OpenGL\n"
      "pipes and windows.  In addition, it triggers rendering, swapping, and\n"
      "syncing of the windows under its control.\n\n"
      "All access to the OpenGL rendering structures has to happen from the\n"
      "control thread or in the case of context sensitive functions, from\n"
      "the control thread of the managed pipes.  Because of this, the object\n"
      "uses queues to hold new windows.",
      no_init
      )
      .def("setCpuAffinityStrategy", &pyj::setCpuAffinityStrategy,
           "setCpuAffinityStrategy(strategy)\n"
           "Changes the callable object used for determining the draw\n"
           "thread CPU affinity to use the given value. In order for this to\n"
           "have the desired effect, it must be called before any render\n"
           "threads have been started.\n"
           "Arguments:\n"
           "strategy -- A callable that serves to map zero-based thread\n"
           "            thread identifiers to zero-based CPU values in order\n"
           "            to assign affinity. The callable must accept a\n"
           "            single unsigned integer and return a signed integer."
      )
      .def("start", &vrj::opengl::DrawManager::start,
           &pyj::vrj_opengl_DrawManager_Wrapper::default_start,
           "start()\n"
           "Starts the control loop."
      )
      .def("draw", &vrj::opengl::DrawManager::draw,
           &pyj::vrj_opengl_DrawManager_Wrapper::default_draw,
           "draw()\n"
           "Enable a frame to be drawn."
      )
      .def("sync", &vrj::opengl::DrawManager::sync,
           &pyj::vrj_opengl_DrawManager_Wrapper::default_sync,
           "sync()\n"
           "Blocks until the end of the frame."
      )
      .def("initAPI", &vrj::opengl::DrawManager::initAPI,
           &pyj::vrj_opengl_DrawManager_Wrapper::default_initAPI,
           "initAPI()\n"
           "Initializes the drawing API (if not already running)."
      )
      .def("addDisplay", &vrj::opengl::DrawManager::addDisplay,
           &pyj::vrj_opengl_DrawManager_Wrapper::default_addDisplay,
           "addDisplay(display)\n"
           "Callback when display is added to Display Manager.\n"
           "Arguments:\n"
           "display -- A vrj.Display instance."
      )
      .def("removeDisplay", &vrj::opengl::DrawManager::removeDisplay,
           &pyj::vrj_opengl_DrawManager_Wrapper::default_removeDisplay,
           "removeDisplay(display)\n"
           "Callback when display is removed from Display Manager.\n"
           "Arguments:\n"
           "display -- A vrj.Display instance."
      )
      .def("closeAPI", &vrj::opengl::DrawManager::closeAPI,
           &pyj::vrj_opengl_DrawManager_Wrapper::default_closeAPI,
           "closeAPI()\n"
           "Initializes the drawing API (if not already running)."
      )
      .def("setApp", &vrj::opengl::DrawManager::setApp,
           &pyj::vrj_opengl_DrawManager_Wrapper::default_setApp,
           "setApp(app)\n"
           "Sets the application with which this Draw Manager will interact.\n"
           "Arguments:\n"
           "app -- A vrj.App instance."
      )
      .def("getApp", &vrj::opengl::DrawManager::getApp,
           return_internal_reference<>(),
           "getApp() -> vrj.opengl.App object\n"
           "Returns the app we are rendering."
      )
      // vrj::DisplayManager is not currently exposed to Python.
      /*
      .def("setDisplayManager", &vrj::DrawManager::setDisplayManager,
           "setDisplayManager(dispMgr)\n"
           "Setter for for Display Manager variable.\n"
           "Arguments:\n"
           "dispMgr -- A vrj.DisplayManager instance."
      )
      .def("getDisplayManager", &vrj::DrawManager::getDisplayManager,
           "getDisplayManager() -> vrj.DisplayManager object"
      )
      */
      .def("configAdd", &vrj::opengl::DrawManager::configAdd,
           &pyj::vrj_opengl_DrawManager_Wrapper::default_configAdd,
           "configAdd(element) -> Boolean value\n"
           "Adds the element to the configuration.\n"
           "Arguments:\n"
           "element -- A jccl.ConfigElement object."
      )
      .def("configRemove", &vrj::opengl::DrawManager::configRemove,
           &pyj::vrj_opengl_DrawManager_Wrapper::default_configRemove,
           "configRemove(element) -> Boolean value\n"
           "Removes the element from the configuration.\n"
           "Arguments:\n"
           "element -- A jccl.ConfigElement object."
      )
      .def("configCanHandle", &vrj::opengl::DrawManager::configCanHandle,
           &pyj::vrj_opengl_DrawManager_Wrapper::default_configCanHandle,
           "configCanHandle(element) -> Boolean value\n"
           "Can the handler handle the given config element?\n"
           "Arguments:\n"
           "element -- A jccl.ConfigElement object."
      )
      .def("currentUserData", &vrj::opengl::DrawManager::currentUserData,
           return_internal_reference<1>(),
           "Gets pointer to the current user data. Should be used in the\n"
           "draw() function.\n\n"
           "NOTE: This user data is valid ONLY in draw()!"
      )
      .def("getCurrentContext", &vrj::opengl::DrawManager::getCurrentContext,
           "Returns a unique identifier for the current context.\n\n"
           "NOTE: This user data is valid ONLY in contextInit() and draw()!"
      )
      .def("instance", &vrj::opengl::DrawManager::instance,
           return_value_policy<reference_existing_object>(),
           "vrj.opengl.DrawManager.instance() -> vrj.opengl.DrawManager object\n"
           "Returns the singleton VR Juggler OpenGL Draw Manager reference."
      )
      .staticmethod("instance")
   ;
}
