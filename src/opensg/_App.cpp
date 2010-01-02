// PyJuggler is (C) Copyright 2002-2010 by Patrick Hartling
// Distributed under the GNU Lesser General Public License 2.1.  (See
// accompanying file COPYING.txt or http://www.gnu.org/copyleft/lesser.txt)

// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <vrj/Draw/OpenSG/App.h>
#include <vrj/Kernel/Kernel.h>
#include <pyjutil/InterpreterGuard.h>
#include <pyjutil/Debug.h>

// Using =======================================================================
using namespace boost::python;

// Declarations ================================================================
namespace pyj
{

struct vrj_opensg_App_Wrapper : vrj::opensg::App, wrapper<vrj::opensg::App>
{
   vrj_opensg_App_Wrapper(vrj::Kernel* p0 = NULL)
      : vrj::opensg::App(p0)
   {
      /* Do nothing. */ ;
   }

   virtual ~vrj_opensg_App_Wrapper()
   {
      /* Do nothing. */ ;
   }

   void initScene()
   {
      vpr::DebugOutputGuard og(pyjDBG_CXX, vprDBG_VERB_LVL,
                               "vrj_opensg_App_Wrapper::initScene()\n",
                               "vrj_opensg_App_Wrapper::initScene() done.\n");
      PyJuggler::InterpreterGuard guard;

      try
      {
         this->get_override("initScene")();
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }
   }

   OSG::NodePtr getScene()
   {
      vpr::DebugOutputGuard og(pyjDBG_CXX, vprDBG_VERB_LVL,
                               "vrj_opensg_App_Wrapper::getScene()\n",
                               "vrj_opensg_App_Wrapper::getScene() done.\n");
      PyJuggler::InterpreterGuard guard;

      try
      {
         return this->get_override("getScene")();
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }

      return OSG::NullFC;
   }

   void draw()
   {
      vpr::DebugOutputGuard og(pyjDBG_CXX, vprDBG_VERB_LVL,
                               "vrj_opensg_App_Wrapper::draw()\n",
                               "vrj_opensg_App_Wrapper::draw() done.\n");
      PyJuggler::InterpreterGuard guard;

      try
      {
         if ( override draw = this->get_override("draw") )
         {
            draw();
         }
         else
         {
            vrj::opensg::App::draw();
         }
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }
   }

   void default_draw()
   {
      vrj::opensg::App::draw();
   }

   void init()
   {
      vpr::DebugOutputGuard og(pyjDBG_CXX, vprDBG_VERB_LVL,
                               "vrj_opensg_App_Wrapper::init()\n",
                               "vrj_opensg_App_Wrapper::init() done.\n");
      PyJuggler::InterpreterGuard guard;

      try
      {
         if ( override init = this->get_override("init") )
         {
            init();
         }
         else
         {
            vrj::opensg::App::init();
         }
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }
   }

   void default_init()
   {
      vrj::opensg::App::init();
   }

   void contextInit()
   {
      vpr::DebugOutputGuard og(
         pyjDBG_CXX, vprDBG_VERB_LVL,
         "vrj_opensg_App_Wrapper::contextInit()\n",
         "vrj_opensg_App_Wrapper::contextInit() done.\n"
      );
      PyJuggler::InterpreterGuard guard;

      try
      {
         if ( override contextInit = this->get_override("contextInit") )
         {
            contextInit();
         }
         else
         {
            vrj::opensg::App::contextInit();
         }
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }
   }

   void default_contextInit()
   {
      vrj::opensg::App::contextInit();
   }

   void contextClose()
   {
      vpr::DebugOutputGuard og(
         pyjDBG_CXX, vprDBG_VERB_LVL,
         "vrj_opensg_App_Wrapper::contextClose()\n",
         "vrj_opensg_App_Wrapper::contextClose() done.\n"
      );
      PyJuggler::InterpreterGuard guard;

      try
      {
         if ( override contextClose = this->get_override("contextClose") )
         {
            contextClose();
         }
         else
         {
            vrj::opensg::App::contextClose();
         }
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }
   }

   void default_contextClose()
   {
      vrj::opensg::App::contextClose();
   }

   void contextPreDraw()
   {
      vpr::DebugOutputGuard og(
         pyjDBG_CXX, vprDBG_VERB_LVL,
         "vrj_opensg_App_Wrapper::contextPreDraw()\n",
         "vrj_opensg_App_Wrapper::contextPreDraw() done.\n"
      );
      PyJuggler::InterpreterGuard guard;

      try
      {
         if ( override contextPreDraw = this->get_override("contextPreDraw") )
         {
            contextPreDraw();
         }
         else
         {
            vrj::opensg::App::contextPreDraw();
         }
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }
   }

   void default_contextPreDraw()
   {
      vrj::opensg::App::contextPreDraw();
   }

   void bufferPreDraw()
   {
      vpr::DebugOutputGuard og(
         pyjDBG_CXX, vprDBG_VERB_LVL,
         "vrj_opensg_App_Wrapper::bufferPreDraw()\n",
         "vrj_opensg_App_Wrapper::bufferPreDraw() done.\n"
      );
      PyJuggler::InterpreterGuard guard;

      try
      {
         if ( override bufferPreDraw = this->get_override("bufferPreDraw") )
         {
            bufferPreDraw();
         }
         else
         {
            vrj::opensg::App::bufferPreDraw();
         }
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }
   }

   void default_bufferPreDraw()
   {
      vrj::opensg::App::bufferPreDraw();
   }

   void pipePreDraw()
   {
      vpr::DebugOutputGuard og(
         pyjDBG_CXX, vprDBG_VERB_LVL,
         "vrj_opensg_App_Wrapper::pipePreDraw()\n",
         "vrj_opensg_App_Wrapper::pipePreDraw() done.\n"
      );
      PyJuggler::InterpreterGuard guard;

      try
      {
         if ( override pipePreDraw = this->get_override("pipePreDraw") )
         {
            pipePreDraw();
         }
         else
         {
            vrj::opensg::App::pipePreDraw();
         }
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }
   }

   void default_pipePreDraw()
   {
      vrj::opensg::App::pipePreDraw();
   }

   void contextPostDraw()
   {
      vpr::DebugOutputGuard og(
         pyjDBG_CXX, vprDBG_VERB_LVL,
         "vrj_opensg_App_Wrapper::contextPostDraw()\n",
         "vrj_opensg_App_Wrapper::contextPostDraw() done.\n"
      );
      PyJuggler::InterpreterGuard guard;

      try
      {
         if ( override contextPostDraw = this->get_override("contextPostDraw") )
         {
            contextPostDraw();
         }
         else
         {
            vrj::opensg::App::contextPostDraw();
         }
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }
   }

   void default_contextPostDraw()
   {
      vrj::opensg::App::contextPostDraw();
   }

   void apiInit()
   {
      vpr::DebugOutputGuard og(pyjDBG_CXX, vprDBG_VERB_LVL,
                               "vrj_opensg_App_Wrapper::apiInit()\n",
                               "vrj_opensg_App_Wrapper::apiInit() done.\n");
      PyJuggler::InterpreterGuard guard;

      try
      {
         if ( override apiInit = this->get_override("apiInit") )
         {
            apiInit();
         }
         else
         {
            vrj::opensg::App::apiInit();
         }
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }
   }

   void default_apiInit()
   {
      vrj::opensg::App::apiInit();
   }

   void exit()
   {
      vpr::DebugOutputGuard og(pyjDBG_CXX, vprDBG_VERB_LVL,
                               "vrj_opensg_App_Wrapper::exit()\n",
                               "vrj_opensg_App_Wrapper::exit() done.\n");
      PyJuggler::InterpreterGuard guard;

      try
      {
         if ( override exit = this->get_override("exit") )
         {
            exit();
         }
         else
         {
            vrj::opensg::App::exit();
         }
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }
   }

   void default_exit()
   {
      vrj::opensg::App::exit();
   }

   void preFrame()
   {
      vpr::DebugOutputGuard og(pyjDBG_CXX, vprDBG_VERB_LVL,
                               "vrj_opensg_App_Wrapper::preFrame()\n",
                               "vrj_opensg_App_Wrapper::preFrame() done.\n");
      PyJuggler::InterpreterGuard guard;

      try
      {
         if ( override preFrame = this->get_override("preFrame") )
         {
            preFrame();
         }
         else
         {
            vrj::opensg::App::preFrame();
         }
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }
   }

   void default_preFrame()
   {
      vrj::opensg::App::preFrame();
   }

   void latePreFrame()
   {
      vpr::DebugOutputGuard og(
         pyjDBG_CXX, vprDBG_VERB_LVL,
         "vrj_opensg_App_Wrapper::latePreFrame()\n",
         "vrj_opensg_App_Wrapper::latePreFrame() done.\n"
      );
      PyJuggler::InterpreterGuard guard;

      try
      {
         if ( override latePreFrame = this->get_override("latePreFrame") )
         {
            latePreFrame();
         }
         else
         {
            vrj::opensg::App::latePreFrame();
         }
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }
   }

   void default_latePreFrame()
   {
      vrj::opensg::App::latePreFrame();
   }

   void intraFrame()
   {
      vpr::DebugOutputGuard og(
         pyjDBG_CXX, vprDBG_VERB_LVL,
         "vrj_opensg_App_Wrapper::intraFrame()\n",
         "vrj_opensg_App_Wrapper::intraFrame() done.\n"
      );
      PyJuggler::InterpreterGuard guard;

      try
      {
         if ( override intraFrame = this->get_override("intraFrame") )
         {
            intraFrame();
         }
         else
         {
            vrj::opensg::App::intraFrame();
         }
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }
   }

   void default_intraFrame()
   {
      vrj::opensg::App::intraFrame();
   }

   void postFrame()
   {
      vpr::DebugOutputGuard og(pyjDBG_CXX, vprDBG_VERB_LVL,
                               "vrj_opensg_App_Wrapper::postFrame()\n",
                               "vrj_opensg_App_Wrapper::postFrame() done.\n");
      PyJuggler::InterpreterGuard guard;

      try
      {
         if ( override postFrame = this->get_override("postFrame") )
         {
            postFrame();
         }
         else
         {
            vrj::opensg::App::postFrame();
         }
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }
   }

   void default_postFrame()
   {
      vrj::opensg::App::postFrame();
   }

   void reset()
   {
      vpr::DebugOutputGuard og(pyjDBG_CXX, vprDBG_VERB_LVL,
                               "vrj_opensg_App_Wrapper::reset()\n",
                               "vrj_opensg_App_Wrapper::reset() done.\n");
      PyJuggler::InterpreterGuard guard;

      try
      {
         if ( override reset = this->get_override("reset") )
         {
            reset();
         }
         else
         {
            vrj::opensg::App::reset();
         }
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }
   }

   void default_reset()
   {
      vrj::opensg::App::reset();
   }

   void focusChanged()
   {
      vpr::DebugOutputGuard og(
         pyjDBG_CXX, vprDBG_VERB_LVL,
         "vrj_opensg_App_Wrapper::focusChanged()\n",
         "vrj_opensg_App_Wrapper::focusChanged() done.\n"
      );
      PyJuggler::InterpreterGuard guard;

      try
      {
         if ( override focusChanged = this->get_override("focusChanged") )
         {
            focusChanged();
         }
         else
         {
            vrj::opensg::App::focusChanged();
         }
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }
   }

   void default_focusChanged()
   {
      vrj::opensg::App::focusChanged();
   }

   float getDrawScaleFactor()
   {
      vpr::DebugOutputGuard og(
         pyjDBG_CXX, vprDBG_VERB_LVL,
         "vrj_opensg_App_Wrapper::getDrawScaleFactor()\n",
         "vrj_opensg_App_Wrapper::getDrawScaleFactor() done.\n"
      );
      PyJuggler::InterpreterGuard guard;

      try
      {
         if ( override getDrawScaleFactor =
                 this->get_override("getDrawScaleFactor") )
         {
            return getDrawScaleFactor();
         }
         return vrj::opensg::App::getDrawScaleFactor();
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }

      return vrj::opensg::App::getDrawScaleFactor();
   }

   float default_getDrawScaleFactor()
   {
      return vrj::opensg::App::getDrawScaleFactor();
   }

   bool configCanHandle(jccl::ConfigElementPtr p0)
   {
      vpr::DebugOutputGuard og(
         pyjDBG_CXX, vprDBG_VERB_LVL,
         "vrj_opensg_App_Wrapper::configCanHandle()\n",
         "vrj_opensg_App_Wrapper::configCanHandle() done.\n"
      );
      PyJuggler::InterpreterGuard guard;

      try
      {
         if ( override configCanHandle = this->get_override("configCanHandle") )
         {
            return configCanHandle(p0);
         }
         return vrj::opensg::App::configCanHandle(p0);
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }

      return false;
   }

   bool default_configCanHandle(jccl::ConfigElementPtr p0)
   {
      return vrj::opensg::App::configCanHandle(p0);
   }

   bool depSatisfied()
   {
      vpr::DebugOutputGuard og(
         pyjDBG_CXX, vprDBG_VERB_LVL,
         "vrj_opensg_App_Wrapper::depSatisfied()\n",
         "vrj_opensg_App_Wrapper::depSatisfied() done.\n"
      );
      PyJuggler::InterpreterGuard guard;

      try
      {
         if ( override depSatisfied = this->get_override("depSatisfied") )
         {
            return depSatisfied();
         }
         return vrj::opensg::App::depSatisfied();
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }

      return true;
   }

   bool default_depSatisfied()
   {
      return vrj::opensg::App::depSatisfied();
   }

   bool configAdd(jccl::ConfigElementPtr p0)
   {
      vpr::DebugOutputGuard og(pyjDBG_CXX, vprDBG_VERB_LVL,
                               "vrj_opensg_App_Wrapper::configAdd()\n",
                               "vrj_opensg_App_Wrapper::configAdd() done.\n");
      PyJuggler::InterpreterGuard guard;

      try
      {
         if ( override configAdd = this->get_override("configAdd") )
         {
            return configAdd(p0);
         }
         return vrj::opensg::App::configAdd(p0);
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }

      return false;
   }

   bool default_configAdd(jccl::ConfigElementPtr p0)
   {
      return vrj::opensg::App::configAdd(p0);
   }

   bool configRemove(jccl::ConfigElementPtr p0)
   {
      vpr::DebugOutputGuard og(
         pyjDBG_CXX, vprDBG_VERB_LVL,
         "vrj_opensg_App_Wrapper::configRemove()\n",
         "vrj_opensg_App_Wrapper::configRemove() done.\n"
      );
      PyJuggler::InterpreterGuard guard;

      try
      {
         if ( override configRemove = this->get_override("configRemove") )
         {
            return configRemove(p0);
         }
         return vrj::opensg::App::configRemove(p0);
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }

      return false;
   }

   bool default_configRemove(jccl::ConfigElementPtr p0)
   {
      return vrj::opensg::App::configRemove(p0);
   }

   int configProcessPending()
   {
      vpr::DebugOutputGuard og(
         pyjDBG_CXX, vprDBG_VERB_LVL,
         "vrj_opensg_App_Wrapper::configProcessPending()\n",
         "vrj_opensg_App_Wrapper::configProcessPending() done.\n"
      );
      PyJuggler::InterpreterGuard guard;

      try
      {
         if ( override configProcessPending =
                 this->get_override("configProcessPending") )
         {
            return configProcessPending();
         }
         return vrj::opensg::App::configProcessPending();
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }

      return 0;
   }

   int default_configProcessPending()
   {
      return vrj::opensg::App::configProcessPending();
   }

   vrj::opensg::App::context_data& getContextData()
   {
      return *mContextData;
   }

   void setContextData(vrj::opensg::App::context_data* data)
   {
      *mContextData = *data;
   }

   OSG::UInt32 getMainAspectID() const
   {
      return OSG_MAIN_ASPECT_ID;
   }

   void setMainAspectID(const OSG::UInt32 id)
   {
      OSG_MAIN_ASPECT_ID = id;
   }
};


}// namespace pyj


// Module ======================================================================
void _Export_App()
{
   scope* vrj_opensg_App_scope = new scope(
   class_<pyj::vrj_opensg_App_Wrapper, bases<vrj::opengl::App>, boost::noncopyable>
      ("App",
       "vrj.opensgA.pp encapsulates an OpenSG application. This defines the\n"
       "base class from which OpenSG-based application objects should be\n"
       "derived. It makes use of the OpenGL Draw Manager.\n\n"
       "To use OpenSG with Python and this class, use PyOpenSG. PyOpenSG is\n"
       "also written using Boost.Python, so instances of PyOpenSG objects\n"
       "can be passed into methods of this class without compatibility\n"
       "problems.\n\n"
       "See: vrj.opengl.App"
       ,
       init< optional<vrj::Kernel*> >(
          "__init__()\n"
          "Default constructor.  Uses vrj.Kernel.instance().\n\n"
          "__init__(kernel)\n"
          "Arguments:\n"
          "kernel -- The vrj.Kernel instance that is active (so the\n"
          "          application has easy access to the kernel)."
       )
      )
      .def_readwrite("mKernel", &vrj::App::mKernel)
      .def_readwrite("mHaveFocus", &vrj::App::mHaveFocus)
      .add_property("OSG_MAIN_ASPECT_ID",
                    &pyj::vrj_opensg_App_Wrapper::getMainAspectID,
                    &pyj::vrj_opensg_App_Wrapper::setMainAspectID
      )
      .def("initScene", pure_virtual(&vrj::opensg::App::initScene),
           "initScene()\n"
           "Initializes the scene.  Called by init() to initialize the\n"
           "scene."
      )
      .def("getScene", pure_virtual(&vrj::opensg::App::getScene),
           "getScene() -> osg.Group object\n"
           "Gets the root fo the scene to render.  Called each frame to\n"
           "get teh current scene to render."
      )
      .def("draw", &vrj::opensg::App::draw,
           &pyj::vrj_opensg_App_Wrapper::default_draw,
           "draw()\n"
           "Function to draw the scene.  Override this method with great\n"
           "create.  All the logic to handle multi-pipe rendering and\n"
           "other VR Juggler features happens here.\n\n"
           "Pre-conditions:\n"
           "OpenGL state has correct transformation and buffer selected.\n\n"
           "Post-conditions:\n"
           "The current sceen has been drawn."
      )
      .def("init", &vrj::opensg::App::init,
           &pyj::vrj_opensg_App_Wrapper::default_init,
           "init()\n"
           "Application initialization function.  Execute any\n"
           "initialization needed before the graphics API is started.  If\n"
           "this method is overridden, it must be called by the overriding\n"
           "version.  This calls initScene(), which is used to set up this\n"
           "application object's scene graph.\n\n"
           "Note:\n"
           "Derived classes MUST call the base class version of this\n"
           "method."
      )
      .def("contextInit", &vrj::opensg::App::contextInit,
           &pyj::vrj_opensg_App_Wrapper::default_contextInit,
           "contextInit()\n"
           "Function that is called immediately after a new context is\n"
           "created.  Use this function to create context-specific data\n"
           "structures such as display lists and texture objects that are\n"
           "known to be required when the context is created.\n\n"
           "Pre-condition:\n"
           "The OpenGL context has been set to the new context.\n\n"
           "Post-condition:\n"
           "The application has completed context-specific initialization."
      )
      .def("contextClose", &vrj::opensg::App::contextClose,
           &pyj::vrj_opensg_App_Wrapper::default_contextClose,
           "contextClose()\n"
           "Function that is called immediately before a context is closed.\n"
           "Use this function to clean up any context-specific data\n"
           "structures."
      )
      .def("contextPreDraw", &vrj::opensg::App::contextPreDraw,
           &pyj::vrj_opensg_App_Wrapper::default_contextPreDraw,
           "contextPreDraw()\n"
           "Function that is called upon entry into the context before\n"
           "rendering begins.  This can be used to allocate\n"
           "context-specific data dynamically.\n\n"
           "Pre-conditions:\n"
           "The OpenGL context has been set to the context for drawing.\n\n"
           "Post-conditins:\n"
           "The application object has executed any commands that need to\n"
           "be executed only once per context, per frame.\n\n"
           "This function can be used for things that need to happen every\n"
           "frame but only once per context."
      )
      .def("bufferPreDraw", &vrj::opensg::App::bufferPreDraw,
           &pyj::vrj_opensg_App_Wrapper::default_bufferPreDraw,
           "bufferPreDraw()\n"
           "Function that is called once for each frame buffer of an\n"
           "OpenGL context.  This function is executed after contextInit()\n"
           "(if neede) but before contextPreDraw().  It is called once\n"
           "per frame buffer (see note below).\n\n"
           "Pre-conditions:\n"
           "The OpenGL context has been set to the context for drawing.\n\n"
           "Post-conditions:\n"
           "The application object has executed any commands that need to\n"
           "be executed once per context, per buffer, per frame.\n\n"
           "Note:\n"
           "This function is designed to be used when some task must be\n"
           "performed only once per frame buffer (i.e., once for the left\n"
           "tbuffer, once for the right buffer).  For example, the OpenGL\n"
           "clear color should be defined and glClear(GL_COLOR_BUFFER_BIT)\n"
           "should be called in this method."
      )
      .def("pipePreDraw", &vrj::opensg::App::pipePreDraw,
           &pyj::vrj_opensg_App_Wrapper::default_pipePreDraw,
           "pipePreDraw()\n"
           "Function that is called at the beginning of the drawing of eacn\n"
           "pipe.\n\n"
           "Pre-conditions:\n"
           "The library is preparing to render all windows on a given\n"
           "pipe.\n\n"
           "Post-conditions:\n"
           "Any pre-pipe user calls have been done.\n\n"
           "Note:\n"
           "Currently the OpenGL context is not set when this function is\n"
           "called.  This is a TEST function.  USE AT YOUR OWN RISK!"
      )
      .def("contextPostDraw", &vrj::opensg::App::contextPostDraw,
           &pyj::vrj_opensg_App_Wrapper::default_contextPostDraw,
           "contextPostDraw()\n"
           "Function that is called upon exit of the context after\n"
           "rendering\n\n"
           "Pre-conditions:\n"
           "The OpenGL context has been set to the context for drawing."
      )
      .def("apiInit", &vrj::opensg::App::apiInit,
           &pyj::vrj_opensg_App_Wrapper::default_apiInit,
           "apiInit()\n"
           "Application graphics API initialization function.  Execute any\n"
           "initialization needed after the graphics API is started but\n"
           "before the Draw Manager starts the rendering loop(s)."
      )
      .def("exit", &vrj::opensg::App::exit,
           &pyj::vrj_opensg_App_Wrapper::default_exit,
           "exit()\n"
           "Executes any final clean-up needed for the application before\n"
           "exiting."
      )
      .def("preFrame", &vrj::opensg::App::preFrame,
           &pyj::vrj_opensg_App_Wrapper::default_preFrame,
           "preFrame()\n"
           "Function called before the Juggler frame starts.  This is\n"
           "called after input device updates but before the start of a\n"
           "new frame."
      )
      .def("latePreFrame", &vrj::opensg::App::latePreFrame,
           &pyj::vrj_opensg_App_Wrapper::default_latePreFrame,
           "latePreFrame()\n"
           "Function called after preFrame() and application-specific data\n"
           "synchronization (in a cluster conifguration) but before the\n"
           "start of a new frame.\n\n"
           "Note:\n"
           "This is required because we cannot update data during the\n"
           "rendering process since it might be using multiple threads."
      )
      .def("intraFrame", &vrj::opensg::App::intraFrame,
           &pyj::vrj_opensg_App_Wrapper::default_intraFrame,
           "intraFrame()\n"
           "Function called during the application's drawing time."
      )
      .def("postFrame", &vrj::opensg::App::postFrame,
           &pyj::vrj_opensg_App_Wrapper::default_postFrame,
           "postFrame()\n"
           "Function alled before updating input devices but after the\n"
           "frame is complete."
      )
      .def("reset", &vrj::opensg::App::reset,
           &pyj::vrj_opensg_App_Wrapper::default_reset,
           "reset()\n"
           "Resets the application.  This is used when the kernel (or\n"
           "applications would like this application to reset to its\n"
           "initial state."
      )
      .def("focusChanged", &vrj::opensg::App::focusChanged,
           &pyj::vrj_opensg_App_Wrapper::default_focusChanged,
           "focusChanged()\n"
           "Called when the focus state changes."
      )
      .def("getDrawScaleFactor", &vrj::opensg::App::getDrawScaleFactor,
           &pyj::vrj_opensg_App_Wrapper::default_getDrawScaleFactor,
           "getDrawScaleFactor() -> float\n"
           "Returns the scale factor to convert from Juggler units\n"
           "(meters) to application units.  Internally, VR Juggler stores\n"
           "and processes all position values in meterrs.  The scale\n"
           "factor returned by this method is used by VR Juggler to scale\n"
           "the rendering state from meters to whatever units this\n"
           "application wants to use.  For example, to render in feet,\n"
           "return 3.28 (gadget.PositionUnitConversion.ConvertToFeet)."
      )
      .def("configCanHandle", &vrj::opensg::App::configCanHandle,
           &pyj::vrj_opensg_App_Wrapper::default_configCanHandle,
           "configCanHandle(element) -> Boolean\n"
           "Defaults to handling nothing.\n\n"
           "Arguments:\n"
           "element -- An instance of jccl.ConfigElement."
      )
      .def("depSatisfied", &vrj::opensg::App::depSatisfied,
           &pyj::vrj_opensg_App_Wrapper::default_depSatisfied,
           "depSatisfied() -> Boolean\n"
           "Are any application dependencies satisified?  If this\n"
           "application requires anything special of the system for\n"
           "successful initialization, check it here.  If the return value\n"
           "is False, then this application will not be started yet.  If\n"
           "the return value is True, this application will be allowed to\n"
           "enter the system."
      )
      .def("configProcessPending",
           &jccl::ConfigElementHandler::configProcessPending,
           &pyj::vrj_opensg_App_Wrapper::default_configProcessPending,
           "configProcessPending() -> int\n"
           "Inherited from jccl.ConfigElementHandler and not overridden."
      )
      .def("haveFocus", &vrj::opensg::App::haveFocus,
           "haveFocus() -> Boolean\n"
           "Does this application currently have focus?  If an application\n"
           "has focus, the user may be attempting to interact with it, so\n"
           "the application should process input.  If not, the user is\n"
           "not interacting with it, so ignore all input.  However, the\n"
           "user may still be viewing the application, so render, update\n"
           "animations, etc.  This is akin to the way that a user can only\n"
           "interact with a GUI window that has focus."
      )
      .def("setFocus", &vrj::opensg::App::setFocus,
           "setFocus(newState)\n"
           "Sets the focus state.\n\n"
           "Post-condition:\n"
           "If the focus state has changed, then focusChanged() is\n"
           "called.\n\n"
           "Arguments:\n"
           "newState -- A Boolean value indicating whether this application\n"
           "            now has focus."
      )
      .def("getContextData",
           &pyj::vrj_opensg_App_Wrapper::getContextData,
           return_internal_reference<1>(),
           "getContextData() -> vrj.OpenSGApp.context_data\n"
           "Returns a reference to the context-specific internal mContextData\n"
           "object. The data members of that object can then be modified\n"
           "directly. This data can only be accessed from the OpenGL context\n"
           "interfaces methods."
      )
      .def("setContextData",
           &pyj::vrj_opensg_App_Wrapper::setContextData,
           "setContextData(vrj.OpenSGApp.context_data)\n"
           "Replaces the internal context-specific internal mContextData\n"
           "object with the given object. This data can only be replaced from\n"
           "the OpenGL context interface methods."
      )
   );

   class_<vrj::opensg::App::context_data>("context_data", init<>()
      )
      .def_readwrite("mRenderAction",
                     &vrj::opensg::App::context_data::mRenderAction)
      .def_readwrite("mWin", &vrj::opensg::App::context_data::mWin)
      .def_readwrite("mViewport", &vrj::opensg::App::context_data::mViewport)
      .def_readwrite("mBackground",
                     &vrj::opensg::App::context_data::mBackground)
      .def_readwrite("mCamera", &vrj::opensg::App::context_data::mCamera)
      .def_readwrite("mContextThreadInitialized",
                     &vrj::opensg::App::context_data::mContextThreadInitialized)
      .def_readwrite("mOsgThread", &vrj::opensg::App::context_data::mOsgThread)
   ;

   delete vrj_opensg_App_scope;
}
