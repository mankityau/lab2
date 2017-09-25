project(src)

set(HEADERS quicksort.h pi.h)

set(SOURCES quicksort.cpp pi.cpp)

add_library(src ${HEADERS} ${SOURCES})

add_executable(quicksortMain quicksortMain.cpp)
target_link_libraries(quicksortMain Threads::Threads src)    # link with threads library

add_executable(piMain piMain.cpp)
target_link_libraries(piMain src)