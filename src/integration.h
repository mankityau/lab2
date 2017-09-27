#ifndef LAB2_INTEGRATION_H
#define LAB2_INTEGRATION_H


#include <functional>
#include <iostream>
#include <thread>
#include <vector>
#include <random>

namespace integration {
    struct Point {
    public:
        double x, y, z;
        Point(double x, double y, double z){
            this->x = x;
            this->y = y;
            this->z = z;
        }
    };

    template <typename Func, typename PtGenerator>
    static double integrate(Func func, PtGenerator ptGenerator, double volV, int nsample) {
        double seriesSum = 0;
        for (int i = 0; i < nsample; i++){
            Point point = ptGenerator();
            seriesSum += func(point);
        }
        return seriesSum / nsample * volV;
    };

    template <typename Func, typename PtGenerator>
    double integrateMultiThread(Func func, PtGenerator ptGenerator, double volV, int nsample){
        int nthreads = std::thread::hardware_concurrency();

        std::vector<double> threadEvaluation(nthreads, 0);

        std::vector<std::thread> threads;

        //setting up the threads
        int msamples = 0; // samples accounted for

        auto nsampleIntegrate = [func, ptGenerator, volV] (int nsample) {
            return integration::integrate(func, ptGenerator, volV, nsample);
        };

        auto threadProcess = [nsampleIntegrate] (std::vector<double> &threadEvaluation, int nsample, int threadIdx) {
            threadEvaluation[threadIdx] = nsampleIntegrate(nsample);
        };

        for (int i = 0; i < nthreads - 1; ++i) {
            threads.push_back(
                    std::thread(threadProcess, std::ref(threadEvaluation), nsample/nthreads, i));
            msamples += nsample / nthreads;
        }

        threads.push_back(std::thread(threadProcess, std::ref(threadEvaluation), nsample - msamples, nthreads - 1));

        for (int i = 0; i < nthreads; ++i) {
            threads[i].join();
        }

//        summing up the values from the thread;
        msamples = 0; // samples accounted for
        double threadsWeightedSum = 0;
        for (int i = 0; i < nthreads; ++i) {
            threadsWeightedSum += threadEvaluation[i] * nsample / nthreads;
            msamples += nsample / nthreads;
        }

        threadsWeightedSum += threadEvaluation[nthreads - 1] * (nsample - msamples);


        return threadsWeightedSum / nsample;


    };
};
#endif //LAB2_INTEGRATION_H
