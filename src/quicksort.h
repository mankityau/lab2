#ifndef LAB2_QUICKSORT_H
#define LAB2_QUICKSORT_H

#include <vector>

namespace quicksort{
    /**
     * @brief       sorts elements low through high (inclusive) using a single thread
     * @param data  The vector that will be sorted
     * @param low   The lower bound
     * @param high  The higher bound
     */
    void quicksort(std::vector<int> &data, int low, int high);
}

#endif //LAB2_QUICKSORT_H
