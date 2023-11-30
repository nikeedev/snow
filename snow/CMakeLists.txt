# GLAD
add_library(GLAD STATIC ../libs/src/glad.c)

include_directories(
        src
        ../libs/include
)

# Link GLFW library
add_library(GLFW_LIB STATIC IMPORTED)
set_target_properties(GLFW_LIB PROPERTIES IMPORTED_LOCATION "../libs/lib/glfw3.lib")


set(SNOW_SRC
        src/snow.hpp
        src/core/Application.cpp
        src/core/Shader.cpp
        src/core/Window.cpp
        src/objects/Rectangle.cpp
        src/core/Camera.cpp
        src/core/Scene.h
)

add_library(snow STATIC
        ${SNOW_SRC}
)

