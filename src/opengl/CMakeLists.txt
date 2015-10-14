set(SRC_FILES
    __opengl.cpp
    _App.cpp
    _ContextData.cpp
    _DrawManager.cpp
)
set(TARGET_NAME __opengl)

# PYTHON_ADD_MODULE(TARGET_NAME opengl.cpp)
# add_library(${TARGET_NAME} SHARED ${SRC_FILES})
# set_target_properties(${TARGET_NAME} PROPERTIES PREFIX "")

# Python on Windows is lame and will only load binary libraries with the .pyd
# extension.
# if(CMAKE_HOST_SYSTEM_NAME STREQUAL "Windows")
#     set_target_properties(${TARGET_NAME} PROPERTIES SUFFIX ".pyd")
# endif()

python_add_module(${TARGET_NAME} ${SRC_FILES})

target_include_directories(${TARGET_NAME} PRIVATE
                          ${Boost_INCLUDE_DIRS}
                          ${PYTHON_INCLUDE_DIRS}
                          ${VRJOGL31_INCLUDE_DIRS}
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
                     "${VRJOGL31_LIBRARY}"
                     pyjutil
)

install (TARGETS ${TARGET_NAME} DESTINATION PyJuggler/vrj/opengl)
install (FILES __init__.py DESTINATION PyJuggler/vrj/opengl)
