
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <vrj/Kernel/UserPtr.h>
#include <vrj/Kernel/User.h>
#include <vrj/Display/ProjectionPtr.h>
#include <vrj/Display/Projection.h>
#include <vrj/Display/ViewportPtr.h>
#include <vrj/Display/Viewport.h>
#include <vrj/Draw/OpenGL/Config.h>
#include <vrj/Draw/OpenGL/WindowPtr.h>
#include <vrj/Draw/OpenGL/Window.h>
#include <vrj/Draw/OpenGL/UserData.h>

#include <pyjutil/InterpreterGuard.h>
#include <pyjutil/Debug.h>

// Using =======================================================================
using namespace boost::python;
namespace bp = boost::python;

namespace pyj {

struct vrj_opengl_UserData_Wrapper
   : vrj::opengl::UserData,
   wrapper<vrj::opengl::UserData> {

   virtual ~vrj_opengl_UserData_Wrapper() {
      /* Do nothing. */
   }

   const vrj::UserPtr getUser() const {
      vpr::DebugOutputGuard og(
         pyjDBG_CXX, vprDBG_VERB_LVL,
         "vrj_opengl_UserData_Wrapper::getUser()\n",
         "vrj_opengl_UserData_Wrapper::getUser() done.\n"
      );
      PyJuggler::InterpreterGuard guard;

      try {
         if ( bp::override getUser = this->get_override("getUser") ) {
            return getUser();
         } else {
            return vrj::opengl::UserData::getUser();
         }
      }
      catch (error_already_set) {
         PyErr_Print();
      }
   }

   const vrj::UserPtr default_getUser() const {
      return vrj::opengl::UserData::getUser();
   }

   void setUser(vrj::UserPtr user) {
      vpr::DebugOutputGuard og(
         pyjDBG_CXX, vprDBG_VERB_LVL,
         "vrj_opengl_UserData_Wrapper::setUser()\n",
         "vrj_opengl_UserData_Wrapper::setUser() done.\n"
      );
      PyJuggler::InterpreterGuard guard;

      try {
         if ( bp::override setUser = this->get_override("setUser") ) {
            setUser(user);
         } else {
            vrj::opengl::UserData::setUser(user);
         }
      }
      catch (error_already_set) {
         PyErr_Print();
      }
   }

   void default_setUser(vrj::UserPtr user) {
      vrj::opengl::UserData::setUser(user);
   }

   const vrj::ProjectionPtr getProjection() const {
      vpr::DebugOutputGuard og(
         pyjDBG_CXX, vprDBG_VERB_LVL,
         "vrj_opengl_UserData_Wrapper::getProjection()\n",
         "vrj_opengl_UserData_Wrapper::getProjection() done.\n"
      );
      PyJuggler::InterpreterGuard guard;

      try {
         if ( bp::override getProjection = this->get_override("getProjection") ) {
            return getProjection();
         } else {
            return vrj::opengl::UserData::getProjection();
         }
      }
      catch (error_already_set) {
         PyErr_Print();
      }
   }

   const vrj::ProjectionPtr default_getProjection() const {
      return vrj::opengl::UserData::getProjection();
   }

   void setProjection(vrj::ProjectionPtr proj) {
      vpr::DebugOutputGuard og(
         pyjDBG_CXX, vprDBG_VERB_LVL,
         "vrj_opengl_UserData_Wrapper::setProjection()\n",
         "vrj_opengl_UserData_Wrapper::setProjection() done.\n"
      );
      PyJuggler::InterpreterGuard guard;

      try {
         if ( bp::override setProjection = this->get_override("getProjection") ) {
            getProjection();
         } else {
            vrj::opengl::UserData::getProjection();
         }
      }
      catch (error_already_set) {
         PyErr_Print();
      }
   }

   void default_setProjection(vrj::ProjectionPtr proj) {
      vrj::opengl::UserData::setProjection(proj);
   }

   const vrj::ViewportPtr getViewport() const {
      vpr::DebugOutputGuard og(
         pyjDBG_CXX, vprDBG_VERB_LVL,
         "vrj_opengl_UserData_Wrapper::getViewport()\n",
         "vrj_opengl_UserData_Wrapper::getViewport() done.\n"
      );
      PyJuggler::InterpreterGuard guard;

      try {
         if ( bp::override getViewport = this->get_override("getViewport") ) {
            return getViewport();
         } else {
            return vrj::opengl::UserData::getViewport();
         }
      }
      catch (error_already_set) {
         PyErr_Print();
      }
   }

   const vrj::ViewportPtr default_getViewport() const {
      return vrj::opengl::UserData::getViewport();
   }

   void setViewport(vrj::ViewportPtr vp) {
      vpr::DebugOutputGuard og(
         pyjDBG_CXX, vprDBG_VERB_LVL,
         "vrj_opengl_UserData_Wrapper::setViewport\n",
         "vrj_opengl_UserData_Wrapper::setViewport done.\n"
      );
      PyJuggler::InterpreterGuard guard;

      try {
         if ( bp::override setViewport = this->get_override("setViewport") ) {
            setViewport(vp);
         } else {
            vrj::opengl::UserData::setViewport(vp);
         }
      }
      catch (error_already_set) {
         PyErr_Print();
      }
   }

   void default_setViewport(vrj::ViewportPtr vp) {
      vrj::opengl::UserData::setViewport(vp);
   }

   const vrj::opengl::WindowPtr getGlWindow() const {
      vpr::DebugOutputGuard og(
         pyjDBG_CXX, vprDBG_VERB_LVL,
         "vrj_opengl_UserData_Wrapper::getGlWindow()\n",
         "vrj_opengl_UserData_Wrapper::getGlWindow() done.\n"
      );
      PyJuggler::InterpreterGuard guard;

      try {
         if ( bp::override getGlWindow = this->get_override("getGlWindow") ) {
            return getGlWindow();
         } else {
            return vrj::opengl::UserData::getGlWindow();
         }
      }
      catch (error_already_set) {
         PyErr_Print();
      }
   }

   const vrj::opengl::WindowPtr default_getGlWindow() const {
      return vrj::opengl::UserData::getGlWindow();
   }

   void setGlWindow(vrj::opengl::WindowPtr win) {
      vpr::DebugOutputGuard og(
         pyjDBG_CXX, vprDBG_VERB_LVL,
         "vrj_opengl_UserData_Wrapper::setGlWindow()\n",
         "vrj_opengl_UserData_Wrapper::setGlWindow() done.\n"
      );
      PyJuggler::InterpreterGuard guard;

      try {
         if ( bp::override setGlWindow = this->get_override("setGlWindow") ) {
            setGlWindow(win);
         } else {
            vrj::opengl::UserData::setGlWindow(win);
         }
      }
      catch (error_already_set) {
         PyErr_Print();
      }
   }

   void default_setGlWindow(vrj::opengl::WindowPtr win) {
      vrj::opengl::UserData::setGlWindow(win);
   }
};

}  // namespace pyj

void _Export_UserData() {
   class_<pyj::vrj_opengl_UserData_Wrapper, boost::noncopyable>(
      "UserData",
      "Documentation stub",
      // no_init
      init<>()
   )
   .def("getUser", &vrj::opengl::UserData::getUser,
      // &pyj::vrj_opengl_UserData_Wrapper::default_getUser,
      // return_value_policy<reference_existing_object>(),
      "Documentation stub"
   )
   .def("setUser", &vrj::opengl::UserData::setUser,
      &pyj::vrj_opengl_UserData_Wrapper::default_setUser,
      "Documentation stub"
   )
   .def("getProjection", &vrj::opengl::UserData::getProjection,
      // &pyj::vrj_opengl_UserData_Wrapper::default_getProjection,
      // return_value_policy<reference_existing_object>(),
      "Documentation stub"
   )
   .def("setProjection", &vrj::opengl::UserData::setProjection,
      &pyj::vrj_opengl_UserData_Wrapper::default_setProjection,
      "Documentation stub"
   )
   .def("getViewport", &vrj::opengl::UserData::getViewport,
      // &pyj::vrj_opengl_UserData_Wrapper::default_getViewport,
      // return_value_policy<reference_existing_object>(),
      "Documentation stub"
   )
   .def("setViewport", &vrj::opengl::UserData::setViewport,
      &pyj::vrj_opengl_UserData_Wrapper::default_setViewport,
      "Documentation stub"
   )
   .def("getGlWindow", &vrj::opengl::UserData::getGlWindow,
      // &pyj::vrj_opengl_UserData_Wrapper::default_getGlWindow,
      // return_value_policy<reference_existing_object>(),
      "Documentation stub"
   )
   .def("setGlWindow", &vrj::opengl::UserData::setGlWindow,
      &pyj::vrj_opengl_UserData_Wrapper::default_setGlWindow,
      "Documentation stub"
   )
   ;
}
