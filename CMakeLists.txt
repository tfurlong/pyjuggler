cmake_minimum_required(VERSION 2.8.3)
project(PyJuggler)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake" "${CMAKE_MODULE_PATH}")

# set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/PyJuggler")
# set(CMAKE_INSTALL_PREFIX "/home/STUDENTS/cemegginson/usr/pythonlibs")

if (${CMAKE_CXX_COMPILER_ID} STREQUAL "GNU" OR ${CMAKE_CXX_COMPILER_ID} STREQUAL "Clang")
	# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic -std=c++11")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -std=c++11")
	set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_DEBUG} -g")
	set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_RELEASE} -O2")
elseif (${CMAKE_CXX_COMPILER_ID} STREQUAL "MSVC")
	if (CMAKE_CXX_FLAGS MATCHES "/W[0-4]")
		string(REGEX REPLACE "/W[0-4]" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
	else()
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
	endif()
endif()

include("PrintAlignedVariables")

set(BOOST_COMPONENT_LIST
    python
    date_time
    filesystem
    program_options
    regex
    system
)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_LIBS OFF)
add_definitions("-DBOOST_ALL_DYN_LINK")
find_package(Boost COMPONENTS ${BOOST_COMPONENT_LIST} REQUIRED)
# message(STATUS "Boost_LIBRARIES = ${Boost_LIBRARIES}")
print_aligned_variables(
    Boost_INCLUDE_DIRS
    Boost_PYTHON_LIBRARIES
    Boost_DATE_TIME_LIBRARIES
    Boost_FILESYSTEM_LIBRARIES
    Boost_PROGRAM_OPTIONS_LIBRARIES
    Boost_REGEX_LIBRARIES
    Boost_SYSTEM_LIBRARIES
)

find_package(CPPDOM REQUIRED)
find_package(GMTL REQUIRED)
find_package(PythonInterp REQUIRED)
find_package(PythonLibs REQUIRED)
find_package(VPR23 REQUIRED)
find_package(Gadgeteer21 REQUIRED)
find_package(JCCL15 REQUIRED)
find_package(Sonix15 REQUIRED)
find_package(VRJ31 REQUIRED)
find_package(VRJOGL31 REQUIRED)
find_package(VRJuggler31 REQUIRED)


# ENABLE_TESTING()

add_subdirectory("${CMAKE_SOURCE_DIR}/pyjutil")
add_subdirectory("${CMAKE_SOURCE_DIR}/dist")
add_subdirectory("${CMAKE_SOURCE_DIR}/src/cluster")
add_subdirectory("${CMAKE_SOURCE_DIR}/src/gadget")
add_subdirectory("${CMAKE_SOURCE_DIR}/src/jccl")
add_subdirectory("${CMAKE_SOURCE_DIR}/src/opengl")
# add_subdirectory("${CMAKE_SOURCE_DIR}/src/opensg")
# add_subdirectory("${CMAKE_SOURCE_DIR}/src/osg")
add_subdirectory("${CMAKE_SOURCE_DIR}/src/snx")
add_subdirectory("${CMAKE_SOURCE_DIR}/src/vpr")
add_subdirectory("${CMAKE_SOURCE_DIR}/src/vrj")

# if(CMAKE_HOST_SYSTEM_NAME STREQUAL "Windows")
#     add_subdirectory("${CMAKE_SOURCE_DIR}/src/direct3d")
# endif()
