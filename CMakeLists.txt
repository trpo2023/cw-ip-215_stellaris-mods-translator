cmake_minimum_required(VERSION 3.5)
project(StellarisMT)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../bin)
add_executable(StellarisMT src/interface.cpp src/mod.cpp src/parser.cpp src/localisator.cpp)

target_link_libraries(StellarisMT sfml-graphics sfml-window sfml-system)