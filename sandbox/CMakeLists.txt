add_executable(sandbox main.cpp
        Game.cpp
        Game.h
        MyScene.cpp
        MyScene.h
)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin") # .exe and .dll
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib") # .so and .dylib
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib") # .lib and .a

# copy shaders

configure_file(shaders/shader.vert ${CMAKE_CURRENT_BINARY_DIR}/Debug/shaders/shader.vert COPYONLY)
configure_file(shaders/shader.frag ${CMAKE_CURRENT_BINARY_DIR}/Debug/shaders/shader.frag COPYONLY)

<<<<<<< HEAD

=======
>>>>>>> e8247a586280afffd386c0b23859685e1f5de6d2
include_directories(
        ../snow/src
)

# GLAD
include_directories(
        ${CMAKE_SOURCE_DIR}/libs/include
)
set_source_files_properties(${CMAKE_SOURCE_DIR}/libs/src/glad.c PROPERTIES LANGUAGE CXX )
add_library(glad ${CMAKE_SOURCE_DIR}/libs/src/glad.c)
target_link_libraries(sandbox glad)


if(MSVC)
    # on Windows && Visual Studio
    # Link GLFW library
    add_library(glfw STATIC IMPORTED)
    set_target_properties(glfw PROPERTIES
            IMPORTED_LOCATION "${CMAKE_SOURCE_DIR}/libs/lib/glfw3.lib"
            INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_SOURCE_DIR}/libs/include")
    target_link_libraries(sandbox glfw)

    include_directories(
            ${CMAKE_SOURCE_DIR}/libs/include
    )

    set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
else()
    # on UNIX/Linux
    find_package(glfw3 3.3 REQUIRED)
    target_link_libraries(sandbox glfw)
endif()

target_link_libraries(
        sandbox
        snow
)
