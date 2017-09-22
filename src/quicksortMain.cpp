#include <vector>
#include <cstdlib>
#include <iostream>
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
    quicksort::quicksort(v1, 0, v1.size()-1);

    // sort v2 using parallel algorithm
//    parallel_quicksort(v2, 0, v2.size()-1);

    return 0;
}