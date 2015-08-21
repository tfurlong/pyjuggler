set(TARGET_NAME __vrj)

# PYTHON_ADD_MODULE(${TARGET_NAME} __vrj.cpp)
add_library(${TARGET_NAME} SHARED __vrj.cpp)

target_include_directories(${TARGET_NAME} PRIVATE
                          "${Boost_INCLUDE_DIRS}"
                          "${PYTHON_INCLUDE_DIRS}"
                          "${VRJ31_INCLUDE_DIR}"
                          "${VPR23_INCLUDE_DIR}")

target_link_libraries(${TARGET_NAME}
                     "${Boost_LIBRARIES}"
                     "${PYTHON_LIBRARIES}"
                     "${VRJ31_LIBRARY}"
                     "${VPR23_LIBRARY}")
