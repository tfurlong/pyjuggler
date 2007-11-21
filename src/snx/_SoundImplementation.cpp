// PyJuggler is (C) Copyright 2002-2007 by Patrick Hartling
// Distributed under the GNU Lesser General Public License 2.1.  (See
// accompanying file COPYING.txt or http://www.gnu.org/copyleft/lesser.txt)

// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <snx/SoundImplementation.h>

// Using =======================================================================
using namespace boost::python;

// Declarations ================================================================
namespace pyj
{

struct snx_SoundImplementation_Adapter : snx::SoundImplementation
{
   snx_SoundImplementation_Adapter(const snx::SoundImplementation& p0)
      : snx::SoundImplementation(p0)
   {
      /* Do nothing. */ ;
   }

   snx_SoundImplementation_Adapter()
      : snx::SoundImplementation()
   {
      /* Do nothing. */ ;
   }

   virtual ~snx_SoundImplementation_Adapter()
   {
      /* Do nothing. */ ;
   }

   virtual tuple getPositionWrapper(const std::string& alias)
   {
      float p0, p1, p2;
      snx::SoundImplementation::getPosition(alias, p0, p1, p2);
      return make_tuple(p0, p1, p2);
   }
};

struct snx_SoundImplementation_Wrapper
   : snx_SoundImplementation_Adapter
   , wrapper<snx_SoundImplementation_Adapter>
{
   snx_SoundImplementation_Wrapper(const snx::SoundImplementation& p0)
      : snx_SoundImplementation_Adapter(p0)
   {
      /* Do nothing. */ ;
   }

   snx_SoundImplementation_Wrapper()
      : snx_SoundImplementation_Adapter()
   {
      /* Do nothing. */ ;
   }

   virtual ~snx_SoundImplementation_Wrapper()
   {
      /* Do nothing. */ ;
   }

   void clone(snx::ISoundImplementation*& p0)
   {
      try
      {
         this->get_override("clone")(boost::ref(p0));
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }
   }

   void trigger(const std::string& p0, const int p1)
   {
      try
      {
         if ( override trigger = this->get_override("trigger") )
         {
           trigger(boost::ref(p0), p1);
         }
         else
         {
           snx::SoundImplementation::trigger(p0, p1);
         }
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }
   }

   void default_trigger(const std::string& p0, const int p1)
   {
      snx::SoundImplementation::trigger(p0, p1);
   }

   bool isPlaying(const std::string& p0)
   {
      try
      {
         if ( override isPlaying = this->get_override("isPlaying") )
         {
            return isPlaying(boost::ref(p0));
         }
         return snx::SoundImplementation::isPlaying(p0);
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }

      return false;
   }

   bool default_isPlaying(const std::string& p0)
   {
      return snx::SoundImplementation::isPlaying(p0);
   }

   void setRetriggerable(const std::string& p0, bool p1)
   {
      try
      {
         if ( override setRetriggerable =
                 this->get_override("setRetriggerable") )
         {
            setRetriggerable(boost::ref(p0), p1);
         }
         else
         {
            snx::SoundImplementation::setRetriggerable(p0, p1);
         }
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }
   }

   void default_setRetriggerable(const std::string& p0, bool p1)
   {
      snx::SoundImplementation::setRetriggerable(p0, p1);
   }

   bool isRetriggerable(const std::string& p0)
   {
      try
      {
         if ( override isRetriggerable = this->get_override("isRetriggerable") )
         {
            return isRetriggerable(boost::ref(p0));
         }
         return snx::SoundImplementation::isRetriggerable(p0);
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }

      return false;
   }

   bool default_isRetriggerable(const std::string& p0)
   {
      return snx::SoundImplementation::isRetriggerable(p0);
   }

   void stop(const std::string& p0)
   {
      try
      {
         if ( override stop = this->get_override("stop") )
         {
            stop(boost::ref(p0));
         }
         else
         {
            snx::SoundImplementation::stop(p0);
         }
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }
   }

   void default_stop(const std::string& p0)
   {
      snx::SoundImplementation::stop(p0);
   }

   void pause(const std::string& p0)
   {
      try
      {
         if ( override pause = this->get_override("pause") )
         {
            pause(boost::ref(p0));
         }
         else
         {
            snx::SoundImplementation::pause(p0);
         }
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }
   }

   void default_pause(const std::string& p0)
   {
      snx::SoundImplementation::pause(p0);
   }

   void unpause(const std::string& p0)
   {
      try
      {
         if ( override unpause = this->get_override("unpause") )
         {
            unpause(boost::ref(p0));
         }
         else
         {
            snx::SoundImplementation::unpause(p0);
         }
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }
   }

   void default_unpause(const std::string& p0)
   {
      snx::SoundImplementation::unpause(p0);
   }

   bool isPaused(const std::string& p0)
   {
      try
      {
         if ( override isPaused = this->get_override("isPaused") )
         {
            return isPaused(boost::ref(p0));
         }
         return snx::SoundImplementation::isPaused(p0);
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }

      return false;
   }

   bool default_isPaused(const std::string& p0)
   {
      return snx::SoundImplementation::isPaused(p0);
   }

   void setAmbient(const std::string& p0, const bool p1)
   {
      try
      {
         if ( override setAmbient = this->get_override("setAmbient") )
         {
            setAmbient(boost::ref(p0), p1);
         }
         else
         {
            snx::SoundImplementation::setAmbient(p0, p1);
         }
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }
   }

   void default_setAmbient(const std::string& p0, const bool p1 = false)
   {
      snx::SoundImplementation::setAmbient(p0, p1);
   }

   bool isAmbient(const std::string& p0)
   {
      try
      {
         if ( override isAmbient = this->get_override("isAmbient") )
         {
            return isAmbient(boost::ref(p0));
         }
         return snx::SoundImplementation::isAmbient(p0);
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }

      return false;
   }

   bool default_isAmbient(const std::string& p0)
   {
      return snx::SoundImplementation::isAmbient(p0);
   }

   void setPitchBend(const std::string& p0, float p1)
   {
      try
      {
         if ( override setPitchBend = this->get_override("setPitchBend") )
         {
            setPitchBend(boost::ref(p0), p1);
         }
         else
         {
            snx::SoundImplementation::setPitchBend(p0, p1);
         }
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }
   }

   void default_setPitchBend(const std::string& p0, float p1)
   {
      snx::SoundImplementation::setPitchBend(p0, p1);
   }

   void setVolume(const std::string& p0, float p1)
   {
      try
      {
         if ( override setVolume = this->get_override("setVolume") )
         {
            setVolume(boost::ref(p0), p1);
         }
         else
         {
            snx::SoundImplementation::setVolume(p0, p1);
         }
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }
   }

   void default_setVolume(const std::string& p0, float p1)
   {
      snx::SoundImplementation::setVolume(p0, p1);
   }

   void setCutoff(const std::string& p0, float p1)
   {
      try
      {
         if ( override setCutoff = this->get_override("setCutoff") )
         {
            setCutoff(boost::ref(p0), p1);
         }
         else
         {
            snx::SoundImplementation::setCutoff(p0, p1);
         }
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }
   }

   void default_setCutoff(const std::string& p0, float p1)
   {
      snx::SoundImplementation::setCutoff(p0, p1);
   }

   void setPosition(const std::string& p0, float p1, float p2, float p3)
   {
      try
      {
         if ( override setPosition = this->get_override("setPosition") )
         {
            setPosition(boost::ref(p0), p1, p2, p3);
         }
         else
         {
            snx::SoundImplementation::setPosition(p0, p1, p2, p3);
         }
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }
   }

   void default_setPosition(const std::string& p0, float p1, float p2,
                            float p3)
   {
      snx::SoundImplementation::setPosition(p0, p1, p2, p3);
   }

   void getPosition(const std::string& p0, float& p1, float& p2, float& p3)
   {
      tuple result = getPositionWrapper(p0);
      p1 = extract<float>(result[0]);
      p2 = extract<float>(result[1]);
      p3 = extract<float>(result[2]);
   }

   tuple getPositionWrapper(const std::string& p0)
   {
      try
      {
         if ( override getPosition = this->get_override("getPosition") )
         {
            return getPosition(boost::ref(p0));
         }
         return snx_SoundImplementation_Adapter::getPositionWrapper(p0);
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }

      return make_tuple();
   }

   tuple default_getPositionWrapper(const std::string& p0)
   {
      return snx_SoundImplementation_Adapter::getPositionWrapper(p0);
   }

   void setListenerPosition(const gmtl::Matrix44f& p0)
   {
      try
      {
         if ( override setListenerPosition =
                 this->get_override("setListenerPosition") )
         {
            setListenerPosition(boost::ref(p0));
         }
         else
         {
            snx::SoundImplementation::setListenerPosition(p0);
         }
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }
   }

   void default_setListenerPosition(const gmtl::Matrix44f& p0)
   {
      snx::SoundImplementation::setListenerPosition(p0);
   }

   void getListenerPosition(gmtl::Matrix44f& p0)
   {
      try
      {
         if ( override getListenerPosition =
                 this->get_override("getListenerPosition") )
         {
            getListenerPosition(p0);
         }
         else
         {
            snx::SoundImplementation::getListenerPosition(p0);
         }
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }
   }

   void default_getListenerPosition(gmtl::Matrix44f& p0)
   {
      snx::SoundImplementation::getListenerPosition(p0);
   }

   int startAPI()
   {
      try
      {
         return this->get_override("startAPI")();
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }

      return 0;
   }

   bool isStarted() const
   {
      return this->get_override("isStarted")();
   }

   void shutdownAPI()
   {
      try
      {
         if ( override shutdownAPI = this->get_override("shutdownAPI") )
         {
            shutdownAPI();
         }
         else
         {
            snx::SoundImplementation::shutdownAPI();
         }
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }
   }

   void default_shutdownAPI()
   {
      snx::SoundImplementation::shutdownAPI();
   }

   void configure(const snx::SoundAPIInfo& p0)
   {
      try
      {
         if ( override configure = this->get_override("configure") )
         {
            configure(boost::ref(p0));
         }
         else
         {
            snx::SoundImplementation::configure(p0);
         }
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }
   }

   void default_configure(const snx::SoundAPIInfo& p0)
   {
      snx::SoundImplementation::configure(p0);
   }

   void configure(const std::string& p0, const snx::SoundInfo& p1)
   {
      try
      {
         if ( override configure = this->get_override("configure") )
         {
            configure(boost::ref(p0), boost::ref(p1));
         }
         else
         {
            snx::SoundImplementation::configure(p0, p1);
         }
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }
   }

   void default_configure(const std::string& p0, const snx::SoundInfo& p1)
   {
      snx::SoundImplementation::configure(p0, p1);
   }

   void remove(const std::string& p0)
   {
      try
      {
         if ( override remove = this->get_override("remove") )
         {
            remove(boost::ref(p0));
         }
         else
         {
            snx::SoundImplementation::remove(p0);
         }
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }
   }

   void default_remove(const std::string& p0)
   {
      snx::SoundImplementation::remove(p0);
   }

   void step(const float p0)
   {
      try
      {
         if ( override step = this->get_override("step") )
         {
            step(p0);
         }
         else
         {
            snx::SoundImplementation::step(p0);
         }
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }
   }

   void default_step(const float p0)
   {
      snx::SoundImplementation::step(p0);
   }

   void clear()
   {
      try
      {
         if ( override clear = this->get_override("clear") )
         {
            clear();
         }
         else
         {
            snx::SoundImplementation::clear();
         }
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }
   }

   void default_clear()
   {
      snx::SoundImplementation::clear();
   }

   void bindAll()
   {
      try
      {
         if ( override bindAll = this->get_override("bindAll") )
         {
            bindAll();
         }
         else
         {
            snx::SoundImplementation::bindAll();
         }
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }
   }

   void default_bindAll()
   {
      snx::SoundImplementation::bindAll();
   }

   void unbindAll()
   {
      try
      {
         if ( override unbindAll = this->get_override("unbindAll") )
         {
            unbindAll();
         }
         else
         {
            snx::SoundImplementation::unbindAll();
         }
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }
   }

   void default_unbindAll()
   {
      snx::SoundImplementation::unbindAll();
   }

   void bind(const std::string& p0)
   {
      try
      {
         this->get_override("bind")(boost::ref(p0));
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }
   }

   void unbind(const std::string& p0)
   {
      this->get_override("unbind")(boost::ref(p0));
   }

   snx::SoundInfo& lookup(const std::string& p0)
   {
      try
      {
         if ( override lookup = this->get_override("lookup") )
         {
#if defined(_MSC_VER) || \
    (defined(__GNUC__) && __GNUC__ == 3 && __GNUC_MINOR__ == 2)
            return call<snx::SoundInfo&, std::string>(lookup.ptr(),
                                                      boost::ref(p0));
#else
            return lookup(boost::ref(p0));
#endif
         }
         return snx::SoundImplementation::lookup(p0);
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }

      // XXX: I am not sure if this is the best way to handle this case.
      return default_lookup(p0);
   }

   snx::SoundInfo& default_lookup(const std::string& p0)
   {
      return snx::SoundImplementation::lookup(p0);
   }

   void setName(const std::string& p0)
   {
      try
      {
         if ( override setName = this->get_override("setName") )
         {
            setName(boost::ref(p0));
         }
         else
         {
            snx::SoundImplementation::setName(p0);
         }
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }
   }

   void default_setName(const std::string& p0)
   {
      snx::SoundImplementation::setName(p0);
   }

   std::string& name()
   {
      try
      {
         if ( override name = this->get_override("name") )
         {
#if defined(_MSC_VER) || \
    (defined(__GNUC__) && __GNUC__ == 3 && __GNUC_MINOR__ == 2)
            return call<std::string&>(name.ptr());
#else
            return name();
#endif
         }
         return snx::SoundImplementation::name();
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }

      return default_name();
   }

   std::string& default_name()
   {
      return snx::SoundImplementation::name();
   }

   void destroy()
   {
      try
      {
         this->get_override("destroy")();
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }
   }

   PyObject* self;
};


}// namespace pyj


// Module ======================================================================
void _Export_SoundImplementation()
{
   class_<pyj::snx_SoundImplementation_Wrapper, boost::noncopyable>
      ("SoundImplementation",
       init<>(
          "__init__()\n"
          "Default constructor."
       )
      )
      .def("clone", pure_virtual(&snx::SoundImplementation::clone),
           "clone(newCopy)\n"
           "Every implementation can return a new copy of itself."
      )
      .def("trigger", &snx::SoundImplementation::trigger,
           (arg("alias"), arg("repeat") = 1),
           "trigger(alias, repeat = 1)\n"
           "Triggers a sound.\n\n"
           "Pre-condition:\n"
           "alias does not have to be associated with a loaded sound.\n\n"
           "Post-condition:\n"
           "If allias is associated with a loaded sound, then the loaded\n"
           "sound is triggered.  If not, nothing happens.\n\n"
           "Arguments:\n"
           "alias  -- Alias of the sound to trigger.\n"
           "repeat -- The number of times to play.  Use -1 to repeat\n\n"
           "          forever.  The default is to play the sound once.\n\n"
      )
      .def("isPlaying", &snx::SoundImplementation::isPlaying,
           &pyj::snx_SoundImplementation_Wrapper::default_isPlaying,
           "isPlaying(alias) -> Boolean\n"
           "Is the named sound currently playing?\n\n"
           "Arguments:\n"
           "alias -- The alias of the sound to query."
      )
      .def("setRetriggerable", &snx::SoundImplementation::setRetriggerable,
           &pyj::snx_SoundImplementation_Wrapper::default_setRetriggerable,
           "setRetriggerable(alias, onOff)\n"
           "Specifies whether the named sound retriggers from the beginning\n"
           "when triggered while playing.  In other words, when the named\n"
           "sound is already playing and trigger() is called, does the\n"
           "sound restart from the beginning?\n\n"
           "Arguments:\n"
           "alias -- The alias of the sound to change.\n"
           "onOff -- A Boolean value enabling or disabling retriggering."
      )
      .def("isRetriggerable", &snx::SoundImplementation::isRetriggerable,
           &pyj::snx_SoundImplementation_Wrapper::default_isRetriggerable,
           "isRetriggerable(alais) -> Boolean\n"
           "Is the named sound retriggerable?\n\n"
           "Arguments:\n"
           "alias -- The alias of the sound to query."
      )
      .def("stop", &snx::SoundImplementation::stop,
           &pyj::snx_SoundImplementation_Wrapper::default_stop,
           "stop(alias)\n"
           "Stops the named sound.\n\n"
           "Arguments:\n"
           "alias -- The alias of the sound to stop."
      )
      .def("pause", &snx::SoundImplementation::pause,
           &pyj::snx_SoundImplementation_Wrapper::default_pause,
           "pause(alias)\n"
           "Pauses the sound.  Use unpause() to return playback from where\n"
           "the sound was paused.\n\n"
           "Arguments:\n"
           "alias -- The alias of the sound to pause."
      )
      .def("unpause", &snx::SoundImplementation::unpause,
           &pyj::snx_SoundImplementation_Wrapper::default_unpause,
           "unpause(alias)\n"
           "Resumes playback of the named sound from a paused state.  This\n"
           "does nothing if the sound was not paused.\n\n"
           "Arguments:\n"
           "alias -- The alias of the sound to unpause."
      )
      .def("isPaused", &snx::SoundImplementation::isPaused,
           &pyj::snx_SoundImplementation_Wrapper::default_isPaused,
           "isPaused(alias) -> Boolean\n"
           "If the sound is paused, then return True.\n\n"
           "Arguments:\n"
           "alias -- The alias of the sound to query."
      )
      .def("setAmbient", &snx::SoundImplementation::setAmbient,
           &pyj::snx_SoundImplementation_Wrapper::default_setAmbient,
           "setAmbient(alias, ambient = False)\n"
           "Sets the named sound as either ambient or positional depending\n"
           "on the value of the given argument.  If the sound is ambient,\n"
           "it is attached to the listener, and its volume does not change\n"
           "when the listener moves.  If the sound is positional, the\n"
           "volume changes when the listener moves.\n\n"
           "Arguments:\n"
           "alias   -- The alias of the sound to change\n"
           "ambient -- A Boolean flag identifying whether this sound is\n"
           "           ambient (True) or positional (False).\n\n"
      )
      .def("isAmbient", &snx::SoundImplementation::isAmbient,
           &pyj::snx_SoundImplementation_Wrapper::default_isAmbient,
           "isAmbient(alias) -> Boolean\n"
           "Is the named sound ambient?\n\n"
           "Arguments:\n"
           "alias -- The name of the sound to query."
      )
      .def("setPitchBend", &snx::SoundImplementation::setPitchBend,
           &pyj::snx_SoundImplementation_Wrapper::default_setPitchBend,
           "setPitchBend(alias, amount)\n"
           "Alters the frequency of the named sound.\n\n"
           "Arguments:\n"
           "alias  -- The alias of the sound to change.\n"
           "amount -- A floating-point value that determines the pitch\n"
           "          bend.  1.0 means that there is no change.  A value\n"
           "          less than 1.0 is low; a value greather than 1.0 is\n"
           "          high."
      )
      .def("setVolume", &snx::SoundImplementation::setVolume,
           &pyj::snx_SoundImplementation_Wrapper::default_setVolume,
           "setVolume(alias, amount)\n"
           "Sets the effect volume of the named sound.  The value must be\n"
           "in the range [0,1].\n\n"
           "Argument:\n"
           "alias  -- The alias of the sound to change.\n"
           "amount -- A floating-point value that determines the volume.\n"
           "          It must be between 0.0 and 1.0 inclusive."
      )
      .def("setCutoff", &snx::SoundImplementation::setCutoff,
           &pyj::snx_SoundImplementation_Wrapper::default_setCutoff,
           "setCutoff(alias, amount)\n"
           "Sets the effect cutoff of the named sound.  Set to a value in\n"
           "the range [0,1].\n\n"
           "Arguments:\n"
           "alias  -- The alias of the sound to change.\n"
           "amount -- A floating-point value that determines the cutoff.\n"
           "          The value must be between 0.0 and 1.0 inclusive.\n"
           "          1.0 means no change; 0.0 is total cutoff."
      )
      .def("setPosition", &snx::SoundImplementation::setPosition,
           &pyj::snx_SoundImplementation_Wrapper::default_setPosition,
           "setPosition(alias, x, y, z)\n"
           "Sets the named sound's three-dimensional position.\n\n"
           "Arguments:\n"
           "alias -- The alias of the sound to change.\n"
           "x     -- The X coordinate of the sound in 3D OpenGL coordinates.\n"
           "y     -- The Y coordinate of the sound in 3D OpenGL coordinates.\n"
           "z     -- The Z coordinate of the sound in 3D OpenGL coordinates."
      )
      .def("getPosition",
           &pyj::snx_SoundImplementation_Adapter::getPositionWrapper,
           &pyj::snx_SoundImplementation_Wrapper::default_getPositionWrapper,
           "getPosition(alias) -> tuple\n"
           "Gets the named sound's 3D position.\n\n"
           "Arguments:\n"
           "alias  -- The alias of the sound to change.\n\n"
           "Returns:\n"
           "A tuple of floating-point values providing the (x, y, z)\n"
           "position of the named sound."
      )
      .def("setListenerPosition",
           &snx::SoundImplementation::setListenerPosition,
           &pyj::snx_SoundImplementation_Wrapper::default_setListenerPosition,
           "setListenerPosition(matrix)\n"
           "Sets the position of the listener.\n\n"
           "Arguments:\n"
           "matrix -- A gmtl.Matrix44f object representing the position\n"
           "          of the listener."
      )
      .def("getListenerPosition",
           &snx::SoundImplementation::getListenerPosition,
           &pyj::snx_SoundImplementation_Wrapper::default_getListenerPosition,
           "getListenerPosition(matrix)\n"
           "Gets the listeners's 3D position.\n\n"
           "Arguments:\n"
           "matrix -- A gmtl.Matrix44f object used to store the position\n"
           "          of the listener."
      )
      .def("startAPI", pure_virtual(&snx::SoundImplementation::startAPI),
           "startAPI() -> integer\n"
           "Starts the sound API, creating any contexts or other\n"
           "configurations at startup.  This function should be callled\n"
           "before using the other functions in the class.\n\n"
           "Post-condition:\n"
           "Sound APi is ready to go.\n\n"
           "Returns:\n"
           "1 if success, 0 otherwise."
      )
      .def("isStarted", pure_virtual(&snx::SoundImplementation::isStarted),
           "isStarted() -> Boolean\n"
           "Queries whether the API has been started.\n\n"
           "Returns:\n"
           "True if the API has been started, False otherwise."
      )
      .def("shutdownAPI", &snx::SoundImplementation::shutdownAPI,
           &pyj::snx_SoundImplementation_Wrapper::default_shutdownAPI,
           "shutdownAPI()\n"
           "Kills the sound API, deallocating any sounds, etc.  This\n"
           "function could be called any time.  The function could be\n"
           "called multiple times, so it should be smart.\n\n"
           "Post-condition:\n"
           "The sound API is no longer running or available for use."
      )
      .def("configure",
           (void (snx::SoundImplementation::*)(const snx::SoundAPIInfo&)) &snx::SoundImplementation::configure,
           (void (pyj::snx_SoundImplementation_Wrapper::*)(const snx::SoundAPIInfo&)) &pyj::snx_SoundImplementation_Wrapper::default_configure,
           "configure(description)\n"
           "Configures/reconfigures the sound API global settings.\n\n"
           "Arguments:\n"
           "description -- A snx.SoundAPIInfo object that describes the\n"
           "               settings for this sound API."
      )
      .def("configure",
           (void (snx::SoundImplementation::*)(const std::string&, const snx::SoundInfo&)) &snx::SoundImplementation::configure,
           (void (pyj::snx_SoundImplementation_Wrapper::*)(const std::string&, const snx::SoundInfo&)) &pyj::snx_SoundImplementation_Wrapper::default_configure,
           "configure(alais, description)\n"
           "Configures/reconfigures the named sound by associating sound\n"
           "data with the named sound.  Afterwards, the alias can be used\n"
           "to operate on sound data.\n\n"
           "Configure: associate a name (alias) with the description if\n"
           "not already done.\n"
           "Reconfigure: change properties of the sound to the description\n"
           "provided.\n\n"
           "Pre-condition:\n"
           "Provide a snx.SoundInfo that describes the sound.\n\n"
           "Post-condition:\n"
           "This handle will point to loaded sound data.\n\n"
           "Arguments:\n"
           "alias       -- The alias of the sound to be associated with the\n"
           "               given sound data.\n"
           "description -- A snx.SoundInfo object that describes the sound\n"
           "               for which this object will be a handle."
      )
      .def("remove", &snx::SoundImplementation::remove,
           &pyj::snx_SoundImplementation_Wrapper::default_remove,
           "remove(alias)\n"
           "Removes a configured sound.  Any future reference to the alias\n"
           "will not cause an error, but it will not result in a rendered\n"
           "sound.\n\n"
           "Arguments:\n"
           "alias -- The alias of the sound to remove."
      )
      .def("step", &snx::SoundImplementation::step,
           &pyj::snx_SoundImplementation_Wrapper::default_step,
           "step(timeElapsed)\n"
           "Call once per sound frame (which does not have to be the same\n"
           "as the graphics frame).\n\n"
           "Arguments:\n"
           "timeElapsed -- A floating-point value giving the time elapsed\n"
           "               since the last sound frame."
      )
      .def("clear", &snx::SoundImplementation::clear,
           &pyj::snx_SoundImplementation_Wrapper::default_clear,
           "clear()\n"
           "Clears all associations.\n\n"
           "Post-conditions:\n"
           "Any existing aliases will be stubbed.  Sounds will be unbound."
      )
      .def("bindAll", &snx::SoundImplementation::bindAll,
           &pyj::snx_SoundImplementation_Wrapper::default_bindAll,
           "bindAll()\n"
           "Bind: load (or reload) all associated sounds.\n\n"
           "Post-condition:\n"
           "All sound associations are buffered by the sound API."
      )
      .def("unbindAll", &snx::SoundImplementation::unbindAll,
           &pyj::snx_SoundImplementation_Wrapper::default_unbindAll,
           "unbindAll()\n"
           "Unbind: unload/deallocate all associated sounds.\n\n"
           "Post-conditions:\n"
           "All sound associations are unbuffered by the sound API."
      )
      .def("bind", pure_virtual(&snx::SoundImplementation::bind),
           "bind(alias)\n"
           "Loads/allocates the sound data this alias refers to in the\n"
           "sound API.\n\n"
           "Post-condition:\n"
           "The sound API has the sound buffered.\n\n"
           "Arguments:\n"
           "alias -- The alias of the sound data to be bound."
      )
      .def("unbind", pure_virtual(&snx::SoundImplementation::unbind),
           "unbind(alias)\n"
           "Unloads/deallocates the sound data this alias refers to in the\n"
           "sound API.\n\n"
           "Post-condition:\n"
           "The sound API no longer has the sound buffered.\n\n"
           "Arguments:\n"
           "alias -- The alias of the sound data to be unbound."
      )
      .def("lookup", &snx::SoundImplementation::lookup,
           &pyj::snx_SoundImplementation_Wrapper::default_lookup,
           return_internal_reference<1>()
      )
      .def("setName", &snx::SoundImplementation::setName,
           &pyj::snx_SoundImplementation_Wrapper::default_setName
      )
      .def("name", &snx::SoundImplementation::name,
           &pyj::snx_SoundImplementation_Wrapper::default_name,
           return_internal_reference<1>()
      )
      .def("copy", &snx::SoundImplementation::copy,
           "copy(si)\n"
           "Copies the current state of the system from the given API into\n"
           "this object.  This does not perform any binding.  That must be\n"
           "done separately.\n\n"
           "Arguments:\n"
           "si -- A snx.SoundImplementation object from which the state\n"
           "      will be copied into this object."
      )
   ;
}
