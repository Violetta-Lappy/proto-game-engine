# https://cmake.org/cmake/help/latest/module/FetchContent.html
# FetchContent is available in 3.11+
cmake_minimum_required(VERSION 3.11) 

project(vlge-cpp-202309-d)

# Generate compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Dependencies

#--raylib package--
set(RAYLIB_VERSION 4.5.0)
find_package(raylib ${RAYLIB_VERSION} QUIET) # QUIET or REQUIRED
if (NOT raylib_FOUND) # If there's none, fetch and build raylib
  include(FetchContent)
  FetchContent_Declare(
    raylib
    DOWNLOAD_EXTRACT_TIMESTAMP OFF
    URL https://github.com/raysan5/raylib/archive/refs/tags/${RAYLIB_VERSION}.tar.gz
  )
  FetchContent_GetProperties(raylib)
  if (NOT raylib_POPULATED) # Have we downloaded raylib yet?
    set(FETCHCONTENT_QUIET NO)
    FetchContent_Populate(raylib)
    set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
    add_subdirectory(${raylib_SOURCE_DIR} ${raylib_BINARY_DIR})
  endif()
endif()

#--fmt package--
set(FMT_VERSION 10.1.1)
find_package(fmt ${FMT_VERSION} QUIET) # QUIET or REQUIRED
# If there's none, fetch and build
if (NOT fmt_FOUND) 
  include(FetchContent)
  FetchContent_Declare(
    fmt
    DOWNLOAD_EXTRACT_TIMESTAMP OFF
    URL https://github.com/fmtlib/fmt/archive/refs/tags/${FMT_VERSION}.tar.gz
  )  
  FetchContent_GetProperties(fmt)
  # Have we downloaded yet?
  if (NOT fmt_POPULATED) 
    set(FETCHCONTENT_QUIET NO)
    FetchContent_Populate(fmt)
    add_subdirectory(${fmt_SOURCE_DIR} ${fmt_BINARY_DIR})
  endif()
endif()

#--Define Your Custom Project Here--

file(GLOB_RECURSE SOURCEFILE_ALL CONFIGURE_DEPENDS
"${CMAKE_CURRENT_SOURCE_DIR}/LauncherEngine/*.cpp"    
"${CMAKE_CURRENT_SOURCE_DIR}/LauncherProgram/*.cpp"    
"${CMAKE_CURRENT_SOURCE_DIR}/AppEngine/*.cpp"    
"${CMAKE_CURRENT_SOURCE_DIR}/AppProgram/*.cpp"    
"${CMAKE_CURRENT_SOURCE_DIR}/GameEngine/*.cpp"    
"${CMAKE_CURRENT_SOURCE_DIR}/GameProgram/*.cpp"    
"${CMAKE_CURRENT_SOURCE_DIR}/Constant/*.cpp"    
"${CMAKE_CURRENT_SOURCE_DIR}/ArgumentException/*.cpp"    
"${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/imgui/*.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/rlImgui/*.cpp"

"${CMAKE_CURRENT_SOURCE_DIR}/LauncherEngine/*.h"    
"${CMAKE_CURRENT_SOURCE_DIR}/LauncherProgram/*.h"    
"${CMAKE_CURRENT_SOURCE_DIR}/AppEngine/*.h"    
"${CMAKE_CURRENT_SOURCE_DIR}/AppProgram/*.h"    
"${CMAKE_CURRENT_SOURCE_DIR}/GameEngine/*.h"    
"${CMAKE_CURRENT_SOURCE_DIR}/GameProgram/*.h"    
"${CMAKE_CURRENT_SOURCE_DIR}/Constant/*.h"    
"${CMAKE_CURRENT_SOURCE_DIR}/ArgumentException/*.h"    
"${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/imgui/*.h"
"${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/rlImgui/*.h"
)

file(GLOB_RECURSE SOURCEFILE_LAUNCHER CONFIGURE_DEPENDS
"${CMAKE_CURRENT_SOURCE_DIR}/LauncherEngine/*.cpp"    
"${CMAKE_CURRENT_SOURCE_DIR}/LauncherProgram/*.cpp"    
"${CMAKE_CURRENT_SOURCE_DIR}/Constant/*.cpp"    
"${CMAKE_CURRENT_SOURCE_DIR}/ArgumentException/*.cpp"    
"${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/imgui/*.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/rlImgui/*.cpp"

"${CMAKE_CURRENT_SOURCE_DIR}/LauncherEngine/*.h"    
"${CMAKE_CURRENT_SOURCE_DIR}/LauncherProgram/*.h"    
"${CMAKE_CURRENT_SOURCE_DIR}/Constant/*.h"    
"${CMAKE_CURRENT_SOURCE_DIR}/ArgumentException/*.h"    
"${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/imgui/*.h"
"${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/rlImgui/*.h"
)

file(GLOB_RECURSE SOURCEFILE_APP CONFIGURE_DEPENDS
"${CMAKE_CURRENT_SOURCE_DIR}/AppEngine/*.cpp"    
"${CMAKE_CURRENT_SOURCE_DIR}/AppProgram/*.cpp"    
"${CMAKE_CURRENT_SOURCE_DIR}/Constant/*.cpp"    
"${CMAKE_CURRENT_SOURCE_DIR}/ArgumentException/*.cpp"    
"${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/imgui/*.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/rlImgui/*.cpp"

"${CMAKE_CURRENT_SOURCE_DIR}/AppEngine/*.h"    
"${CMAKE_CURRENT_SOURCE_DIR}/AppProgram/*.h"    
"${CMAKE_CURRENT_SOURCE_DIR}/Constant/*.h"    
"${CMAKE_CURRENT_SOURCE_DIR}/ArgumentException/*.h"    
"${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/imgui/*.h"
"${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/rlImgui/*.h"
)

file(GLOB_RECURSE SOURCEFILE_GAME CONFIGURE_DEPENDS
"${CMAKE_CURRENT_SOURCE_DIR}/GameEngine/*.cpp"    
"${CMAKE_CURRENT_SOURCE_DIR}/GameProgram/*.cpp"    
"${CMAKE_CURRENT_SOURCE_DIR}/Constant/*.cpp"    
"${CMAKE_CURRENT_SOURCE_DIR}/ArgumentException/*.cpp"    
"${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/imgui/*.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/rlImgui/*.cpp"

"${CMAKE_CURRENT_SOURCE_DIR}/GameEngine/*.h"    
"${CMAKE_CURRENT_SOURCE_DIR}/GameProgram/*.h"    
"${CMAKE_CURRENT_SOURCE_DIR}/Constant/*.h"    
"${CMAKE_CURRENT_SOURCE_DIR}/ArgumentException/*.h"    
"${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/imgui/*.h"
"${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/rlImgui/*.h"
)

file(GLOB_RECURSE SOURCEFILE_HELPFUL CONFIGURE_DEPENDS
"${CMAKE_CURRENT_SOURCE_DIR}/GameEngine/*.cpp"    
"${CMAKE_CURRENT_SOURCE_DIR}/GameProgram/*.cpp"    
"${CMAKE_CURRENT_SOURCE_DIR}/Constant/*.cpp"    
"${CMAKE_CURRENT_SOURCE_DIR}/ArgumentException/*.cpp"    
"${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/imgui/*.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/rlImgui/*.cpp"

"${CMAKE_CURRENT_SOURCE_DIR}/GameEngine/*.h"    
"${CMAKE_CURRENT_SOURCE_DIR}/GameProgram/*.h"    
"${CMAKE_CURRENT_SOURCE_DIR}/Constant/*.h"    
"${CMAKE_CURRENT_SOURCE_DIR}/ArgumentException/*.h"    
"${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/imgui/*.h"
"${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/rlImgui/*.h"
)

add_executable(${PROJECT_NAME} main.cpp ${SOURCEFILE_ALL})
add_executable(launcher launcher.cpp ${SOURCEFILE_LAUNCHER})
add_executable(app app.cpp ${SOURCEFILE_APP})
add_executable(game game.cpp ${SOURCEFILE_GAME})
#add_executable(helpful helpful.cpp ${SOURCEFILE_HELPFUL})

set(3RDPARTY 
"${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/imgui" 
"${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/rlImgui"
)

target_include_directories(${PROJECT_NAME} PUBLIC ${3RDPARTY})
target_include_directories(launcher PUBLIC ${3RDPARTY})
target_include_directories(app PUBLIC ${3RDPARTY})
target_include_directories(game PUBLIC ${3RDPARTY})

set(3RDPARTY_LIB 
raylib 
fmt 
)

#set(raylib_VERBOSE 1)
target_link_libraries(${PROJECT_NAME} ${3RDPARTY_LIB})
target_link_libraries(launcher ${3RDPARTY_LIB})
target_link_libraries(app ${3RDPARTY_LIB})
target_link_libraries(game ${3RDPARTY_LIB})
#target_link_libraries(helpful raylib)

# Web Configurations
if (${PLATFORM} STREQUAL "Web")
    # Tell Emscripten to build an example.html file.
    set_target_properties(${PROJECT_NAME} PROPERTIES SUFFIX ".html")
endif()

# Checks if OSX and links appropriate frameworks (Only required on MacOS)
if (APPLE)
    target_link_libraries(${PROJECT_NAME} "-framework IOKit")
    target_link_libraries(${PROJECT_NAME} "-framework Cocoa")
    target_link_libraries(${PROJECT_NAME} "-framework OpenGL")
endif()