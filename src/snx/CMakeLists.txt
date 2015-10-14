set(SRC_FILES
    __snx.cpp
    _sonix.cpp
    _SoundAPIInfo.cpp
    _SoundHandle.cpp
    _SoundImplementation.cpp
    _SoundInfo.cpp
)
set(TARGET_NAME __snx)

python_add_module(${TARGET_NAME} ${SRC_FILES})

target_include_directories(${TARGET_NAME} PRIVATE
                          ${Boost_INCLUDE_DIRS}
                          ${PYTHON_INCLUDE_DIRS}
                          "${SONIX15_INCLUDE_DIR}"
                          "${VPR23_INCLUDE_DIR}"
                          "${GMTL_INCLUDE_DIR}"
)

target_link_libraries(${TARGET_NAME}
                     ${Boost_LIBRARIES}
                     ${PYTHON_LIBRARIES}
                     "${SONIX15_LIBRARY}"
                     "${VPR23_LIBRARY}"
)

install (TARGETS ${TARGET_NAME} DESTINATION PyJuggler/snx)
install (FILES __init__.py DESTINATION PyJuggler/snx)
