add_executable(sandbox main.cpp
        Game.cpp
        Game.h
        MyScene.cpp
        MyScene.h
)

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

target_link_libraries(
        sandbox
        snow
)
