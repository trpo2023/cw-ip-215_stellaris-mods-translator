cmake_minimum_required(VERSION 3.0)
project(StellarisMT)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
file(GLOB SOURCE_FILES "oop/*.cpp")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY bin)

add_executable(StellarisMT ${SOURCE_FILES})