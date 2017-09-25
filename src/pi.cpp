#include <thread>
#include <iostream>
#include <random>

namespace pi {
    /**
     * return if the x and y coordinate is within the unit circle.
     * @param x the x coordinate
     * @param y the y coordinate
     * @return True, if x and y is within the unit circle.
     */
    static bool isInUnitCicle(double x, double y) {
        return x * x + y * y <= 1;
    }

    /**
     * generates a random sample and sets hits[idx] to true if within the unit circle
     * @param hits the hits vector that will be modified.
     * @param idx the index that that will be modified
     */
    static void pi_sampler(std::vector<bool> &hits, int idx) {
        static std::default_random_engine rnd(std::chrono::system_clock::now().time_since_epoch().count());
        static std::uniform_real_distribution<double> dist(-1.0, 1.0);

        hits[idx] = isInUnitCicle(dist(rnd), dist(rnd));
    }

    /**
     * count number of hits using nsamples, populates hits[threadIdx]
     * @param hits the hits vector that will be modified.
     * @param threadIdx the index that that will be modified
     * @param nsamples the number of samples that will be generate.
     */
    static void pi_hits(std::vector<int> &hits, int threadIdx, int nsamples) {
        static std::default_random_engine rnd(std::chrono::system_clock::now().time_since_epoch().count());
        static std::uniform_real_distribution<double> dist(-1.0, 1.0);

        int hitCount = 0;
        for (int i = 0; i < nsamples; i++) {
            if (isInUnitCicle(dist(rnd), dist(rnd))) {
                hitCount++;
            }
        }
        hits[threadIdx] = hitCount;
    }

    double estimate_pi(int nsamples) {
        int hits = 0;
        std::default_random_engine rnd(std::chrono::system_clock::now().time_since_epoch().count());
        std::uniform_real_distribution<double> dist(-1.0, 1.0);
        for (int i = 0; i < nsamples; i++) {
            if (isInUnitCicle(dist(rnd), dist(rnd))) {
                hits++;
            }
        }

        return 4.0 * hits / nsamples;
    }

    double estimate_pi_multithread_naive(int nsamples) {
        // stores whether each sample falls within circle
        std::vector<bool> hits(nsamples, false);

        // create and store all threads
        std::vector<std::thread> threads;
        for (int i = 0; i < nsamples; ++i) {
            threads.push_back(std::thread(pi_sampler, std::ref(hits), i));
        }

        // wait for all threads to complete
        for (int i = 0; i < nsamples; ++i) {
            threads[i].join();
        }

        // estimate our value of PI
        double pi = 0;
        for (int i = 0; i < nsamples; ++i) {
            if (hits[i]) {
                pi = pi + 1;
            }
        }
        pi = pi / nsamples * 4;

        return pi;
    }

    double estimate_pi_multithread(int nsamples) {

        // number of available cores
        int nthreads = std::thread::hardware_concurrency();

        // hit counts
        std::vector<int> hits(nthreads, 0);

        // create and store threads
        std::vector<std::thread> threads;
        int msamples = 0; // samples accounted for
        for (int i = 0; i < nthreads - 1; ++i) {
            threads.push_back(
                    std::thread(pi_hits, std::ref(hits), i, nsamples / nthreads));
            msamples += nsamples / nthreads;
        }
        // remaining samples
        threads.push_back(
                std::thread(pi_hits, std::ref(hits), nthreads - 1, nsamples - msamples));

        // wait for threads to finish
        for (int i = 0; i < nthreads; ++i) {
            threads[i].join();
        }

        // estimate pi
        double pi = 0;
        for (int i = 0; i < nthreads; ++i) {
            pi += hits[i];
        }
        pi = pi / nsamples * 4;

        return pi;
    }
}

//
//
//
//int main() {
//
//    double pi = estimate_pi(1000);
//    std::cout << "My estimate of PI is: " << pi << std::endl;
//
//    return 0;
//}