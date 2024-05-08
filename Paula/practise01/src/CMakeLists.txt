add_library(PiGenerator PiGenerator.cpp)
target_include_directories(PiGenerator PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(PiGenerator PUBLIC  ROOT::MathCore ROOT::RIO ROOT::Hist)
