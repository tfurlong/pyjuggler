set(SRC_FILES
    vpr.cpp
    _GUID.cpp
    _InetAddr.cpp
    _Interval.cpp
    _ObjectReader.cpp
    _ObjectWriter.cpp
    _ReadableObject.cpp
    _ReadableObject.cpp
    _SerializableObject.cpp
    _WriteableObject.cpp
    ${CMAKE_SOURCE_DIR}/pyjutil/InterpreterGuard.cpp
)
set(TARGET_NAME vpr)

# PYTHON_ADD_MODULE(${TARGET_NAME} vpr.cpp)
add_library(${TARGET_NAME} SHARED ${SRC_FILES})

target_include_directories(${TARGET_NAME} PRIVATE
                          "${Boost_INCLUDE_DIRS}"
                          "${PYTHON_INCLUDE_DIRS}"
                          "${VPR23_INCLUDE_DIR}"
                          "${CMAKE_SOURCE_DIR}/src"
                          "${CMAKE_SOURCE_DIR}"
)

target_link_libraries(${TARGET_NAME}
                     "${Boost_LIBRARIES}"
                     "${PYTHON_LIBRARIES}"
                     "${VPR23_LIBRARY}"
)

install (TARGETS ${TARGET_NAME} DESTINATION PyJuggler)
