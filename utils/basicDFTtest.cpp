#include <cmath>
#include <vector>
#include <complex>
#include <iostream>
#include "basicDFT.h"

int testDFT()
{
    vector<complex<double>> numbers;
    double frequency = 1;
    for (int i=0; i<16; i++)
        numbers.push_back(sin((double)i / 16*frequency*2*pi));
    vector<complex<double>> testing = DFT(numbers);
    for(unsigned i=0; i<testing.size(); i++)
        std::cout << testing[i] << std::endl;
}
