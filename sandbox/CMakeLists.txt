add_executable(sandbox main.cpp
        Game.cpp
        Game.h
        MyScene.cpp
        MyScene.h
)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "$<0:>${CMAKE_BINARY_DIR}/bin") # .exe and .dll
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "$<0:>${CMAKE_BINARY_DIR}/lib") # .so and .dylib
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "$<0:>${CMAKE_BINARY_DIR}/lib") # .lib and .a

# copy shaders

configure_file(shaders/shader.vert ${CMAKE_CURRENT_BINARY_DIR}/Debug/shaders/shader.vert COPYONLY)
configure_file(shaders/shader.frag ${CMAKE_CURRENT_BINARY_DIR}/Debug/shaders/shader.frag COPYONLY)

# GLAD
add_library(glad STATIC ${CMAKE_SOURCE_DIR}/libs/src/glad.c)
target_link_libraries(sandbox glad)

# Link GLFW library
add_library(glfw STATIC IMPORTED)
set_target_properties(glfw PROPERTIES
        IMPORTED_LOCATION "${CMAKE_SOURCE_DIR}/libs/lib/glfw3.lib"
        INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_SOURCE_DIR}/libs/include")
target_link_libraries(sandbox glfw)

include_directories(
        ../snow/src
        ${CMAKE_SOURCE_DIR}/libs/include
)

set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")

target_link_libraries(
        sandbox
        snow
)
