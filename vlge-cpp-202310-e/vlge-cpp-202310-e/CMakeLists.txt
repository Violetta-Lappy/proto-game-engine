cmake_minimum_required(VERSION 3.12) 
project(vlge-cpp-202309-e)
# Generate compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


if(NOT EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/include/miniaudio/miniaudio.h)
file(DOWNLOAD
https://raw.githubusercontent.com/mackron/miniaudio/0.11.18/miniaudio.h
${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/include/miniaudio/miniaudio.h)
endif()

add_library(fmt STATIC
${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/include/fmt/format.cpp
${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/include/fmt/core.h
${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/include/fmt/format.h
${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/include/fmt/format-inl.h
${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/include/fmt/ostream.h
)

add_library(glad STATIC
${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/include/glad/glad.c
${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/include/glad/glad.h
${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/include/KHR/khrplatform.h
)

#--Define Your Custom Project Here--

set(SOURCEFILE_COMMON 
"${CMAKE_CURRENT_SOURCE_DIR}/internal/engine/*.h" 
"${CMAKE_CURRENT_SOURCE_DIR}/internal/engine/*.cpp" 

#"${CMAKE_CURRENT_SOURCE_DIR}/internal/include/ae/*.h" 
#"${CMAKE_CURRENT_SOURCE_DIR}/internal/include/ae/*.cpp" 
#"${CMAKE_CURRENT_SOURCE_DIR}/internal/include/ge/*.h" 
#"${CMAKE_CURRENT_SOURCE_DIR}/internal/include/ge/*.cpp" 
#"${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/include/glad/*.h"
#"${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/include/glad/*.c"
#"${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/include/GLFW/*.h"
#"${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/include/GLFW/*.cpp"
#"${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/include/fmt/*.h"
#"${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/include/fmt/*.cpp"
#"${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/include/imgui/*.h"
#"${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/include/imgui/*.cpp"
)

file(GLOB_RECURSE SOURCEFILE_ALL CONFIGURE_DEPENDS
${SOURCEFILE_COMMON}
)

add_executable(${PROJECT_NAME} main.cpp)
#add_executable(launcher launcher.cpp ${SOURCEFILE_LAUNCHER})
#add_executable(app app.cpp ${SOURCEFILE_APP})
#add_executable(game game.cpp ${SOURCEFILE_GAME})
#add_executable(helpful helpful.cpp ${SOURCEFILE_HELPFUL})

target_include_directories(fmt 
PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/include/fmt 
)

target_include_directories(glad
PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/include/glad
PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/include/KHR
)

set(INTERNALPARTY
"${CMAKE_CURRENT_SOURCE_DIR}/internal/" 
"${CMAKE_CURRENT_SOURCE_DIR}/internal/engine" 
"${CMAKE_CURRENT_SOURCE_DIR}/internal/include" 
"${CMAKE_CURRENT_SOURCE_DIR}/internal/include/ae" 
"${CMAKE_CURRENT_SOURCE_DIR}/internal/include/ge" 
)

set(3RDPARTY 
fmt
glad
"${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/include" 
"${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/include/RmlUi/" 
"${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/include/GFLW" 
"${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/include/imgui"
"${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/include/miniaudio" 
)

target_include_directories(${PROJECT_NAME} PUBLIC ${INTERNALPARTY} PUBLIC ${3RDPARTY})
#target_include_directories(launcher)
#target_include_directories(app)
#target_include_directories(game)

set(3RDPARTY_LIB
winmm.lib
opengl32.lib
# Custom
fmt
glad
"${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/lib/freetype/freetype.lib"
"${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/lib/RmlUi/RmlCore.lib"
"${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/lib/RmlUi/RmlDebugger.lib"
"${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/lib/GLFW/glfw3.lib"
)

target_link_libraries(${PROJECT_NAME} PRIVATE ${3RDPARTY_LIB})
#target_link_libraries(launcher)
#target_link_libraries(app)
#target_link_libraries(game)
#target_link_libraries(helpful)

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

# After build, copy all necessary file to the build folder
add_custom_target(copy_assets
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_LIST_DIR}/program ${CMAKE_CURRENT_BINARY_DIR}/
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_LIST_DIR}/data ${CMAKE_CURRENT_BINARY_DIR}/data
)
add_dependencies(${PROJECT_NAME} copy_assets)