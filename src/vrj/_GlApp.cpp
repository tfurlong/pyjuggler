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
#include <vrj/Draw/OGL/GlApp.h>
#include <vrj/Kernel/Kernel.h>
#include <pyjutil/InterpreterGuard.h>
#include <pyjutil/Debug.h>

// Using =======================================================================
using namespace boost::python;

// Declarations ================================================================
namespace pyj {

struct vrj_GlApp_Wrapper: vrj::GlApp
{
    vrj_GlApp_Wrapper(PyObject* self_, const vrj::GlApp& p0):
        vrj::GlApp(p0), self(self_) {}

    vrj_GlApp_Wrapper(PyObject* self_, vrj::Kernel* p0):
        vrj::GlApp(p0), self(self_) {}

    vrj_GlApp_Wrapper(PyObject* self_):
        vrj::GlApp(), self(self_) {}

    virtual ~vrj_GlApp_Wrapper()
    {
    }

    void draw() {
        vpr::DebugOutputGuard og(pyjDBG_CXX, vprDBG_VERB_LVL,
                                 "vrj_GlApp_Wrapper::draw()\n",
                                 "vrj_GlApp_Wrapper::draw() done.\n");
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

    void contextInit() {
        vpr::DebugOutputGuard og(pyjDBG_CXX, vprDBG_VERB_LVL,
                                 "vrj_GlApp_Wrapper::contextInit()\n",
                                 "vrj_GlApp_Wrapper::contextInit() done.\n");
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
        vrj::GlApp::contextInit();
    }

    void contextClose() {
        vpr::DebugOutputGuard og(pyjDBG_CXX, vprDBG_VERB_LVL,
                                 "vrj_GlApp_Wrapper::contextClose()\n",
                                 "vrj_GlApp_Wrapper::contextClose() done.\n");
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
        vrj::GlApp::contextClose();
    }

    void contextPreDraw() {
        vpr::DebugOutputGuard og(pyjDBG_CXX, vprDBG_VERB_LVL,
                                 "vrj_GlApp_Wrapper::contextPreDraw()\n",
                                 "vrj_GlApp_Wrapper::contextPreDraw() done.\n");
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
        vrj::GlApp::contextPreDraw();
    }

    void contextPostDraw() {
        vpr::DebugOutputGuard og(pyjDBG_CXX, vprDBG_VERB_LVL,
                                 "vrj_GlApp_Wrapper::contextPostDraw()\n",
                                 "vrj_GlApp_Wrapper::contextPostDraw() done.\n");
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

    void bufferPreDraw() {
        vpr::DebugOutputGuard og(pyjDBG_CXX, vprDBG_VERB_LVL,
                                 "vrj_GlApp_Wrapper::bufferPreDraw()\n",
                                 "vrj_GlApp_Wrapper::bufferPreDraw() done.\n");
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
        vrj::GlApp::bufferPreDraw();
    }

    void pipePreDraw() {
        vpr::DebugOutputGuard og(pyjDBG_CXX, vprDBG_VERB_LVL,
                                 "vrj_GlApp_Wrapper::pipePreDraw()\n",
                                 "vrj_GlApp_Wrapper::pipePreDraw() done.\n");
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
        vrj::GlApp::pipePreDraw();
    }

    void init() {
        vpr::DebugOutputGuard og(pyjDBG_CXX, vprDBG_VERB_LVL,
                                 "vrj_GlApp_Wrapper::init()\n",
                                 "vrj_GlApp_Wrapper::init() done.\n");
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
        vrj::App::init();
    }

    void apiInit() {
        vpr::DebugOutputGuard og(pyjDBG_CXX, vprDBG_VERB_LVL,
                                 "vrj_GlApp_Wrapper::apiInit()\n",
                                 "vrj_GlApp_Wrapper::apiInit() done.\n");
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
                                 "vrj_GlApp_Wrapper::exit()\n",
                                 "vrj_GlApp_Wrapper::exit() done.\n");
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
                                 "vrj_GlApp_Wrapper::preFrame()\n",
                                 "vrj_GlApp_Wrapper::preFrame() done.\n");
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
                                 "vrj_GlApp_Wrapper::latePreFrame()\n",
                                 "vrj_GlApp_Wrapper::latePreFrame() done.\n");
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
                                 "vrj_GlApp_Wrapper::intraFrame()\n",
                                 "vrj_GlApp_Wrapper::intraFrame() done.\n");
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
                                 "vrj_GlApp_Wrapper::postFrame()\n",
                                 "vrj_GlApp_Wrapper::postFrame() done.\n");
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
                                 "vrj_GlApp_Wrapper::reset()\n",
                                 "vrj_GlApp_Wrapper::reset() done.\n");
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
                                 "vrj_GlApp_Wrapper::focusChanged()\n",
                                 "vrj_GlApp_Wrapper::focusChanged() done.\n");
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
                                 "vrj_GlApp_Wrapper::getDrawScaleFactor()\n",
                                 "vrj_GlApp_Wrapper::getDrawScaleFactor() done.\n");
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
                                 "vrj_GlApp_Wrapper::configCanHandle()\n",
                                 "vrj_GlApp_Wrapper::configCanHandle() done.\n");
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
                                 "vrj_GlApp_Wrapper::depSatisfied()\n",
                                 "vrj_GlApp_Wrapper::depSatisfied() done.\n");
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
                                 "vrj_GlApp_Wrapper::configAdd()\n",
                                 "vrj_GlApp_Wrapper::configAdd() done.\n");
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
                                 "vrj_GlApp_Wrapper::configRemove()\n",
                                 "vrj_GlApp_Wrapper::configRemove() done.\n");
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
                                 "vrj_GlApp_Wrapper::configProcessPending()\n",
                                 "vrj_GlApp_Wrapper::configProcessPending() done.\n");
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
        return jccl::ConfigElementHandler::configProcessPending();
    }

    PyObject* self;
};

}// namespace 


// Module ======================================================================
void _Export_GlApp()
{
    class_< vrj::GlApp, bases< vrj::App >, boost::noncopyable, pyj::vrj_GlApp_Wrapper >("GlApp", init<  >())
        .def(init< vrj::Kernel* >())
        .def("draw", pure_virtual(&vrj::GlApp::draw))
        .def("contextInit", &vrj::GlApp::contextInit, &pyj::vrj_GlApp_Wrapper::default_contextInit)
        .def("contextClose", &vrj::GlApp::contextClose, &pyj::vrj_GlApp_Wrapper::default_contextClose)
        .def("contextPreDraw", &vrj::GlApp::contextPreDraw, &pyj::vrj_GlApp_Wrapper::default_contextPreDraw)
        .def("contextPostDraw", &vrj::GlApp::contextPostDraw, &pyj::vrj_GlApp_Wrapper::default_contextPostDraw)
        .def("bufferPreDraw", &vrj::GlApp::bufferPreDraw, &pyj::vrj_GlApp_Wrapper::default_bufferPreDraw)
        .def("pipePreDraw", &vrj::GlApp::pipePreDraw, &pyj::vrj_GlApp_Wrapper::default_pipePreDraw)
        .def("init", &vrj::App::init, &pyj::vrj_GlApp_Wrapper::default_init)
        .def("apiInit", &vrj::App::apiInit, &pyj::vrj_GlApp_Wrapper::default_apiInit)
        .def("exit", &vrj::App::exit, &pyj::vrj_GlApp_Wrapper::default_exit)
        .def("preFrame", &vrj::App::preFrame, &pyj::vrj_GlApp_Wrapper::default_preFrame)
        .def("latePreFrame", &vrj::App::latePreFrame, &pyj::vrj_GlApp_Wrapper::default_latePreFrame)
        .def("intraFrame", &vrj::App::intraFrame, &pyj::vrj_GlApp_Wrapper::default_intraFrame)
        .def("postFrame", &vrj::App::postFrame, &pyj::vrj_GlApp_Wrapper::default_postFrame)
        .def("reset", &vrj::App::reset, &pyj::vrj_GlApp_Wrapper::default_reset)
        .def("focusChanged", &vrj::App::focusChanged, &pyj::vrj_GlApp_Wrapper::default_focusChanged)
        .def("getDrawScaleFactor", &vrj::App::getDrawScaleFactor, &pyj::vrj_GlApp_Wrapper::default_getDrawScaleFactor)
        .def("configCanHandle", (bool (vrj::App::*)(jccl::ConfigElementPtr) )&vrj::App::configCanHandle, (bool (pyj::vrj_GlApp_Wrapper::*)(jccl::ConfigElementPtr))&pyj::vrj_GlApp_Wrapper::default_configCanHandle)
        .def("depSatisfied", &vrj::App::depSatisfied, &pyj::vrj_GlApp_Wrapper::default_depSatisfied)
        .def("configProcessPending", &jccl::ConfigElementHandler::configProcessPending, &pyj::vrj_GlApp_Wrapper::default_configProcessPending)
    ;

}
