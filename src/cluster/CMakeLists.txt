set(SRC_FILES
    __cluster.cpp
    _UserData.cpp
)
set(TARGET_NAME __cluster)

# PYTHON_ADD_MODULE(${TARGET_NAME} cluster.cpp)
add_library(${TARGET_NAME} SHARED ${SRC_FILES})
set_target_properties(${TARGET_NAME} PROPERTIES PREFIX "")

# Python on Windows is lame and will only load binary libraries with the .pyd
# extension.
if(CMAKE_HOST_SYSTEM_NAME STREQUAL "Windows")
    set_target_properties(${TARGET_NAME} PROPERTIES SUFFIX ".pyd")
endif()

target_include_directories(${TARGET_NAME} PRIVATE
                          "${CMAKE_SOURCE_DIR}/include"
                          "${Boost_INCLUDE_DIRS}"
                          "${CPPDOM_INCLUDE_DIR}"
                          "${GADGETEER21_INCLUDE_DIR}"
                          "${JCCL15_INCLUDE_DIR}"
                          "${PYTHON_INCLUDE_DIRS}"
                          "${VPR23_INCLUDE_DIR}"
)

target_link_libraries(${TARGET_NAME}
                     "${Boost_LIBRARIES}"
                     "${CPPDOM_LIBRARY}"
                     "${GADGETEER21_LIBRARY}"
                     "${JCCL15_LIBRARY}"
                     "${PYTHON_LIBRARIES}"
                     "${VPR23_LIBRARY}"
                     pyjutil
)

install (TARGETS ${TARGET_NAME} DESTINATION PyJuggler/cluster)
install (FILES __init__.py DESTINATION PyJuggler/cluster)
