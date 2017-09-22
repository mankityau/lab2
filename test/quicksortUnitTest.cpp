#include <gtest/gtest.h>
#include "quicksort.h"

TEST(quicksortUnitTest, quicksort_emptyVector){
    std::vector<int> unsortedVector = {};
    std::vector<int> expectedVector = {};
    quicksort::quicksort(unsortedVector, 0, 0);
    EXPECT_EQ(unsortedVector, expectedVector);
}

TEST(quicksortUnitTest, quicksort_sizeOneVector) {
    std::vector<int> unsortedVector = {0};
    std::vector<int> expectedVector = {0};
    quicksort::quicksort(unsortedVector, 0, 0);
    EXPECT_EQ(unsortedVector, expectedVector);
}

TEST(quicksortUnitTest, quicksort_unsortedVectorOddLength) {
    std::vector<int> unsortedVector = {4, 2, 3, 1, 0};
    std::vector<int> expectedVector = {0, 1, 2, 3, 4};
    quicksort::quicksort(unsortedVector, 0, 4);
    EXPECT_EQ(unsortedVector, expectedVector);
}

TEST(quicksortUnitTest, quicksort_unsortedVectorEvenLength) {
    std::vector<int> unsortedVector = {4, 2, 5, 3, 1, 0};
    std::vector<int> expectedVector = {0, 1, 2, 3, 4, 5};
    quicksort::quicksort(unsortedVector, 0, 5);
    EXPECT_EQ(unsortedVector, expectedVector);
}

TEST(quicksortUnitTest, quicksort_sortedVector) {
    std::vector<int> unsortedVector = {0, 1, 2, 3, 4, 5};
    std::vector<int> expectedVector = {0, 1, 2, 3, 4, 5};
    quicksort::quicksort(unsortedVector, 0, 5);
    EXPECT_EQ(unsortedVector, expectedVector);
}

TEST(quicksortUnitTest, quicksort_flippedVector) {
    std::vector<int> unsortedVector = {5, 4, 3, 2, 1, 0};
    std::vector<int> expectedVector = {0, 1, 2, 3, 4, 5};
    quicksort::quicksort(unsortedVector, 0, 5);
    EXPECT_EQ(unsortedVector, expectedVector);
}

TEST(quicksortUnitTest, quicksort_duplicatedElementVector) {
    std::vector<int> unsortedVector = {5, 4, 2, 2, 4, 0};
    std::vector<int> expectedVector = {0, 2, 2, 4, 4, 5};
    quicksort::quicksort(unsortedVector, 0, 5);
    EXPECT_EQ(unsortedVector, expectedVector);
}

TEST(quicksortUnitTest, quicksort_sameElementVector) {
    std::vector<int> unsortedVector = {5, 5, 5, 5, 5, 5};
    std::vector<int> expectedVector = {5, 5, 5, 5, 5, 5};
    quicksort::quicksort(unsortedVector, 0, 5);
    EXPECT_EQ(unsortedVector, expectedVector);
}

