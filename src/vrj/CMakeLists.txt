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

python_add_module(${TARGET_NAME} ${SRC_FILES})

target_include_directories(${TARGET_NAME} PRIVATE
                          ${Boost_INCLUDE_DIRS}
                          ${PYTHON_INCLUDE_DIRS}
                          "${CMAKE_SOURCE_DIR}/include"
                          "${CPPDOM_INCLUDE_DIR}"
                          "${GADGETEER21_INCLUDE_DIR}"
                          "${GMTL_INCLUDE_DIR}"
                          "${JCCL15_INCLUDE_DIR}"
                          "${VPR23_INCLUDE_DIR}"
                          "${VRJ31_INCLUDE_DIR}"
)

target_link_libraries(${TARGET_NAME}
                     ${Boost_LIBRARIES}
                     ${PYTHON_LIBRARIES}
                     "${CPPDOM_LIBRARY}"
                     "${GADGETEER21_LIBRARY}"
                     "${JCCL15_LIBRARY}"
                     "${VPR23_LIBRARY}"
                     "${VRJ31_LIBRARY}"
                     pyjutil
)

install(TARGETS ${TARGET_NAME} DESTINATION PyJuggler/vrj)
install(FILES __init__.py DESTINATION PyJuggler/vrj)
