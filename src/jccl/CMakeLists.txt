set(TARGET_NAME jccl)

# PYTHON_ADD_MODULE(${TARGET_NAME} jccl.cpp)
add_library(${TARGET_NAME} SHARED jccl.cpp)

target_include_directories(${TARGET_NAME} PRIVATE
                          "${Boost_INCLUDE_DIRS}"
                          "${PYTHON_INCLUDE_DIRS}"
                          "${JCCL15_INCLUDE_DIR}"
                          "${VPR23_INCLUDE_DIR}")

target_link_libraries(${TARGET_NAME}
                     "${Boost_LIBRARIES}"
                     "${PYTHON_LIBRARIES}"
                     "${JCCL15_LIBRARY}"
                     "${VPR23_LIBRARY}")
