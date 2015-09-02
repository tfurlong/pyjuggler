set(SRC_FILES
    __gadget.cpp
    _Analog.cpp
    _gadget_Type_KeyboardMouse_Keys_h.cpp
    _AnalogData.cpp
    _InputManager.cpp
    _AnalogInterface.cpp
    _KeyboardMouse.cpp
    _AnalogProxy.cpp
    _KeyboardMouseInterface.cpp
    _BaseDeviceInterface.cpp
    _KeyboardMouseProxy.cpp
    _KeyEvent.cpp
    _Command.cpp
    _MouseEvent.cpp
    _CommandData.cpp
    _Position.cpp
    _CommandInterface.cpp
    _PositionData.cpp
    _CommandProxy.cpp
    _PositionInterface.cpp
    _Digital.cpp
    _PositionProxy.cpp
    _DigitalData.cpp
    _PositionUnitConversion.cpp
    _DigitalInterface.cpp
    _String.cpp
    _DigitalProxy.cpp
    _StringData.cpp
    _Event.cpp
    _StringInterface.cpp
    __gadget.cpp
    _StringProxy.cpp
    _gadget_Type_KeyboardMouse_Event_h.cpp
)
set(TARGET_NAME __gadget)

# PYTHON_ADD_MODULE(${TARGET_NAME} gadget.cpp)
add_library(${TARGET_NAME} SHARED ${SRC_FILES})
set_target_properties(${TARGET_NAME} PROPERTIES PREFIX "")

target_include_directories(${TARGET_NAME} PRIVATE
                          "${CMAKE_SOURCE_DIR}/include"
                          "${Boost_INCLUDE_DIRS}"
                          "${CPPDOM_INCLUDE_DIR}"
                          "${GADGETEER21_INCLUDE_DIR}"
                          "${GMTL_INCLUDE_DIR}"
                          "${JCCL15_INCLUDE_DIR}"
                          "${PYTHON_INCLUDE_DIRS}"
                          "${VPR23_INCLUDE_DIR}"
)

target_link_libraries(${TARGET_NAME}
                     "${Boost_LIBRARIES}"
                     "${CPPDOM_LIBRARY}"
                     "${GADGETEER21_LIBRARY}"
                     "${JCCL15_LIBRARY}"
                     "${PYTHON_LIBRARIES}"
                     "${VPR23_LIBRARY}"
)

install (TARGETS ${TARGET_NAME} DESTINATION PyJuggler/gadget)
install (FILES __init__.py DESTINATION PyJuggler/gadget)
