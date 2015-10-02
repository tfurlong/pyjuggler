set(SRC_FILES
    __direct3d.cpp
    _App.cpp
)
set(TARGET_NAME __direct3d)

# PYTHON_ADD_MODULE(${TARGET_NAME} direct3d.cpp)
add_library(${TARGET_NAME} SHARED ${SRC_FILES})
set_target_properties(${TARGET_NAME} PROPERTIES PREFIX "")
set_target_properties(${TARGET_NAME} PROPERTIES SUFFIX ".pyd")

target_include_directories(${TARGET_NAME} PRIVATE
                          "${Boost_INCLUDE_DIRS}"
                          "${PYTHON_INCLUDE_DIRS}"
                          "${VRJ31_INCLUDE_DIR}"
                          "${VPR23_INCLUDE_DIR}"
                          "${JCCL15_INCLUDE_DIR}"
                          "${GADGETEER21_INCLUDE_DIR}"
                          "${GMTL_INCLUDE_DIR}"
)

target_link_libraries(${TARGET_NAME}
                     "${Boost_LIBRARIES}"
                     "${PYTHON_LIBRARIES}"
                     "${VRJ31_LIBRARY}"
                     "${VPR23_LIBRARY}"
                     "${JCCL15_LIBRARY}"
                     "${GADGETEER21_LIBRARY}"
)

install (TARGETS ${TARGET_NAME} DESTINATION PyJuggler/direct3d)
install (FILES __init__.py DESTINATION PyJuggler/direct3d)
