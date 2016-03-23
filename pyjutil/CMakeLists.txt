set(SRC_FILES InterpreterGuard.cpp)
set(TARGET_NAME pyjutil)

add_library(${TARGET_NAME} SHARED ${SRC_FILES})
# set_target_properties(${TARGET_NAME} PROPERTIES PREFIX "")

target_include_directories(${TARGET_NAME} PRIVATE
                           ${Boost_INCLUDE_DIRS}
                           ${PYTHON_INCLUDE_DIRS}
                           "${CMAKE_SOURCE_DIR}/include"
                           "${CMAKE_SOURCE_DIR}/include/pyjutil"
                           "${VPR23_INCLUDE_DIR}"
)

target_link_libraries(${TARGET_NAME}
                      ${Boost_LIBRARIES}
                      ${PYTHON_LIBRARIES}
                      "${VPR23_LIBRARY}"
)

install(TARGETS ${TARGET_NAME} DESTINATION PyJuggler)
