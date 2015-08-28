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
    ${CMAKE_SOURCE_DIR}/pyjutil/InterpreterGuard.cpp
)
set(TARGET_NAME vrj)

# PYTHON_ADD_MODULE(${TARGET_NAME} __vrj.cpp)
add_library(${TARGET_NAME} SHARED ${SRC_FILES})

target_include_directories(${TARGET_NAME} PRIVATE
                          "${Boost_INCLUDE_DIRS}"
                          "${PYTHON_INCLUDE_DIRS}"
                          "${VRJ31_INCLUDE_DIR}"
                          "${VPR23_INCLUDE_DIR}"
                          "${JCCL15_INCLUDE_DIR}"
                          "${GADGETEER21_INCLUDE_DIR}"
                          "${CPPDOM_INCLUDE_DIR}"
                          "${GMTL_INCLUDE_DIR}"
                          "${CMAKE_SOURCE_DIR}"
                          "${CMAKE_SOURCE_DIR}/src"
)

target_link_libraries(${TARGET_NAME}
                     "${Boost_LIBRARIES}"
                     "${PYTHON_LIBRARIES}"
                     "${VRJ31_LIBRARY}"
                     "${VPR23_LIBRARY}"
                     "${JCCL15_LIBRARY}"
                     "${GADGETEER21_LIBRARY}"
                     "${CPPDOM_LIBRARY}"
)

install (TARGETS ${TARGET_NAME} DESTINATION PyJuggler)
