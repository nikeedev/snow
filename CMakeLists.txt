cmake_minimum_required(VERSION 3.26)

project(snow_engine)

set(CMAKE_CXX_STANDARD 17)

# Add the engine src code
add_subdirectory(snow)

# Add the sandbox app
add_subdirectory(sandbox)
