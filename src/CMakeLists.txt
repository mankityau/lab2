project(src)

set(HEADERS quicksort.h)

set(SOURCES quicksort.cpp)

add_library(src ${HEADERS} ${SOURCES})

add_executable(quicksortMain quicksortMain.cpp)
target_link_libraries(quicksortMain Threads::Threads src)    # link with threads library