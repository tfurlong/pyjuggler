set(SRC_FILES
    cluster.cpp
    _UserData.cpp
    ${CMAKE_SOURCE_DIR}/pyjutil/InterpreterGuard.cpp
)
set(TARGET_NAME cluster)

# PYTHON_ADD_MODULE(${TARGET_NAME} cluster.cpp)
add_library(${TARGET_NAME} SHARED ${SRC_FILES})

target_include_directories(${TARGET_NAME} PRIVATE
                          "${CMAKE_SOURCE_DIR}"
                          "${Boost_INCLUDE_DIRS}"
                          "${PYTHON_INCLUDE_DIRS}"
                          "${GADGETEER21_INCLUDE_DIR}"
                          "${JCCL15_INCLUDE_DIR}"
                          "${VPR23_INCLUDE_DIR}"
                          "${CPPDOM_INCLUDE_DIR}"
)

target_link_libraries(${TARGET_NAME}
                     "${Boost_LIBRARIES}"
                     "${PYTHON_LIBRARIES}"
                     "${GADGETEER21_LIBRARY}"
                     "${JCCL15_LIBRARY}"
                     "${VPR23_LIBRARY}"
                     "${CPPDOM_LIBRARY}"
)

install (TARGETS ${TARGET_NAME} DESTINATION PyJuggler)
