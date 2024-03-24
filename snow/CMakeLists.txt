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
        if (WIN32 AND CMAKE_HOST_SYSTEM_PROCESSOR == "AMD64") 
                ${CMAKE_BINARY_DIR}/vcpkg_installed/x64-windows/include
        endif (WIN32)
        if (UNIX)
                ${CMAKE_BINARY_DIR}/vcpkg_installed/x64-linux/include
        endif (UNIX)
        if (APPLE AND ${CMAKE_APPLE_SILICON_PROCESSOR} == "x86_64")
                ${CMAKE_BINARY_DIR}/vcpkg_installed/x64-osx/include
        endif (APPLE)
        if (APPLE AND ${CMAKE_APPLE_SILICON_PROCESSOR} == "arm64")
                ${CMAKE_BINARY_DIR}/vcpkg_installed/arm64-osx/include
        endif (APPLE)
)

target_link_libraries(snow PRIVATE
        glfw
        glad::glad
        glm::glm
        fmt::fmt
)

