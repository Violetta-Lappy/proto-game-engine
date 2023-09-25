cmake_minimum_required(VERSION 3.12) 
project(vlge-cpp-202309-e)
# Generate compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


if(NOT EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/include/miniaudio/miniaudio.h)
file(DOWNLOAD
https://raw.githubusercontent.com/mackron/miniaudio/0.11.18/miniaudio.h
${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/include/miniaudio/miniaudio.h)
endif()

#--Define Your Custom Project Here--

set(SOURCEFILE_COMMON 
"${CMAKE_CURRENT_SOURCE_DIR}/internal/engine/*.cpp" 
"${CMAKE_CURRENT_SOURCE_DIR}/internal/include/ae/*.cpp" 
"${CMAKE_CURRENT_SOURCE_DIR}/internal/include/ge/*.cpp" 
"${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/include/fmt/*.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/include/imgui/*.cpp"

"${CMAKE_CURRENT_SOURCE_DIR}/internal/engine/*.h" 
"${CMAKE_CURRENT_SOURCE_DIR}/internal/include/ae/*.h" 
"${CMAKE_CURRENT_SOURCE_DIR}/internal/include/ge/*.h" 
"${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/include/fmt/*.h"
"${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/include/imgui/*.h"
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
"${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/include/GFLW" 
"${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/include/imgui"
"${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/include/fmt"
"${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/include/miniaudio" 
)

target_include_directories(${PROJECT_NAME} PUBLIC ${INTERNALPARTY} PUBLIC ${3RDPARTY})
#target_include_directories(launcher)
#target_include_directories(app)
#target_include_directories(game)

set(3RDPARTY_LIB 
"${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/lib/GLFW/glfw3.lib"
#"${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/lib/freetype/freetype.lib"
#"${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/lib/rmlui/RmlCore.lib"
#"${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/lib/rmlui/RmlDebugger.lib"
)

#set(raylib_VERBOSE 1)
target_link_libraries(${PROJECT_NAME} ${3RDPARTY_LIB})
#target_link_libraries(launcher)
#target_link_libraries(app)
#target_link_libraries(game)
#target_link_libraries(helpful)


if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.

# Web Configurations
#if (${PLATFORM} STREQUAL "Web")
# Tell Emscripten to build an example.html file.
#set_target_properties(${PROJECT_NAME} PROPERTIES SUFFIX ".html")
#endif()

# Checks if OSX and links appropriate frameworks (Only required on MacOS)
if (APPLE)
    target_link_libraries(${PROJECT_NAME} "-framework IOKit")
    target_link_libraries(${PROJECT_NAME} "-framework Cocoa")
    target_link_libraries(${PROJECT_NAME} "-framework OpenGL")
endif()
