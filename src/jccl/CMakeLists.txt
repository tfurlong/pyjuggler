set(SRC_FILES
    jccl.cpp
    _ConfigDefinition.cpp
    _ConfigElement.cpp
    _ConfigElementHandler.cpp
    _ConfigManager.cpp
    _PropertyDefinition.cpp
    _VarType.cpp
)
set(TARGET_NAME jccl)

# PYTHON_ADD_MODULE(${TARGET_NAME} jccl.cpp)
add_library(${TARGET_NAME} SHARED ${SRC_FILES})

target_include_directories(${TARGET_NAME} PRIVATE
                          "${Boost_INCLUDE_DIRS}"
                          "${PYTHON_INCLUDE_DIRS}"
                          "${JCCL15_INCLUDE_DIR}"
                          "${VPR23_INCLUDE_DIR}"
                          "${CPPDOM_INCLUDE_DIR}"
                          "${CMAKE_SOURCE_DIR}/src"
)

target_link_libraries(${TARGET_NAME}
                     "${Boost_LIBRARIES}"
                     "${PYTHON_LIBRARIES}"
                     "${JCCL15_LIBRARY}"
                     "${VPR23_LIBRARY}"
                     "${CPPDOM_LIBRARY}"
)

install (TARGETS ${TARGET_NAME} DESTINATION PyJuggler)
