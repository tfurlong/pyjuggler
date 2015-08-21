set(TARGET_NAME snx)

# PYTHON_ADD_MODULE(${TARGET_NAME} snx.cpp)
add_library(${TARGET_NAME} SHARED snx.cpp)

target_include_directories(${TARGET_NAME} PRIVATE
                          "${Boost_INCLUDE_DIRS}"
                          "${PYTHON_INCLUDE_DIRS}"
                          "${SONIX15_INCLUDE_DIR}"
                          "${VPR23_INCLUDE_DIR}")

target_link_libraries(${TARGET_NAME}
                     "${Boost_LIBRARIES}"
                     "${PYTHON_LIBRARIES}"
                     "${SONIX15_LIBRARY}"
                     "${VPR23_LIBRARY}")
