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

# PYTHON_ADD_MODULE(${TARGET_NAME} jccl.cpp)
add_library(${TARGET_NAME} SHARED ${SRC_FILES})
set_target_properties(${TARGET_NAME} PROPERTIES PREFIX "")

target_include_directories(${TARGET_NAME} PRIVATE
                          "${CMAKE_SOURCE_DIR}/include"
                          "${Boost_INCLUDE_DIRS}"
                          "${CPPDOM_INCLUDE_DIR}"
                          "${JCCL15_INCLUDE_DIR}"
                          "${PYTHON_INCLUDE_DIRS}"
                          "${VPR23_INCLUDE_DIR}"
)

target_link_libraries(${TARGET_NAME}
                     "${Boost_LIBRARIES}"
                     "${CPPDOM_LIBRARY}"
                     "${JCCL15_LIBRARY}"
                     "${PYTHON_LIBRARIES}"
                     "${VPR23_LIBRARY}"
)

install (TARGETS ${TARGET_NAME} DESTINATION PyJuggler/jccl)
install (FILES __init__.py DESTINATION PyJuggler/jccl)
