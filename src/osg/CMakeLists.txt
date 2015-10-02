set(SRC_FILES
    __osg.cpp
    _App.cpp
)
set(TARGET_NAME __osg)

# PYTHON_ADD_MODULE(${TARGET_NAME} osg.cpp)
add_library(${TARGET_NAME} SHARED ${SRC_FILES})
set_target_properties(${TARGET_NAME} PROPERTIES PREFIX "")
set_target_properties(${TARGET_NAME} PROPERTIES SUFFIX ".pyd")

target_include_directories(${TARGET_NAME} PRIVATE
                          "${Boost_INCLUDE_DIRS}"
                          "${PYTHON_INCLUDE_DIRS}"
                          "${VRJ31_INCLUDE_DIR}"
                          "${VPR23_INCLUDE_DIR}"
                          "${JCCL15_INCLUDE_DIR}"
)

target_link_libraries(${TARGET_NAME}
                     "${Boost_LIBRARIES}"
                     "${PYTHON_LIBRARIES}"
                     "${VRJ31_LIBRARY}"
                     "${VPR23_LIBRARY}"
                     "${JCCL15_LIBRARY}"
)

install (TARGETS ${TARGET_NAME} DESTINATION PyJuggler/osg)
install (FILES __init__.py DESTINATION PyJuggler/osg)
