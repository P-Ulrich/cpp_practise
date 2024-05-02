cmake_minimum_required(VERSION 3.20)

project(MonteCarlo)

find_package(ROOT REQUIRED COMPONENTS Hist RIO MathCore)
#  find_package(ROOT 6.16 CONFIG REQUIRED)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(src)
add_executable(main main.cpp)
target_link_libraries(main PUBLIC PiGenerator ROOT::MathCore ROOT::RIO ROOT::Hist)

