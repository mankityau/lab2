#include <vector>
#include <iostream>
#include <chrono>
#include "quicksort.h"

int main() {
    // create two copies of random data
    const int VECTOR_SIZE = 1000000;
    std::vector<int> v1(VECTOR_SIZE, 0);
    // fill with random integers
    for (int i=0; i<VECTOR_SIZE; ++i) {
        v1[i] = rand();
    }
    std::vector<int> v2 = v1;  // copy all contents

    // sort v1 using sequential algorithm
    auto quickSortTimeStart = std::chrono::high_resolution_clock::now();
    quicksort::quicksort(v1, 0, v1.size()-1);
    auto quickSortTimeEnd = std::chrono::high_resolution_clock::now();
    long quickSortDurationMs = std::chrono::duration_cast<std::chrono::milliseconds>(quickSortTimeEnd - quickSortTimeStart).count();
    std::cout << "QuickSort Duration (ms): " << quickSortDurationMs << std::endl;

    // sort v2 using parallel algorithm
    auto parallelQuickSortTimeStart = std::chrono::high_resolution_clock::now();
    quicksort::parallel_quicksort(v2, 0, v2.size()-1);
    auto parallelQuickSortTimeEnd = std::chrono::high_resolution_clock::now();
    long parallelQuickSortDurationMs = std::chrono::duration_cast<std::chrono::milliseconds>(parallelQuickSortTimeEnd - parallelQuickSortTimeStart).count();
    std::cout << "Parallel QuickSort Duration (ms): " << parallelQuickSortDurationMs << std::endl;

    return 0;
}
