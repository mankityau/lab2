#ifndef LAB2_PI_H
#define LAB2_PI_H

namespace pi {
    /**
     * estimate the value of pi using n-number of samples.
     * @param nsamples the number of samples
     * @return the esimated value of pi
     */
    double estimate_pi(int nsamples);

    /**
     * estimate the value of pi using n-number of samples. Naively uses multithreading to try to speed up computations
     * @param nsamples the number of samples
     * @return the esimated value of pi
     */
    double estimate_pi_multithread_naive(int nsamples);

    /**
     * estimate the value of pi using n-number of samples. Divides work among threads intelligently
     * @param nsamples the number of samples
     * @return the esimated value of pi
     */
    double estimate_pi_multithread(int nsamples);
}
#endif //LAB2_PI_H
