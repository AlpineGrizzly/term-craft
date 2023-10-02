cmake_minimum_required(VERSION 3.22.1)
project(termcraft VERSION 0.0 LANGUAGES CXX)

# Get source files
set(SOURCES termcraft.cpp player.cpp player.h map.cpp map.h structure.cpp structure.h)

add_executable(termcraft ${SOURCES})
target_link_libraries(termcraft)
