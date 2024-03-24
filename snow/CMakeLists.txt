find_package(fmt CONFIG REQUIRED)
find_package(glad CONFIG REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)
find_package(Stb REQUIRED)

set(SNOW_SRC
        src/snow.hpp
        src/core/Application.cpp
        src/core/Shader.cpp
        src/core/Window.cpp
        src/mesh/Rectangle.cpp
        src/core/Camera.cpp
        src/core/Scene.h
        src/mesh/Triangle.h
        src/mesh/Triangle.cpp
)

add_library(snow STATIC
        ${SNOW_SRC}
)

target_include_directories(snow PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/src 
        ${CMAKE_BINARY_DIR}/vcpkg_installed/x64-windows/include
)

target_link_libraries(snow PRIVATE
        glfw
        glad::glad
        glm::glm
        fmt::fmt
)

