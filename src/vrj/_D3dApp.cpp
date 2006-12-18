// PyJuggler is (C) Copyright 2002-2006 by Patrick Hartling
// Distributed under the GNU Lesser General Public License 2.1.  (See
// accompanying file COPYING.txt or http://www.gnu.org/copyleft/lesser.txt)

// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <vrj/Draw/Direct3D/D3dDrawManager.h>
#include <vrj/Draw/Direct3D/D3dApp.h>
#include <vrj/Kernel/Kernel.h>
#include <pyjutil/InterpreterGuard.h>
#include <pyjutil/Debug.h>

// Using =======================================================================
using namespace boost::python;

// Declarations ================================================================
namespace pyj
{

struct vrj_D3dApp_Wrapper : vrj::D3dApp, wrapper<vrj::D3dApp>
{
   vrj_D3dApp_Wrapper(vrj::Kernel* const& kernel = NULL)
      : vrj::D3dApp(kernel)
   {
      /* Do nothing. */ ;
   }

   virtual ~vrj_D3dApp_Wrapper()
   {
      /* Do nothing. */ ;
   }

   void draw(LPDIRECT3DDEVICE9 renderDevice)
   {
      vpr::DebugOutputGuard og(pyjDBG_CXX, vprDBG_VERB_LVL,
                               "vrj_D3dApp_Wrapper::draw()\n",
                               "vrj_D3dApp_Wrapper::draw() done.\n");
      PyJuggler::InterpreterGuard guard;

      try
      {
         this->get_override("draw")(renderDevice);
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }
   }

   void contextInit(LPDIRECT3DDEVICE9 renderDevice)
   {
      vpr::DebugOutputGuard og(pyjDBG_CXX, vprDBG_VERB_LVL,
                               "vrj_D3dApp_Wrapper::contextInit()\n",
                               "vrj_D3dApp_Wrapper::contextInit() done.\n");
      PyJuggler::InterpreterGuard guard;

      try
      {
         if ( override contextInit = this->get_override("contextInit") )
         {
            contextInit(renderDevice);
         }
         else
         {
            vrj::D3dApp::contextInit(renderDevice);
         }
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }
   }

   void default_contextInit(LPDIRECT3DDEVICE9 renderDevice)
   {
      vrj::D3dApp::contextInit(renderDevice);
   }

   void contextClose()
   {
      vpr::DebugOutputGuard og(pyjDBG_CXX, vprDBG_VERB_LVL,
                               "vrj_D3dApp_Wrapper::contextClose()\n",
                               "vrj_D3dApp_Wrapper::contextClose() done.\n");
      PyJuggler::InterpreterGuard guard;

      try
      {
         if ( override contextClose = this->get_override("contextClose") )
         {
            contextClose();
         }
         else
         {
            vrj::D3dApp::contextClose();
         }
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }
   }

   void default_contextClose()
   {
      vrj::D3dApp::contextClose();
   }

   void contextPreDraw()
   {
      vpr::DebugOutputGuard og(pyjDBG_CXX, vprDBG_VERB_LVL,
                               "vrj_D3dApp_Wrapper::contextPreDraw()\n",
                               "vrj_D3dApp_Wrapper::contextPreDraw() done.\n");
      PyJuggler::InterpreterGuard guard;

      try
      {
         if ( override contextPreDraw = this->get_override("contextPreDraw") )
         {
            contextPreDraw();
         }
         else
         {
            vrj::D3dApp::contextPreDraw();
         }
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }
   }

   void default_contextPreDraw()
   {
      vrj::D3dApp::contextPreDraw();
   }

   void contextPostDraw()
   {
      vpr::DebugOutputGuard og(pyjDBG_CXX, vprDBG_VERB_LVL,
                               "vrj_D3dApp_Wrapper::contextPostDraw()\n",
                               "vrj_D3dApp_Wrapper::contextPostDraw() done.\n");
      PyJuggler::InterpreterGuard guard;

      try
      {
         if ( override contextPostDraw = this->get_override("contextPostDraw") )
         {
            contextPostDraw();
         }
         else
         {
            vrj::D3dApp::contextPostDraw();
         }
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }
   }

   void default_contextPostDraw()
   {
      vrj::D3dApp::contextPostDraw();
   }

   void bufferPreDraw()
   {
      vpr::DebugOutputGuard og(pyjDBG_CXX, vprDBG_VERB_LVL,
                               "vrj_D3dApp_Wrapper::bufferPreDraw()\n",
                               "vrj_D3dApp_Wrapper::bufferPreDraw() done.\n");
      PyJuggler::InterpreterGuard guard;

      try
      {
         if ( override bufferPreDraw = this->get_override("bufferPreDraw") )
         {
            bufferPreDraw();
         }
         else
         {
            vrj::D3dApp::bufferPreDraw();
         }
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }
   }

   void default_bufferPreDraw()
   {
      vrj::D3dApp::bufferPreDraw();
   }

   void pipePreDraw()
   {
      vpr::DebugOutputGuard og(pyjDBG_CXX, vprDBG_VERB_LVL,
                               "vrj_D3dApp_Wrapper::pipePreDraw()\n",
                               "vrj_D3dApp_Wrapper::pipePreDraw() done.\n");
      PyJuggler::InterpreterGuard guard;

      try
      {
         if ( override pipePreDraw = this->get_override("pipePreDraw") )
         {
            pipePreDraw();
         }
         else
         {
            vrj::D3dApp::pipePreDraw();
         }
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }
   }

   void default_pipePreDraw()
   {
      vrj::D3dApp::pipePreDraw();
   }

   void init()
   {
      vpr::DebugOutputGuard og(pyjDBG_CXX, vprDBG_VERB_LVL,
                               "vrj_D3dApp_Wrapper::init()\n",
                               "vrj_D3dApp_Wrapper::init() done.\n");
      PyJuggler::InterpreterGuard guard;

      try
      {
         if ( override init = this->get_override("init") )
         {
            init();
         }
         else
         {
            vrj::D3dApp::init();
         }
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }
   }

   void default_init()
   {
      vrj::D3dApp::init();
   }

   void apiInit()
   {
      vpr::DebugOutputGuard og(pyjDBG_CXX, vprDBG_VERB_LVL,
                               "vrj_D3dApp_Wrapper::apiInit()\n",
                               "vrj_D3dApp_Wrapper::apiInit() done.\n");
      PyJuggler::InterpreterGuard guard;

      try
      {
         if ( override apiInit = this->get_override("apiInit") )
         {
            apiInit();
         }
         else
         {
            vrj::D3dApp::apiInit();
         }
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }
   }

   void default_apiInit()
   {
      vrj::D3dApp::apiInit();
   }

   void exit()
   {
      vpr::DebugOutputGuard og(pyjDBG_CXX, vprDBG_VERB_LVL,
                               "vrj_D3dApp_Wrapper::exit()\n",
                               "vrj_D3dApp_Wrapper::exit() done.\n");
      PyJuggler::InterpreterGuard guard;

      try
      {
         if ( override exit = this->get_override("exit") )
         {
            exit();
         }
         else
         {
            vrj::D3dApp::exit();
         }
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }
   }

   void default_exit()
   {
      vrj::D3dApp::exit();
   }

   void preFrame()
   {
      vpr::DebugOutputGuard og(pyjDBG_CXX, vprDBG_VERB_LVL,
                               "vrj_D3dApp_Wrapper::preFrame()\n",
                               "vrj_D3dApp_Wrapper::preFrame() done.\n");
      PyJuggler::InterpreterGuard guard;

      try
      {
         if ( override preFrame = this->get_override("preFrame") )
         {
            preFrame();
         }
         else
         {
            vrj::D3dApp::preFrame();
         }
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }
   }

   void default_preFrame()
   {
      vrj::D3dApp::preFrame();
   }

   void latePreFrame()
   {
      vpr::DebugOutputGuard og(pyjDBG_CXX, vprDBG_VERB_LVL,
                               "vrj_D3dApp_Wrapper::latePreFrame()\n",
                               "vrj_D3dApp_Wrapper::latePreFrame() done.\n");
      PyJuggler::InterpreterGuard guard;

      try
      {
         if ( override latePreFrame = this->get_override("latePreFrame") )
         {
            latePreFrame();
         }
         else
         {
            vrj::D3dApp::latePreFrame();
         }
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }
   }

   void default_latePreFrame()
   {
      vrj::D3dApp::latePreFrame();
   }

   void intraFrame()
   {
      vpr::DebugOutputGuard og(pyjDBG_CXX, vprDBG_VERB_LVL,
                               "vrj_D3dApp_Wrapper::intraFrame()\n",
                               "vrj_D3dApp_Wrapper::intraFrame() done.\n");
      PyJuggler::InterpreterGuard guard;

      try
      {
         if ( override intraFrame = this->get_override("intraFrame") )
         {
            intraFrame();
         }
         else
         {
            vrj::D3dApp::intraFrame();
         }
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }
   }

   void default_intraFrame()
   {
      vrj::D3dApp::intraFrame();
   }

   void postFrame()
   {
      vpr::DebugOutputGuard og(pyjDBG_CXX, vprDBG_VERB_LVL,
                               "vrj_D3dApp_Wrapper::postFrame()\n",
                               "vrj_D3dApp_Wrapper::postFrame() done.\n");
      PyJuggler::InterpreterGuard guard;

      try
      {
         if ( override postFrame = this->get_override("postFrame") )
         {
            postFrame();
         }
         else
         {
            vrj::D3dApp::postFrame();
         }
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }
   }

   void default_postFrame()
   {
      vrj::D3dApp::postFrame();
   }

   void reset()
   {
      vpr::DebugOutputGuard og(pyjDBG_CXX, vprDBG_VERB_LVL,
                               "vrj_D3dApp_Wrapper::reset()\n",
                               "vrj_D3dApp_Wrapper::reset() done.\n");
      PyJuggler::InterpreterGuard guard;

      try
      {
         if ( override reset = this->get_override("reset") )
         {
            reset();
         }
         else
         {
            vrj::D3dApp::reset();
         }
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }
   }

   void default_reset()
   {
      vrj::D3dApp::reset();
   }

   void focusChanged()
   {
      vpr::DebugOutputGuard og(pyjDBG_CXX, vprDBG_VERB_LVL,
                               "vrj_D3dApp_Wrapper::focusChanged()\n",
                               "vrj_D3dApp_Wrapper::focusChanged() done.\n");
      PyJuggler::InterpreterGuard guard;

      try
      {
         if ( override focusChanged = this->get_override("focusChanged") )
         {
            focusChanged();
         }
         else
         {
            vrj::D3dApp::focusChanged();
         }
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }
   }

   void default_focusChanged()
   {
      vrj::D3dApp::focusChanged();
   }

   float getDrawScaleFactor()
   {
      vpr::DebugOutputGuard og(pyjDBG_CXX, vprDBG_VERB_LVL,
                               "vrj_D3dApp_Wrapper::getDrawScaleFactor()\n",
                               "vrj_D3dApp_Wrapper::getDrawScaleFactor() done.\n");
      PyJuggler::InterpreterGuard guard;

      try
      {
         if ( override getDrawScaleFactor =
                 this->get_override("getDrawScaleFactor") )
         {
            return getDrawScaleFactor();
         }
         return vrj::D3dApp::getDrawScaleFactor();
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }

      return vrj::D3dApp::getDrawScaleFactor();
   }

   float default_getDrawScaleFactor()
   {
      return vrj::D3dApp::getDrawScaleFactor();
   }

   bool configCanHandle(jccl::ConfigElementPtr p0)
   {
      vpr::DebugOutputGuard og(pyjDBG_CXX, vprDBG_VERB_LVL,
                               "vrj_D3dApp_Wrapper::configCanHandle()\n",
                               "vrj_D3dApp_Wrapper::configCanHandle() done.\n");
      PyJuggler::InterpreterGuard guard;

      try
      {
         if ( override configCanHandle = this->get_override("configCanHandle") )
         {
            return configCanHandle(p0);
         }
         return vrj::D3dApp::configCanHandle(p0);
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }

      return false;
   }

   bool default_configCanHandle(jccl::ConfigElementPtr p0)
   {
      return vrj::D3dApp::configCanHandle(p0);
   }

   bool depSatisfied()
   {
      vpr::DebugOutputGuard og(pyjDBG_CXX, vprDBG_VERB_LVL,
                               "vrj_D3dApp_Wrapper::depSatisfied()\n",
                               "vrj_D3dApp_Wrapper::depSatisfied() done.\n");
      PyJuggler::InterpreterGuard guard;

      try
      {
         if ( override depSatisfied = this->get_override("depSatisfied") )
         {
            return depSatisfied();
         }
         return vrj::D3dApp::depSatisfied();
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }

      return true;
   }

   bool default_depSatisfied()
   {
      return vrj::D3dApp::depSatisfied();
   }

   bool configAdd(jccl::ConfigElementPtr p0)
   {
      vpr::DebugOutputGuard og(pyjDBG_CXX, vprDBG_VERB_LVL,
                               "vrj_D3dApp_Wrapper::configAdd()\n",
                               "vrj_D3dApp_Wrapper::configAdd() done.\n");
      PyJuggler::InterpreterGuard guard;

      try
      {
         if ( override configAdd = this->get_override("configAdd") )
         {
            return configAdd(p0);
         }
         return vrj::D3dApp::configAdd(p0);
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }

      return false;
   }

   bool default_configAdd(jccl::ConfigElementPtr p0)
   {
      return vrj::D3dApp::configAdd(p0);
   }

   bool configRemove(jccl::ConfigElementPtr p0)
   {
      vpr::DebugOutputGuard og(pyjDBG_CXX, vprDBG_VERB_LVL,
                               "vrj_D3dApp_Wrapper::configRemove()\n",
                               "vrj_D3dApp_Wrapper::configRemove() done.\n");
      PyJuggler::InterpreterGuard guard;

      try
      {
         if ( override configRemove = this->get_override("configRemove") )
         {
            return configRemove(p0);
         }
         return vrj::D3dApp::configRemove(p0);
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }

      return false;
   }

   bool default_configRemove(jccl::ConfigElementPtr p0)
   {
      return vrj::D3dApp::configRemove(p0);
   }

   vrj::DrawManager* getDrawManager()
   {
      vpr::DebugOutputGuard og(pyjDBG_CXX, vprDBG_VERB_LVL,
                               "vrj_D3dApp_Wrapper::getDrawManager()\n",
                               "vrj_D3dApp_Wrapper::getDrawManager() done.\n");
      PyJuggler::InterpreterGuard guard;

      try
      {
         if ( override getDrawManager = this->get_override("getDrawManager") )
         {
           return getDrawManager();
         }
         return vrj::D3dApp::getDrawManager();
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }

      return NULL;
   }

   void default_getDrawManager()
   {
      vrj::D3dApp::getDrawManager();
   }

   int configProcessPending()
   {
      vpr::DebugOutputGuard og(pyjDBG_CXX, vprDBG_VERB_LVL,
                               "vrj_D3dApp_Wrapper::configProcessPending()\n",
                               "vrj_D3dApp_Wrapper::configProcessPending() done.\n");
      PyJuggler::InterpreterGuard guard;

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

}// namespace 


// Module ======================================================================
void _Export_D3dApp()
{
   class_<pyj::vrj_D3dApp_Wrapper, bases<vrj::App>, boost::noncopyable>
      ("D3dApp",
       "vrj.D3dApp encapsulates an actual Direct3D application object.\n"
       "This defines the base class from which Direct3D-based application\n"
       "objects should be derived. The interface given what the kernel and\n"
       "the Direct3D Draw Manager expect in order to interact with the\n"
       "application object.\n\n"
       "The control loop will look similar to this:\n\n"
       "d3dapp_obj.contextInit()        # called for each context\n"
       "while drawing:\n"
       "   d3dapp_obj.preFrame()\n"
       "   d3dapp_obj.latePreFrame()\n"
       "   d3dapp_obj.bufferPreDraw()   # called for each draw buffer\n"
       "   d3dapp_obj.contextPreDraw()  # called for each context\n"
       "   d3dapp_obj.draw()            # called for each viewport\n"
       "   d3dapp_obj.contextPostDraw() # called for each context\n"
       "   d3dapp_obj.intraFrame()      # called in parallel to the draw functions\n"
       "   sync()\n"
       "   d3dapp_obj.postFrame()\n\n"
       "   updateAllDevices()\n"
       "d3dapp_obj.contextClose()       # called for each context\n\n"
       "Note: One time through the loop is a Juggler Frame.\n\n"
       "See also: vrj.App, vrj.Kernel"
       ,
       init< optional<vrj::Kernel*> >(
          "__init__()\n"
          "Default constructor. Uses vrj.Kernel.instance().\n\n"
          "__init__(kernel)\n"
          "Arguments:\n"
          "kernel -- The vrj.Kernel instance that is active (so the\n"
          "          application has easy access to the kernel)."
       )
      )
      .def("draw", pure_virtual(&vrj::D3dApp::draw),
           "draw()\n"
           "Function that renders the scene. Override this function with\n"
           "the application-specific rendering routine.\n\n"
           "Pre-condition:\n"
           "Direct3D state has transformation and buffer selected.\n\n"
           "Post-condition:\n"
           "The current scene has been drawn."
      )
      .def("contextInit", &vrj::D3dApp::contextInit,
           &pyj::vrj_D3dApp_Wrapper::default_contextInit,
           "contextInit()\n"
           "Function that is called immediately after a new context is\n"
           "created. Use this function to create context-specific data\n"
           "structures such as display lists and texture objects that are\n"
           "known to be required when the context is created.\n\n"
           "Pre-condition:\n"
           "The Direct3D context has been set to the new context.\n\n"
           "Post-condition:\n"
           "The application has completed context-specific initialization."
      )
      .def("contextClose", &vrj::D3dApp::contextClose,
           &pyj::vrj_D3dApp_Wrapper::default_contextClose,
           "contextClose()\n"
           "Function that is called immediately before a context is closed.\n"
           "Use this function to clean up any context-specific data\n"
           "structures."
      )
      .def("contextPreDraw", &vrj::D3dApp::contextPreDraw,
           &pyj::vrj_D3dApp_Wrapper::default_contextPreDraw,
           "contextPreDraw()\n"
           "Function that is called upon entry into the context before\n"
           "rendering begins. This can be used to allocate\n"
           "context-specific data dynamically.\n\n"
           "Pre-conditions:\n"
           "The Direct3D context has been set to the context for drawing.\n\n"
           "Post-conditins:\n"
           "The application object has executed any commands that need to\n"
           "be executed only once per context, per frame.\n\n"
           "This function can be used for things that need to happen every\n"
           "frame but only once per context."
      )
      .def("contextPostDraw", &vrj::D3dApp::contextPostDraw,
           &pyj::vrj_D3dApp_Wrapper::default_contextPostDraw,
           "contextPostDraw()\n"
           "Function that is called upon exit of the context after\n"
           "rendering\n\n"
           "Pre-conditions:\n"
           "The Direct3D context has been set to the context for drawing."
      )
      .def("bufferPreDraw", &vrj::D3dApp::bufferPreDraw,
           &pyj::vrj_D3dApp_Wrapper::default_bufferPreDraw,
           "bufferPreDraw()\n"
           "Function that is called once for each frame buffer of an\n"
           "Direct3D context. This function is executed after contextInit()\n"
           "(if neede) but before contextPreDraw(). It is called once per\n"
           "frame buffer (see note below).\n\n"
           "Pre-conditions:\n"
           "The Direct3D context has been set to the context for drawing.\n\n"
           "Post-conditions:\n"
           "The application object has executed any commands that need to\n"
           "be executed once per context, per buffer, per frame.\n\n"
           "Note:\n"
           "This function is designed to be used when some task must be\n"
           "performed only once per frame buffer (i.e., once for the left\n"
           "tbuffer, once for the right buffer). For example, the Direct3D\n"
           "clear color should be defined and glClear(GL_COLOR_BUFFER_BIT)\n"
           "should be called in this method."
      )
      .def("pipePreDraw", &vrj::D3dApp::pipePreDraw,
           &pyj::vrj_D3dApp_Wrapper::default_pipePreDraw,
           "pipePreDraw()\n"
           "Function that is called at the beginning of the drawing of eacn\n"
           "pipe.\n\n"
           "Pre-conditions:\n"
           "The library is preparing to render all windows on a given\n"
           "pipe.\n\n"
           "Post-conditions:\n"
           "Any pre-pipe user calls have been done.\n\n"
           "Note:\n"
           "Currently the Direct3D context is not set when this function is\n"
           "called. This is a TEST function. USE AT YOUR OWN RISK!"
      )
      .def("init", &vrj::D3dApp::init, &pyj::vrj_D3dApp_Wrapper::default_init,
           "init()\n"
           "Application initialization function. Execute any initialization\n"
           "needed before the graphics API is started.\n\n"
           "Note:\n"
           "Derived classes MUST call the base class version of this\n"
           "method."
      )
      .def("apiInit", &vrj::D3dApp::apiInit,
           &pyj::vrj_D3dApp_Wrapper::default_apiInit,
           "apiInit()\n"
           "Application graphics API initialization function. Execute any\n"
           "initialization needed after the graphics API is started but\n"
           "before the Draw Manager starts the rendering loop(s)."
      )
      .def("exit", &vrj::D3dApp::exit, &pyj::vrj_D3dApp_Wrapper::default_exit,
           "exit()\n"
           "Executes any final clean-up needed for the application before\n"
           "exiting."
      )
      .def("preFrame", &vrj::D3dApp::preFrame,
           &pyj::vrj_D3dApp_Wrapper::default_preFrame,
           "preFrame()\n"
           "Function called before the Juggler frame starts. This is called\n"
           "after input device updates but before the start of a new frame."
      )
      .def("latePreFrame", &vrj::D3dApp::latePreFrame,
           &pyj::vrj_D3dApp_Wrapper::default_latePreFrame,
           "latePreFrame()\n"
           "Function called after preFrame() and application-specific data\n"
           "synchronization (in a cluster conifguration) but before the\n"
           "start of a new frame.\n\n"
           "Note:\n"
           "This is required because we cannot update data during the\n"
           "rendering process since it might be using multiple threads."
      )
      .def("intraFrame", &vrj::D3dApp::intraFrame,
           &pyj::vrj_D3dApp_Wrapper::default_intraFrame,
           "intraFrame()\n"
           "Function called during the application's drawing time."
      )
      .def("postFrame", &vrj::D3dApp::postFrame,
           &pyj::vrj_D3dApp_Wrapper::default_postFrame,
           "postFrame()\n"
           "Function alled before updating input devices but after the\n"
           "frame is complete."
      )
      .def("reset", &vrj::D3dApp::reset,
           &pyj::vrj_D3dApp_Wrapper::default_reset,
           "reset()\n"
           "Resets the application. This is used when the kernel (or\n"
           "applications would like this application to reset to its\n"
           "initial state."
      )
      .def("focusChanged", &vrj::D3dApp::focusChanged,
           &pyj::vrj_D3dApp_Wrapper::default_focusChanged,
           "focusChanged()\n"
           "Called when the focus state changes."
      )
      .def("getDrawScaleFactor", &vrj::D3dApp::getDrawScaleFactor,
           &pyj::vrj_D3dApp_Wrapper::default_getDrawScaleFactor,
           "getDrawScaleFactor() -> float\n"
           "Returns the scale factor to convert from Juggler units\n"
           "(meters) to application units. Internally, VR Juggler stores\n"
           "and processes all position values in meterrs. The scale factor\n"
           "returned by this method is used by VR Juggler to scale the\n"
           "rendering state from meters to whatever units this application\n"
           "wants to use. For example, to render in feet, return 3.28\n"
           "(gadget.PositionUnitConversion.ConvertToFeet)."
      )
      .def("configCanHandle", &vrj::D3dApp::configCanHandle,
           &pyj::vrj_D3dApp_Wrapper::default_configCanHandle,
           "configCanHandle(element) -> Boolean\n"
           "Defaults to handling nothing.\n\n"
           "Arguments:\n"
           "element -- An instance of jccl.ConfigElement."
      )
      .def("depSatisfied", &vrj::D3dApp::depSatisfied,
           &pyj::vrj_D3dApp_Wrapper::default_depSatisfied,
           "depSatisfied() -> Boolean\n"
           "Are any application dependencies satisified?  If this\n"
           "application requires anything special of the system for\n"
           "successful initialization, check it here. If the return value\n"
           "is False, then this application will not be started yet. If the\n"
           "return value is True, this application will be allowed to enter\n"
           "the system."
      )
//      .def("getDrawManager", &vrj::D3dApp::getDrawManager,
//           &pyj::vrj_D3dApp_Wrapper::default_getDrawManager,
//           return_internal_reference<1>()
//      )
      .def("configProcessPending",
           &jccl::ConfigElementHandler::configProcessPending,
           &pyj::vrj_D3dApp_Wrapper::default_configProcessPending,
           "configProcessPending() -> int\n"
           "Inherited from jccl.ConfigElementHandler and not overridden."
      )
   ;
}
