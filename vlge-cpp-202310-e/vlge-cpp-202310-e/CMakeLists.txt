# CMakeList.txt : CMake project for vlge-cpp-202310-e, include source and define
# project specific logic here.
#

if(NOT EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/include/miniaudio/miniaudio.h)

file(DOWNLOAD
https://raw.githubusercontent.com/mackron/miniaudio/0.11.18/miniaudio.h
${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/include/miniaudio/miniaudio.h)

endif()

# Add source to this project's executable.
add_executable (vlge-cpp-202310-e "vlge-cpp-202310-e.cpp" "vlge-cpp-202310-e.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET vlge-cpp-202310-e PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
