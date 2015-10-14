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
