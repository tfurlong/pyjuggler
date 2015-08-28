set(SRC_FILES
    opengl.cpp
    _App.cpp
    _ContextData.cpp
    _DrawManager.cpp
)
set(TARGET_NAME opengl)

# PYTHON_ADD_MODULE(TARGET_NAME opengl.cpp)
add_library(${TARGET_NAME} SHARED ${SRC_FILES})

target_include_directories(${TARGET_NAME} PRIVATE
                          "${Boost_INCLUDE_DIRS}"
                          "${PYTHON_INCLUDE_DIRS}"
                          "${VRJ31_INCLUDE_DIR}"
                          "${VPR23_INCLUDE_DIR}"
                          "${JCCL15_INCLUDE_DIR}"
                          "${GMTL_INCLUDE_DIR}"
                          "${GADGETEER21_INCLUDE_DIR}"
                          "${CPPDOM_INCLUDE_DIR}"
                          "${CMAKE_SOURCE_DIR}/src"
                          "${CMAKE_SOURCE_DIR}"
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
