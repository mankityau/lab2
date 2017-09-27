cmake_minimum_required(VERSION 3.7)
project(lab2)

set(CMAKE_CXX_STANDARD 11)
find_package( Threads REQUIRED )  # Multithreading package required

include_directories(src)

add_subdirectory(src)
add_subdirectory(test)
