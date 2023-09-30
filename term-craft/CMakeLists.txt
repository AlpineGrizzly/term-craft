cmake_minimum_required(VERSION 3.22.1)
project(termcraft VERSION 0.0 LANGUAGES CXX)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

add_executable(termcraft termcraft.cpp)
target_link_libraries(termcraft ${CURSES_LIBRARIES})