#include <iostream>
#include "pi.h"

int main(){
    std::cout << "My estimate of PI using estimate_pi is: " << pi::estimate_pi(1000) << std::endl;
    std::cout << "My estimate of PI using estimate_pi_multithread_naive is: " << pi::estimate_pi_multithread_naive(1000) << std::endl;
    return 0;
}