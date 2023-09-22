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

set(SOURCEFILE_COMMON 
"${CMAKE_CURRENT_SOURCE_DIR}/internal/engine/*.cpp" 
"${CMAKE_CURRENT_SOURCE_DIR}/internal/include/ae/*.cpp" 
"${CMAKE_CURRENT_SOURCE_DIR}/internal/include/ge/*.cpp" 
"${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/include/imgui/*.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/include/rlimgui/*.cpp"

"${CMAKE_CURRENT_SOURCE_DIR}/internal/engine/*.h" 
"${CMAKE_CURRENT_SOURCE_DIR}/internal/include/ae/*.h" 
"${CMAKE_CURRENT_SOURCE_DIR}/internal/include/ge/*.h" 
"${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/include/imgui/*.h"
"${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/include/rlimgui/*.h"
)

file(GLOB_RECURSE SOURCEFILE_ALL CONFIGURE_DEPENDS
${SOURCEFILE_COMMON}
)

file(GLOB_RECURSE SOURCEFILE_LAUNCHER CONFIGURE_DEPENDS
${SOURCEFILE_COMMON}
)

file(GLOB_RECURSE SOURCEFILE_APP CONFIGURE_DEPENDS
${SOURCEFILE_COMMON}
)

file(GLOB_RECURSE SOURCEFILE_GAME CONFIGURE_DEPENDS
${SOURCEFILE_COMMON}
)

file(GLOB_RECURSE SOURCEFILE_HELPFUL CONFIGURE_DEPENDS
${SOURCEFILE_COMMON}
)

add_executable(${PROJECT_NAME} main.cpp ${SOURCEFILE_ALL})
#add_executable(launcher launcher.cpp ${SOURCEFILE_LAUNCHER})
#add_executable(app app.cpp ${SOURCEFILE_APP})
#add_executable(game game.cpp ${SOURCEFILE_GAME})
#add_executable(helpful helpful.cpp ${SOURCEFILE_HELPFUL})

set(INTERNALPARTY
"${CMAKE_CURRENT_SOURCE_DIR}/internal/" 
"${CMAKE_CURRENT_SOURCE_DIR}/internal/engine" 
"${CMAKE_CURRENT_SOURCE_DIR}/internal/include" 
"${CMAKE_CURRENT_SOURCE_DIR}/internal/include/ae" 
"${CMAKE_CURRENT_SOURCE_DIR}/internal/include/ge" 
)

set(3RDPARTY 
"${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/include" 
"${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/include/imgui" 
"${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/include/rlimgui" 
"${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/include/rmlui" 
)

target_include_directories(${PROJECT_NAME} PUBLIC ${INTERNALPARTY} PUBLIC ${3RDPARTY})
#target_include_directories(launcher)
#target_include_directories(app)
#target_include_directories(game)

set(3RDPARTY_LIB 
raylib 
fmt 
"${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/lib/freetype/freetype.lib"
"${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/lib/rmlui/RmlCore.lib"
"${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/lib/rmlui/RmlDebugger.lib"
)

#set(raylib_VERBOSE 1)
target_link_libraries(${PROJECT_NAME} ${3RDPARTY_LIB})
#target_link_libraries(launcher)
#target_link_libraries(app)
#target_link_libraries(game)
#target_link_libraries(helpful)

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