set(SRC_FILES InterpreterGuard.cpp)
set(TARGET_NAME pyjutil)

add_library(${TARGET_NAME} SHARED ${SRC_FILES})
# set_target_properties(${TARGET_NAME} PROPERTIES PREFIX "")

target_include_directories(${TARGET_NAME} PRIVATE
                           "${CMAKE_SOURCE_DIR}/include"
                           "${CMAKE_SOURCE_DIR}/include/pyjutil"
                           "${PYTHON_INCLUDE_DIRS}"
                           "${VPR23_INCLUDE_DIR}"
)

target_link_libraries(${TARGET_NAME}
                      "${PYTHON_LIBRARIES}"
                      "${VPR23_LIBRARY}"
)

install(TARGETS ${TARGET_NAME} DESTINATION PyJuggler)
