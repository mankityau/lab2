#include <iostream>
#include <thread>
#include <vector>

/**
 * @brief       Swap two element in the vector
 * @param data  The vector that will have its element swapped
 * @param a
 * @param b
 */
void swap(std::vector<int> &data, int a, int b) {
    int temp = data[a];
    data[a] = data[b];
    data[b] = temp;
}

// partitions elements low through high (inclusive)
// around a pivot and returns the pivot index
/**
 *
 * @param data  The entire vector that the function is going
 * @param low
 * @param high
 * @return  the pivot index that function used.
 */
int partition(std::vector<int> &data, int low, int high) {
    int pivotValue = data[high];
    int swapIndex = low;
    for (int i = low; i < high; i++) {
        if (data[i] < pivotValue) {
            swap(data, i, swapIndex);
            swapIndex ++;
        }
    }

    swap(data, swapIndex, high);
    return swapIndex;
}

// sorts elements low through high (inclusive) using a single thread
/**
 * @brief       The function will sort the specific range of the vector. Range = [lower bound, higher bound]
 * @param data  The vector that will be sorted
 * @param low   The lower bound
 * @param high  The higher bound
 */
void quicksort(std::vector<int> &data, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(data, low, high);
        quicksort(data, low, pivotIndex - 1);
        quicksort(data, pivotIndex + 1, high);
    }
}

// sorts elements low through high (inclusive) using multiple threads
void parallel_quicksort(std::vector<int> &data, int low, int high) {
    // your code here
}

//int main() {
//
//    // create two copies of random data
//    const int VECTOR_SIZE = 10;
//    std::vector<int> v1(VECTOR_SIZE, 0);
//    // fill with random integers
//    for (int i = 0; i < VECTOR_SIZE; ++i) {
//        v1[i] = rand();
//    }
////    std::vector<int> v2 = v1;  // copy all contents
//
//    // sort v1 using sequential algorithm
//    for (int i = 0; i < VECTOR_SIZE; ++i) {
//        std::cout << v1[i] << "    ";
//    }
//
//    std::cout << "\n";
//
//    quicksort(v1, 0, v1.size() - 1);
//    for (int i = 0; i < VECTOR_SIZE; ++i) {
//        std::cout << v1[i] << "    ";
//    }
//
//
//    // sort v2 using parallel algorithm
////    parallel_quicksort(v2, 0, v2.size() - 1);
//
//    return 0;
//}
