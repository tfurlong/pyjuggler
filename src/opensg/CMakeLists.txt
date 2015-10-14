set(SRC_FILES
    __opensg.cpp
    _App.cpp
)
set(TARGET_NAME __opensg)

python_add_module(${TARGET_NAME} ${SRC_FILES})

target_include_directories(${TARGET_NAME} PRIVATE
                          ${Boost_INCLUDE_DIRS}
                          ${PYTHON_INCLUDE_DIRS}
                          "${VRJ31_INCLUDE_DIR}"
                          "${VPR23_INCLUDE_DIR}"
                          "${JCCL15_INCLUDE_DIR}"
                          "${GMTL_INCLUDE_DIR}"
)

target_link_libraries(${TARGET_NAME}
                     ${Boost_LIBRARIES}
                     ${PYTHON_LIBRARIES}
                     "${VRJ31_LIBRARY}"
                     "${VPR23_LIBRARY}"
                     "${JCCL15_LIBRARY}"
)

install (TARGETS ${TARGET_NAME} DESTINATION PyJuggler/opensg)
install (FILES __init__.py DESTINATION PyJuggler/opensg)
