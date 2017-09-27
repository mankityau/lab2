#include <gtest/gtest.h>
#include <random>
#include <chrono>
#include "integration.h"

const static int N = 1000000;
const static double ACCETABLE_DISCREPENCY = 0.1;

TEST(integrationFunctionalTest, fcnEqual1_xOver0To1)    {
    double expectedAns = 1;

    auto func = [](integration::Point point){
        return 1;
    };

    auto ptGenerator = [](){
        std::default_random_engine rnd = std::default_random_engine(std::chrono::system_clock::now().time_since_epoch().count());
        std::uniform_real_distribution<double> dist = std::uniform_real_distribution<double>(0, 1.0);
        integration::Point point(dist(rnd), 0, 0);
        return point;
    };

    double volV = 1;

    double actualAns = integration::integrateMultiThread(func, ptGenerator, volV, N);
    ASSERT_NEAR(actualAns, expectedAns, ACCETABLE_DISCREPENCY);
};

/**
 * http://www.wolframalpha.com/input/?i=integrate+x%5E2+%2B+y%5E2+dx+dy,+x%3D0+to+1,+y%3D0+to+1
 */
TEST(integrationFunctionalTest, fcnEqualXSquarePlusYSquare_xOver0To1_yOver0To1){
    double expectedAns = 0.6666666666667;

    auto func = [](integration::Point point){
        return point.x * point.x + point.y * point.y;
    };

    auto ptGenerator = [](){
        std::default_random_engine rnd = std::default_random_engine(std::chrono::system_clock::now().time_since_epoch().count());
        std::uniform_real_distribution<double> dist = std::uniform_real_distribution<double>(0, 1.0);
        integration::Point point(dist(rnd), dist(rnd), 0);
        return point;
    };

    double volV = 1;

    double actualAns = integration::integrateMultiThread(func, ptGenerator, volV, N);
    ASSERT_NEAR(actualAns, expectedAns, ACCETABLE_DISCREPENCY);
};

/**
 * http://www.wolframalpha.com/input/?i=integrate+x%5E2+%2B+y%5E2+%2B+z%5E2+dx+dy+dz,+x%3D0+to+1,+y%3D0+to+1,+z%3D0+to+1
 */
TEST(integrationFunctionalTest, fcnEqualXSquarePlusYSquarePlusZSquare_xOver0To1_yOver0To1_zOver0To1){
    double expectedAns = 1;

    auto func = [](integration::Point point){
        return point.x * point.x + point.y * point.y + point.z * point.z;
    };

    auto ptGenerator = [](){
        std::default_random_engine rnd = std::default_random_engine(std::chrono::system_clock::now().time_since_epoch().count());
        std::uniform_real_distribution<double> dist = std::uniform_real_distribution<double>(0, 1.0);
        integration::Point point(dist(rnd), dist(rnd), dist(rnd));
        return point;
    };

    double volV = 1;

    double actualAns = integration::integrateMultiThread(func, ptGenerator, volV, N);
    ASSERT_NEAR(actualAns, expectedAns, ACCETABLE_DISCREPENCY);
};


