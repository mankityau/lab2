#include <iostream>
#include <thread>
#include <vector>
//#include "lib/cpen333/thread"


namespace quicksort {
    /**
     * @brief       Swap two element in the vector
     * @param data  The vector that will have its element swapped
     * @param a
     * @param b
     */
    static void swap(std::vector<int> &data, int a, int b) {
        int temp = data[a];
        data[a] = data[b];
        data[b] = temp;
    }

    /**
     * @brief       partitions elements low through high (inclusive), around a pivot and returns the pivot index
     * @param data  The entire vector that the function is going
     * @param low
     * @param high
     * @return  the pivot index that function used.
     */
    static int partition(std::vector<int> &data, int low, int high) {
        int pivotValue = data[high];
        int swapIndex = low;
        for (int i = low; i < high; i++) {
            if (data[i] < pivotValue) {
                swap(data, i, swapIndex);
                swapIndex++;
            }
        }

        swap(data, swapIndex, high);
        return swapIndex;
    }

    void quicksort(std::vector<int> &data, int low, int high) {
        if (low < high) {
            int pivotIndex = partition(data, low, high);
            quicksort(data, low, pivotIndex - 1);
            quicksort(data, pivotIndex + 1, high);
        }
    }

    void parallel_quicksort(std::vector<int> &data, int low, int high) {
        if (low < high) {
            int pivotIndex = partition(data, low, high);
            std::thread* threadLeft = new std::thread(quicksort::parallel_quicksort, std::ref(data),low, pivotIndex - 1);
            std::thread* threadRight = new std::thread(quicksort::parallel_quicksort, std::ref(data),pivotIndex + 1, high);
            threadLeft->join();
            threadRight->join();
        }
    }
}


