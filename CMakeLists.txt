cmake_minimum_required(VERSION 3.5)
project(StellarisMT)

find_package(SFML REQUIRED system window graphics)
find_package(CURL REQUIRED)
find_package(SQLite3 REQUIRED)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../bin)
add_executable(StellarisMT src/interface.cpp src/mod.cpp src/parser.cpp src/localisator.cpp src/translator.cpp src/database.cpp)
add_executable(test test/test_catch.cpp src/mod.cpp src/parser.cpp src/localisator.cpp)

target_link_libraries(StellarisMT sfml-graphics sfml-window sfml-system curl sqlite3)
link_directories(test)
target_link_libraries(test catch_amalgamated)