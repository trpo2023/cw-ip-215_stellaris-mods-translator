cmake_minimum_required(VERSION 3.0)
project(StellarisMT)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY bin)

add_executable(StellarisMT oop/main.cpp oop/mod.cpp oop/parser.cpp oop/localisator.cpp)