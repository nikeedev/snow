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
        src/math/Vector2.h
        src/math/Vector2.cpp
        src/core/Application.h
        src/core/Application.cpp
        src/core/Window.h
        src/core/Window.cpp
)

add_library(snow STATIC
        ${SNOW_SRC}
)

