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
      this->get_override("draw");
   }

   void sync()
   {
      this->get_override("sync");
   }

   void initAPI()
   {
      this->get_override("initAPI");
   }

   void addDisplay(vrj::DisplayPtr display)
   {
      this->get_override("addDisplay");
   }

   void removeDisplay(vrj::DisplayPtr display)
   {
      this->get_override("removeDisplay");
   }

   void closeAPI()
   {
      this->get_override("closeAPI");
   }

   void setApp(vrj::App* app)
   {
      this->get_override("setApp");
   }
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
