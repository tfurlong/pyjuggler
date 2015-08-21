set(TARGET_NAME vpr)

# PYTHON_ADD_MODULE(${TARGET_NAME} vpr.cpp)
add_library(${TARGET_NAME} SHARED vpr.cpp)

target_include_directories(${TARGET_NAME} PRIVATE
                          "${Boost_INCLUDE_DIRS}"
                          "${PYTHON_INCLUDE_DIRS}"
                          "${VPR23_INCLUDE_DIR}")

target_link_libraries(${TARGET_NAME}
                     "${Boost_LIBRARIES}"
                     "${PYTHON_LIBRARIES}"
                     "${VPR23_LIBRARY}")
