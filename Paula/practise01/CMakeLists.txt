cmake_minimum_required(VERSION 3.20)

project(MonteCarlo)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(src)
add_executable(main main.cpp)
target_link_libraries(main PUBLIC PiGenerator)
