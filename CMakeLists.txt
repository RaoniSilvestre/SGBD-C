cmake_minimum_required(VERSION 3.10)
project(MyProject)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_BUILD_TYPE Debug)

file(GLOB_RECURSE SOURCES "functions/*.c" "utils/*.c")

add_library(MyLibrary ${SOURCES})

add_executable(main main.c )

target_link_libraries(main MyLibrary)

target_link_libraries(main gcc)