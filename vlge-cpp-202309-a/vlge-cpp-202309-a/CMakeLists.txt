# CMakeList.txt : CMake project for vlge-cpp-202309-a, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (vlge-cpp-202309-a "vlge-cpp-202309-a.cpp" "vlge-cpp-202309-a.h" "transform.cpp" "transform.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET vlge-cpp-202309-a PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
