cmake_minimum_required(VERSION 2.8.3)
project(PyJuggler)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake" "${CMAKE_MODULE_PATH}")

find_package(PythonInterp)
find_package(PythonLibs)
find_package(Boost COMPONENTS python)
find_package(JCCL15)
find_package(Sonix15)
find_package(VPR23)
find_package(VRJ31)
find_package(VRJOGL31)
find_package(VRJuggler31)

# ENABLE_TESTING()
# target_include_directories(${Boost_INCLUDE_DIRS} ${PYTHON_INCLUDE_DIRS})
# link_libraries(${Boost_LIBRARIES} ${PYTHON_LIBRARIES}) # Deprecated but so convenient!

add_subdirectory("${CMAKE_SOURCE_DIR}/src/cluster")
add_subdirectory("${CMAKE_SOURCE_DIR}/src/direct3d")
add_subdirectory("${CMAKE_SOURCE_DIR}/src/gadget")
add_subdirectory("${CMAKE_SOURCE_DIR}/src/jccl")
add_subdirectory("${CMAKE_SOURCE_DIR}/src/opengl")
add_subdirectory("${CMAKE_SOURCE_DIR}/src/opensg")
add_subdirectory("${CMAKE_SOURCE_DIR}/src/osg")
add_subdirectory("${CMAKE_SOURCE_DIR}/src/snx")
add_subdirectory("${CMAKE_SOURCE_DIR}/src/vpr")
add_subdirectory("${CMAKE_SOURCE_DIR}/src/vrj")
