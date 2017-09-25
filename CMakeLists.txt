cmake_minimum_required(VERSION 3.7)
project(lab2)

set(CMAKE_CXX_STANDARD 11)
find_package( Threads REQUIRED )  # Multithreading package required

add_executable(integration src/integration.cpp)
target_link_libraries(integration Threads::Threads)

include_directories(src)

add_subdirectory(src)
add_subdirectory(test)
