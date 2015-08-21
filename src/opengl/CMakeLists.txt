set(TARGET_NAME opengl)

# PYTHON_ADD_MODULE(TARGET_NAME opengl.cpp)
add_library(${TARGET_NAME} SHARED opengl.cpp)

target_include_directories(${TARGET_NAME} PRIVATE
                          "${Boost_INCLUDE_DIRS}"
                          "${PYTHON_INCLUDE_DIRS}")

target_link_libraries(${TARGET_NAME}
                     "${Boost_LIBRARIES}"
                     "${PYTHON_LIBRARIES}")
