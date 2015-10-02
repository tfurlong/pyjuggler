set(SRC_FILES
    __vpr.cpp
    _GUID.cpp
    _InetAddr.cpp
    _Interval.cpp
    _ObjectReader.cpp
    _ObjectWriter.cpp
    _ReadableObject.cpp
    _ReadableObject.cpp
    _SerializableObject.cpp
    _WriteableObject.cpp
)
set(TARGET_NAME __vpr)

# PYTHON_ADD_MODULE(${TARGET_NAME} vpr.cpp)
add_library(${TARGET_NAME} SHARED ${SRC_FILES})
set_target_properties(${TARGET_NAME} PROPERTIES PREFIX "")
set_target_properties(${TARGET_NAME} PROPERTIES SUFFIX ".pyd")

target_include_directories(${TARGET_NAME} PRIVATE
                          "${CMAKE_SOURCE_DIR}/include"
                          "${Boost_INCLUDE_DIRS}"
                          "${PYTHON_INCLUDE_DIRS}"
                          "${VPR23_INCLUDE_DIR}"
)

target_link_libraries(${TARGET_NAME}
                     "${Boost_LIBRARIES}"
                     "${PYTHON_LIBRARIES}"
                     "${VPR23_LIBRARY}"
                     pyjutil
)

install (TARGETS ${TARGET_NAME} DESTINATION PyJuggler/vpr)
install(FILES __init__.py DESTINATION PyJuggler/vpr)
