cmake_minimum_required(VERSION 3.10)
project(MyProject C)

set(CMAKE_C_COMPILER "/usr/bin/gcc")  # Replace "/usr/bin/gcc" with your gcc path
set(CMAKE_C_STANDARD 99)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra")

file(GLOB_RECURSE SOURCES "functions/*.c" "utils/*.c")

add_library(MyLibrary ${SOURCES})

add_executable(main main.c )

target_link_libraries(main MyLibrary)

target_link_libraries(main gcc)