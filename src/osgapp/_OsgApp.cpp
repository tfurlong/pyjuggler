// PyJuggler is (C) Copyright 2002-2004 by Patrick Hartling
// Distributed under the GNU Lesser General Public License 2.1.  (See
// accompanying file COPYING.txt or http://www.gnu.org/copyleft/lesser.txt)

// File:          $RCSfile$
// Date modified: $Date$
// Version:       $Revision$

// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <vrj/Draw/OSG/OsgApp.h>
#include <vrj/Kernel/Kernel.h>
#include <pyjutil/InterpreterGuard.h>
#include <pyjutil/Debug.h>

// Using =======================================================================
using namespace boost::python;

// Declarations ================================================================
namespace pyj {

struct vrj_OsgApp_Wrapper: vrj::OsgApp
{
    vrj_OsgApp_Wrapper(PyObject* self_, vrj::Kernel* p0):
        vrj::OsgApp(p0), self(self_) {}

    vrj_OsgApp_Wrapper(PyObject* self_):
        vrj::OsgApp(), self(self_) {}

    virtual ~vrj_OsgApp_Wrapper()
    {
    }

    void initScene() {
        vpr::DebugOutputGuard og(pyjDBG_CXX, vprDBG_VERB_LVL,
                                 "vrj_OsgApp_Wrapper::initScene()\n",
                                 "vrj_OsgApp_Wrapper::initScene() done.\n");
        PyJuggler::InterpreterGuard guard;

        try
        {
            call_method< void >(self, "initScene");
        }
        catch(error_already_set)
        {
            PyErr_Print();
        }
    }

    osg::Group* getScene() {
        vpr::DebugOutputGuard og(pyjDBG_CXX, vprDBG_VERB_LVL,
                                 "vrj_OsgApp_Wrapper::getScene()\n",
                                 "vrj_OsgApp_Wrapper::getScene() done.\n");
        PyJuggler::InterpreterGuard guard;

        try
        {
            return call_method< osg::Group* >(self, "getScene");
        }
        catch(error_already_set)
        {
            PyErr_Print();
        }

        return NULL;
    }

/*
    void configSceneView(osgUtil::SceneView* p0) {
        vpr::DebugOutputGuard og(pyjDBG_CXX, vprDBG_VERB_LVL,
                                 "vrj_OsgApp_Wrapper::configSceneView()\n",
                                 "vrj_OsgApp_Wrapper::configSceneView() done.\n");
        PyJuggler::InterpreterGuard guard;

        try
        {
            call_method< void >(self, "configSceneView", p0);
        }
        catch(error_already_set)
        {
            PyErr_Print();
        }
    }

    void default_configSceneView(osgUtil::SceneView* p0) {
        vrj::OsgApp::configSceneView(p0);
    }
*/

    void draw() {
        vpr::DebugOutputGuard og(pyjDBG_CXX, vprDBG_VERB_LVL,
                                 "vrj_OsgApp_Wrapper::draw()\n",
                                 "vrj_OsgApp_Wrapper::draw() done.\n");
        PyJuggler::InterpreterGuard guard;

        try
        {
            call_method< void >(self, "draw");
        }
        catch(error_already_set)
        {
            PyErr_Print();
        }
    }

    void default_draw() {
        vrj::OsgApp::draw();
    }

    void init() {
        vpr::DebugOutputGuard og(pyjDBG_CXX, vprDBG_VERB_LVL,
                                 "vrj_OsgApp_Wrapper::init()\n",
                                 "vrj_OsgApp_Wrapper::init() done.\n");
        PyJuggler::InterpreterGuard guard;

        try
        {
            call_method< void >(self, "init");
        }
        catch(error_already_set)
        {
            PyErr_Print();
        }
    }

    void default_init() {
        vrj::OsgApp::init();
    }

    void contextInit() {
        vpr::DebugOutputGuard og(pyjDBG_CXX, vprDBG_VERB_LVL,
                                 "vrj_OsgApp_Wrapper::contextInit()\n",
                                 "vrj_OsgApp_Wrapper::contextInit() done.\n");
        PyJuggler::InterpreterGuard guard;

        try
        {
            call_method< void >(self, "contextInit");
        }
        catch(error_already_set)
        {
            PyErr_Print();
        }
    }

    void default_contextInit() {
        vrj::OsgApp::contextInit();
    }

    void contextClose() {
        vpr::DebugOutputGuard og(pyjDBG_CXX, vprDBG_VERB_LVL,
                                 "vrj_OsgApp_Wrapper::contextClose()\n",
                                 "vrj_OsgApp_Wrapper::contextClose() done.\n");
        PyJuggler::InterpreterGuard guard;

        try
        {
            call_method< void >(self, "contextClose");
        }
        catch(error_already_set)
        {
            PyErr_Print();
        }
    }

    void default_contextClose() {
        vrj::OsgApp::contextClose();
    }

    void contextPreDraw() {
        vpr::DebugOutputGuard og(pyjDBG_CXX, vprDBG_VERB_LVL,
                                 "vrj_OsgApp_Wrapper::contextPreDraw()\n",
                                 "vrj_OsgApp_Wrapper::contextPreDraw() done.\n");
        PyJuggler::InterpreterGuard guard;

        try
        {
            call_method< void >(self, "contextPreDraw");
        }
        catch(error_already_set)
        {
            PyErr_Print();
        }
    }

    void default_contextPreDraw() {
        vrj::OsgApp::contextPreDraw();
    }

    void bufferPreDraw() {
        vpr::DebugOutputGuard og(pyjDBG_CXX, vprDBG_VERB_LVL,
                                 "vrj_OsgApp_Wrapper::bufferPreDraw()\n",
                                 "vrj_OsgApp_Wrapper::bufferPreDraw() done.\n");
        PyJuggler::InterpreterGuard guard;

        try
        {
            call_method< void >(self, "bufferPreDraw");
        }
        catch(error_already_set)
        {
            PyErr_Print();
        }
    }

    void default_bufferPreDraw() {
        vrj::OsgApp::bufferPreDraw();
    }

    void pipePreDraw() {
        vpr::DebugOutputGuard og(pyjDBG_CXX, vprDBG_VERB_LVL,
                                 "vrj_OsgApp_Wrapper::pipePreDraw()\n",
                                 "vrj_OsgApp_Wrapper::pipePreDraw() done.\n");
        PyJuggler::InterpreterGuard guard;

        try
        {
            call_method< void >(self, "pipePreDraw");
        }
        catch(error_already_set)
        {
            PyErr_Print();
        }
    }

    void default_pipePreDraw() {
        vrj::OsgApp::pipePreDraw();
    }

    void contextPostDraw() {
        vpr::DebugOutputGuard og(pyjDBG_CXX, vprDBG_VERB_LVL,
                                 "vrj_OsgApp_Wrapper::contextPostDraw()\n",
                                 "vrj_OsgApp_Wrapper::contextPostDraw() done.\n");
        PyJuggler::InterpreterGuard guard;

        try
        {
            call_method< void >(self, "contextPostDraw");
        }
        catch(error_already_set)
        {
            PyErr_Print();
        }
    }

    void default_contextPostDraw() {
        vrj::GlApp::contextPostDraw();
    }

    void apiInit() {
        vpr::DebugOutputGuard og(pyjDBG_CXX, vprDBG_VERB_LVL,
                                 "vrj_OsgApp_Wrapper::apiInit()\n",
                                 "vrj_OsgApp_Wrapper::apiInit() done.\n");
        PyJuggler::InterpreterGuard guard;

        try
        {
            call_method< void >(self, "apiInit");
        }
        catch(error_already_set)
        {
            PyErr_Print();
        }
    }

    void default_apiInit() {
        vrj::App::apiInit();
    }

    void exit() {
        vpr::DebugOutputGuard og(pyjDBG_CXX, vprDBG_VERB_LVL,
                                 "vrj_OsgApp_Wrapper::exit()\n",
                                 "vrj_OsgApp_Wrapper::exit() done.\n");
        PyJuggler::InterpreterGuard guard;

        try
        {
            call_method< void >(self, "exit");
        }
        catch(error_already_set)
        {
            PyErr_Print();
        }
    }

    void default_exit() {
        vrj::App::exit();
    }

    void preFrame() {
        vpr::DebugOutputGuard og(pyjDBG_CXX, vprDBG_VERB_LVL,
                                 "vrj_OsgApp_Wrapper::preFrame()\n",
                                 "vrj_OsgApp_Wrapper::preFrame() done.\n");
        PyJuggler::InterpreterGuard guard;

        try
        {
            call_method< void >(self, "preFrame");
        }
        catch(error_already_set)
        {
            PyErr_Print();
        }
    }

    void default_preFrame() {
        vrj::App::preFrame();
    }

    void latePreFrame() {
        vpr::DebugOutputGuard og(pyjDBG_CXX, vprDBG_VERB_LVL,
                                 "vrj_OsgApp_Wrapper::latePreFrame()\n",
                                 "vrj_OsgApp_Wrapper::latePreFrame() done.\n");
        PyJuggler::InterpreterGuard guard;

        try
        {
            call_method< void >(self, "latePreFrame");
        }
        catch(error_already_set)
        {
            PyErr_Print();
        }
    }

    void default_latePreFrame() {
        vrj::App::latePreFrame();
    }

    void intraFrame() {
        vpr::DebugOutputGuard og(pyjDBG_CXX, vprDBG_VERB_LVL,
                                 "vrj_OsgApp_Wrapper::intraFrame()\n",
                                 "vrj_OsgApp_Wrapper::intraFrame() done.\n");
        PyJuggler::InterpreterGuard guard;

        try
        {
            call_method< void >(self, "intraFrame");
        }
        catch(error_already_set)
        {
            PyErr_Print();
        }
    }

    void default_intraFrame() {
        vrj::App::intraFrame();
    }

    void postFrame() {
        vpr::DebugOutputGuard og(pyjDBG_CXX, vprDBG_VERB_LVL,
                                 "vrj_OsgApp_Wrapper::postFrame()\n",
                                 "vrj_OsgApp_Wrapper::postFrame() done.\n");
        PyJuggler::InterpreterGuard guard;

        try
        {
            call_method< void >(self, "postFrame");
        }
        catch(error_already_set)
        {
            PyErr_Print();
        }
    }

    void default_postFrame() {
        vrj::App::postFrame();
    }

    void reset() {
        vpr::DebugOutputGuard og(pyjDBG_CXX, vprDBG_VERB_LVL,
                                 "vrj_OsgApp_Wrapper::reset()\n",
                                 "vrj_OsgApp_Wrapper::reset() done.\n");
        PyJuggler::InterpreterGuard guard;

        try
        {
            call_method< void >(self, "reset");
        }
        catch(error_already_set)
        {
            PyErr_Print();
        }
    }

    void default_reset() {
        vrj::App::reset();
    }

    void focusChanged() {
        vpr::DebugOutputGuard og(pyjDBG_CXX, vprDBG_VERB_LVL,
                                 "vrj_OsgApp_Wrapper::focusChanged()\n",
                                 "vrj_OsgApp_Wrapper::focusChanged() done.\n");
        PyJuggler::InterpreterGuard guard;

        try
        {
            call_method< void >(self, "focusChanged");
        }
        catch(error_already_set)
        {
            PyErr_Print();
        }
    }

    void default_focusChanged() {
        vrj::App::focusChanged();
    }

    float getDrawScaleFactor() {
        vpr::DebugOutputGuard og(pyjDBG_CXX, vprDBG_VERB_LVL,
                                 "vrj_OsgApp_Wrapper::getDrawScaleFactor()\n",
                                 "vrj_OsgApp_Wrapper::getDrawScaleFactor() done.\n");
        PyJuggler::InterpreterGuard guard;

        try
        {
            return call_method< float >(self, "getDrawScaleFactor");
        }
        catch(error_already_set)
        {
            PyErr_Print();
        }

        return 1.0f;
    }

    float default_getDrawScaleFactor() {
        return vrj::App::getDrawScaleFactor();
    }

    bool configCanHandle(jccl::ConfigElementPtr p0) {
        vpr::DebugOutputGuard og(pyjDBG_CXX, vprDBG_VERB_LVL,
                                 "vrj_OsgApp_Wrapper::configCanHandle()\n",
                                 "vrj_OsgApp_Wrapper::configCanHandle() done.\n");
        PyJuggler::InterpreterGuard guard;

        try
        {
            return call_method< bool >(self, "configCanHandle", p0);
        }
        catch(error_already_set)
        {
            PyErr_Print();
        }

        return false;
    }

    bool default_configCanHandle(jccl::ConfigElementPtr p0) {
        return vrj::App::configCanHandle(p0);
    }

    bool depSatisfied() {
        vpr::DebugOutputGuard og(pyjDBG_CXX, vprDBG_VERB_LVL,
                                 "vrj_OsgApp_Wrapper::depSatisfied()\n",
                                 "vrj_OsgApp_Wrapper::depSatisfied() done.\n");
        PyJuggler::InterpreterGuard guard;

        try
        {
            return call_method< bool >(self, "depSatisfied");
        }
        catch(error_already_set)
        {
            PyErr_Print();
        }

        return true;
    }

    bool default_depSatisfied() {
        return vrj::App::depSatisfied();
    }

    bool configAdd(jccl::ConfigElementPtr p0) {
        vpr::DebugOutputGuard og(pyjDBG_CXX, vprDBG_VERB_LVL,
                                 "vrj_OsgApp_Wrapper::configAdd()\n",
                                 "vrj_OsgApp_Wrapper::configAdd() done.\n");
        PyJuggler::InterpreterGuard guard;

        try
        {
            return call_method< bool >(self, "configAdd", p0);
        }
        catch(error_already_set)
        {
            PyErr_Print();
        }

        return false;
    }

    bool default_configAdd(jccl::ConfigElementPtr p0) {
        return vrj::App::configAdd(p0);
    }

    bool configRemove(jccl::ConfigElementPtr p0) {
        vpr::DebugOutputGuard og(pyjDBG_CXX, vprDBG_VERB_LVL,
                                 "vrj_OsgApp_Wrapper::configRemove()\n",
                                 "vrj_OsgApp_Wrapper::configRemove() done.\n");
        PyJuggler::InterpreterGuard guard;

        try
        {
            return call_method< bool >(self, "configRemove", p0);
        }
        catch(error_already_set)
        {
            PyErr_Print();
        }

        return false;
    }

    bool default_configRemove(jccl::ConfigElementPtr p0) {
        return vrj::App::configRemove(p0);
    }

    int configProcessPending() {
        vpr::DebugOutputGuard og(pyjDBG_CXX, vprDBG_VERB_LVL,
                                 "vrj_OsgApp_Wrapper::configProcessPending()\n",
                                 "vrj_OsgApp_Wrapper::configProcessPending() done.\n");
        PyJuggler::InterpreterGuard guard;

        try
        {
            return call_method< int >(self, "configProcessPending");
        }
        catch(error_already_set)
        {
            PyErr_Print();
        }

        return 0;
    }

    int default_configProcessPending() {
        return vrj::App::configProcessPending();
    }

    PyObject* self;
};


}// namespace pyj


// Module ======================================================================
void _Export_OsgApp()
{
    class_< vrj::OsgApp, bases< vrj::GlApp >, boost::noncopyable, pyj::vrj_OsgApp_Wrapper >("OsgApp", init<  >())
        .def(init< vrj::Kernel* >())
        .def_readwrite("mKernel", &vrj::App::mKernel)
        .def_readwrite("mHaveFocus", &vrj::App::mHaveFocus)
        .def("initScene", pure_virtual(&vrj::OsgApp::initScene))
        .def("getScene", pure_virtual(&vrj::OsgApp::getScene), return_internal_reference< 1 >())
//        .def("configSceneView", &vrj::OsgApp::configSceneView, &pyj::vrj_OsgApp_Wrapper::default_configSceneView)
        .def("draw", (void (vrj::OsgApp::*)() )&vrj::OsgApp::draw, (void (pyj::vrj_OsgApp_Wrapper::*)())&pyj::vrj_OsgApp_Wrapper::default_draw)
        .def("init", (void (vrj::OsgApp::*)() )&vrj::OsgApp::init, (void (pyj::vrj_OsgApp_Wrapper::*)())&pyj::vrj_OsgApp_Wrapper::default_init)
        .def("contextInit", (void (vrj::OsgApp::*)() )&vrj::OsgApp::contextInit, (void (pyj::vrj_OsgApp_Wrapper::*)())&pyj::vrj_OsgApp_Wrapper::default_contextInit)
        .def("contextClose", (void (vrj::OsgApp::*)() )&vrj::OsgApp::contextClose, (void (pyj::vrj_OsgApp_Wrapper::*)())&pyj::vrj_OsgApp_Wrapper::default_contextClose)
        .def("contextPreDraw", (void (vrj::OsgApp::*)() )&vrj::OsgApp::contextPreDraw, (void (pyj::vrj_OsgApp_Wrapper::*)())&pyj::vrj_OsgApp_Wrapper::default_contextPreDraw)
        .def("bufferPreDraw", (void (vrj::OsgApp::*)() )&vrj::OsgApp::bufferPreDraw, (void (pyj::vrj_OsgApp_Wrapper::*)())&pyj::vrj_OsgApp_Wrapper::default_bufferPreDraw)
        .def("pipePreDraw", (void (vrj::OsgApp::*)() )&vrj::OsgApp::pipePreDraw, (void (pyj::vrj_OsgApp_Wrapper::*)())&pyj::vrj_OsgApp_Wrapper::default_pipePreDraw)
        .def("contextPostDraw", (void (vrj::GlApp::*)() )&vrj::GlApp::contextPostDraw, (void (pyj::vrj_OsgApp_Wrapper::*)())&pyj::vrj_OsgApp_Wrapper::default_contextPostDraw)
        .def("apiInit", (void (vrj::App::*)() )&vrj::App::apiInit, (void (pyj::vrj_OsgApp_Wrapper::*)())&pyj::vrj_OsgApp_Wrapper::default_apiInit)
        .def("exit", (void (vrj::App::*)() )&vrj::App::exit, (void (pyj::vrj_OsgApp_Wrapper::*)())&pyj::vrj_OsgApp_Wrapper::default_exit)
        .def("preFrame", (void (vrj::App::*)() )&vrj::App::preFrame, (void (pyj::vrj_OsgApp_Wrapper::*)())&pyj::vrj_OsgApp_Wrapper::default_preFrame)
        .def("latePreFrame", (void (vrj::App::*)() )&vrj::App::latePreFrame, (void (pyj::vrj_OsgApp_Wrapper::*)())&pyj::vrj_OsgApp_Wrapper::default_latePreFrame)
        .def("intraFrame", (void (vrj::App::*)() )&vrj::App::intraFrame, (void (pyj::vrj_OsgApp_Wrapper::*)())&pyj::vrj_OsgApp_Wrapper::default_intraFrame)
        .def("postFrame", (void (vrj::App::*)() )&vrj::App::postFrame, (void (pyj::vrj_OsgApp_Wrapper::*)())&pyj::vrj_OsgApp_Wrapper::default_postFrame)
        .def("reset", (void (vrj::App::*)() )&vrj::App::reset, (void (pyj::vrj_OsgApp_Wrapper::*)())&pyj::vrj_OsgApp_Wrapper::default_reset)
        .def("focusChanged", (void (vrj::App::*)() )&vrj::App::focusChanged, (void (pyj::vrj_OsgApp_Wrapper::*)())&pyj::vrj_OsgApp_Wrapper::default_focusChanged)
        .def("getDrawScaleFactor", (float (vrj::App::*)() )&vrj::App::getDrawScaleFactor, (float (pyj::vrj_OsgApp_Wrapper::*)())&pyj::vrj_OsgApp_Wrapper::default_getDrawScaleFactor)
        .def("configCanHandle", (bool (vrj::App::*)(jccl::ConfigElementPtr) )&vrj::App::configCanHandle, (bool (pyj::vrj_OsgApp_Wrapper::*)(jccl::ConfigElementPtr))&pyj::vrj_OsgApp_Wrapper::default_configCanHandle)
        .def("depSatisfied", (bool (vrj::App::*)() )&vrj::App::depSatisfied, (bool (pyj::vrj_OsgApp_Wrapper::*)())&pyj::vrj_OsgApp_Wrapper::default_depSatisfied)
        .def("configProcessPending", (int (jccl::ConfigElementHandler::*)() )&jccl::ConfigElementHandler::configProcessPending, (int (pyj::vrj_OsgApp_Wrapper::*)())&pyj::vrj_OsgApp_Wrapper::default_configProcessPending)
        .def("haveFocus", &vrj::App::haveFocus)
        .def("setFocus", &vrj::App::setFocus)
    ;

}
