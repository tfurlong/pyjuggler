set(SRC_FILES
    __cluster.cpp
    _UserData.cpp
)
set(TARGET_NAME __cluster)

python_add_module(${TARGET_NAME} ${SRC_FILES})

target_include_directories(${TARGET_NAME} PRIVATE
                          ${Boost_INCLUDE_DIRS}
                          ${PYTHON_INCLUDE_DIRS}
                          "${CMAKE_SOURCE_DIR}/include"
                          "${CPPDOM_INCLUDE_DIR}"
                          "${GADGETEER21_INCLUDE_DIR}"
                          "${JCCL15_INCLUDE_DIR}"
                          "${VPR23_INCLUDE_DIR}"
)

target_link_libraries(${TARGET_NAME}
                     ${Boost_LIBRARIES}
                     ${PYTHON_LIBRARIES}
                     "${CPPDOM_LIBRARY}"
                     "${GADGETEER21_LIBRARY}"
                     "${JCCL15_LIBRARY}"
                     "${VPR23_LIBRARY}"
                     pyjutil
)

install (TARGETS ${TARGET_NAME} DESTINATION PyJuggler/cluster)
install (FILES __init__.py DESTINATION PyJuggler/cluster)
