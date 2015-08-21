set(TARGET_NAME gadget)

# PYTHON_ADD_MODULE(${TARGET_NAME} gadget.cpp)
add_library(${TARGET_NAME} SHARED gadget.cpp)

target_include_directories(${TARGET_NAME} PRIVATE
                          "${Boost_INCLUDE_DIRS}"
                          "${PYTHON_INCLUDE_DIRS}"
                          "${GADGETEER21_INCLUDE_DIR}"
                          "${VPR23_INCLUDE_DIR}")

target_link_libraries(${TARGET_NAME}
                     "${Boost_LIBRARIES}"
                     "${PYTHON_LIBRARIES}"
                     "${GADGETEER21_LIBRARY}"
                     "${VPR23_LIBRARY}")
