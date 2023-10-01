cmake_minimum_required(VERSION 3.22.1)
project(termcraft VERSION 0.0 LANGUAGES CXX)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

# Get source files
set(SOURCES termcraft.cpp player.cpp player.h map.cpp map.h)

add_executable(termcraft ${SOURCES})
target_link_libraries(termcraft ${CURSES_LIBRARIES})