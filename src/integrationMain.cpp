#include <cmath>
#include <iostream>
#include <random>
#include <chrono>
#include "integration.h"

const static double UNIT_SPHERE_VOLUME = 0.5236;
const static int SAMPLE_SIZE = 10000000;

template<typename DensityFunc>
double xFunction(DensityFunc dFunc, integration::Point point){
    return dFunc(point) * point.x;
}

template<typename DensityFunc>
double yFunction(DensityFunc dFunc, integration::Point point){
    return dFunc(point) * point.y;
}

template<typename DensityFunc>
double zFunction(DensityFunc dFunc, integration::Point point){
    return dFunc(point) * point.z;
}

integration::Point unitCirclePtGenerator() {
    std::default_random_engine rnd = std::default_random_engine(std::chrono::system_clock::now().time_since_epoch().count());
    std::uniform_real_distribution<double> dist = std::uniform_real_distribution<double>(-1.0, 1.0);
    integration::Point point(dist(rnd), dist(rnd), dist(rnd));
    while (point.x * point.x + point.y * point.y + point.z * point.z >= 1){
        point = integration::Point(dist(rnd), dist(rnd), dist(rnd));
    }
    return point;
};

template<typename DensityFunc>
void displayUnitSphereData(std::string densityName, DensityFunc densityFunc){
    double mass = integration::integrateMultiThread(densityFunc, unitCirclePtGenerator, UNIT_SPHERE_VOLUME, SAMPLE_SIZE);

    auto xFunc = [densityFunc](integration::Point point){return xFunction(densityFunc, point); };
    auto yFunc = [densityFunc](integration::Point point){return yFunction(densityFunc, point); };
    auto zFunc = [densityFunc](integration::Point point){return zFunction(densityFunc, point); };

    double centerX = integration::integrateMultiThread(xFunc, unitCirclePtGenerator, UNIT_SPHERE_VOLUME, SAMPLE_SIZE) / mass;
    double centerY = integration::integrateMultiThread(yFunc, unitCirclePtGenerator, UNIT_SPHERE_VOLUME, SAMPLE_SIZE) / mass;
    double centerZ = integration::integrateMultiThread(zFunc, unitCirclePtGenerator, UNIT_SPHERE_VOLUME, SAMPLE_SIZE) / mass;

    std::cout << "For density: " << densityName << std::endl;
    std::cout << "CenterX: " << centerX << ", CenterY: " << centerY << ", CenterZ: " << centerZ << std::endl;

}

int main(){
    auto density1 = [] (integration::Point point) -> double {
        double norm2 = point.x * point.x + point.y * point.y + point.z * point.z;
        if (norm2 > 1) {
            return 0;
        }
        return std::exp(-norm2);
    };

    auto density2 = [] (integration::Point point) -> double {
        return std::abs(point.x + point.y + point.z);
    };

    auto density3 = [] (integration::Point point) -> double {
        return (point.x - 1) * (point.x - 1) + (point.y - 2) * (point.y - 2) + (point.z - 3) * (point.z - 3);
    };

    displayUnitSphereData("Density 1", density1);
    displayUnitSphereData("Density 2", density2);
    displayUnitSphereData("Density 3", density3);
    return 0;
}