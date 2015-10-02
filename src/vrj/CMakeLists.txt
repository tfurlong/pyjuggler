set(SRC_FILES
    __vrj.cpp
    _App.cpp
    _CameraProjection.cpp
    _Display.cpp
    _Frustum.cpp
    _Kernel.cpp
    _Projection.cpp
    _SimViewport.cpp
    _User.cpp
    _Viewport.cpp
)
set(TARGET_NAME __vrj)

# PYTHON_ADD_MODULE(${TARGET_NAME} __vrj.cpp)
add_library(${TARGET_NAME} SHARED ${SRC_FILES})
set_target_properties(${TARGET_NAME} PROPERTIES PREFIX "")

# Python on Windows is lame and will only load binary libraries with the .pyd
# extension.
if(CMAKE_HOST_SYSTEM_NAME STREQUAL "Windows")
    set_target_properties(${TARGET_NAME} PROPERTIES SUFFIX ".pyd")
endif()

target_include_directories(${TARGET_NAME} PRIVATE
                          "${CMAKE_SOURCE_DIR}/include"
                          "${Boost_INCLUDE_DIRS}"
                          "${CPPDOM_INCLUDE_DIR}"
                          "${GADGETEER21_INCLUDE_DIR}"
                          "${GMTL_INCLUDE_DIR}"
                          "${JCCL15_INCLUDE_DIR}"
                          "${PYTHON_INCLUDE_DIRS}"
                          "${VPR23_INCLUDE_DIR}"
                          "${VRJ31_INCLUDE_DIR}"
)

target_link_libraries(${TARGET_NAME}
                     "${Boost_LIBRARIES}"
                     "${CPPDOM_LIBRARY}"
                     "${GADGETEER21_LIBRARY}"
                     "${JCCL15_LIBRARY}"
                     "${PYTHON_LIBRARIES}"
                     "${VPR23_LIBRARY}"
                     "${VRJ31_LIBRARY}"
                     pyjutil
)

install(TARGETS ${TARGET_NAME} DESTINATION PyJuggler/vrj)
install(FILES __init__.py DESTINATION PyJuggler/vrj)
