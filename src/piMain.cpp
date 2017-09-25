#include <iostream>
#include "pi.h"

int main(){
    double pi = pi::estimate_pi(1000);
    std::cout << "My estimate of PI is: " << pi << std::endl;
    return 0;
}