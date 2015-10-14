set(SRC_FILES
    __jccl.cpp
    _ConfigDefinition.cpp
    _ConfigElement.cpp
    _ConfigElementHandler.cpp
    _ConfigManager.cpp
    _PropertyDefinition.cpp
    _VarType.cpp
)
set(TARGET_NAME __jccl)

python_add_module(${TARGET_NAME} ${SRC_FILES})

target_include_directories(${TARGET_NAME} PRIVATE
                          ${Boost_INCLUDE_DIRS}
                          ${PYTHON_INCLUDE_DIRS}
                          "${CMAKE_SOURCE_DIR}/include"
                          "${CPPDOM_INCLUDE_DIR}"
                          "${JCCL15_INCLUDE_DIR}"
                          "${VPR23_INCLUDE_DIR}"
)

target_link_libraries(${TARGET_NAME}
                     ${Boost_LIBRARIES}
                     ${PYTHON_LIBRARIES}
                     "${CPPDOM_LIBRARY}"
                     "${JCCL15_LIBRARY}"
                     "${VPR23_LIBRARY}"
)

install (TARGETS ${TARGET_NAME} DESTINATION PyJuggler/jccl)
install (FILES __init__.py DESTINATION PyJuggler/jccl)
