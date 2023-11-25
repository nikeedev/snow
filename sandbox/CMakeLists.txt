add_executable(sandbox main.cpp)

include_directories(
        ../snow/src
        ../libs/include
)

target_link_libraries(sandbox snow)
