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

if (WIN32)
        configure_file(shaders/shader.vert ${CMAKE_CURRENT_BINARY_DIR}/Debug/shaders/shader.vert COPYONLY)
        configure_file(shaders/shader.frag ${CMAKE_CURRENT_BINARY_DIR}/Debug/shaders/shader.frag COPYONLY)
else()
        configure_file(shaders/shader.vert ${CMAKE_CURRENT_BINARY_DIR}/shaders/shader.vert COPYONLY)
        configure_file(shaders/shader.frag ${CMAKE_CURRENT_BINARY_DIR}/shaders/shader.frag COPYONLY)
endif (WIN32)

include_directories(
        ../snow/src
)

target_link_libraries(
        sandbox
        snow
)
