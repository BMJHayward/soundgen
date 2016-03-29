#include <complex>
#include <iostream>
#include <vector>

using namespace std;

const double PI = 3.141592;


vector<complex<double>> DFT(vector<complex<double>>& theData)
{
    const int S = theData.size();
    vector<complex<double>> out(S, 0);
    for(unsigned i=0; (i < S); i++)
    {
        out[i] = complex<double>(0.0, 0.0);
        for(unsigned j=0; (j < S); j++)
        {
            out[i] += theData[j]*polar<double>(1.0, -2*PI*i*j/S);
        }
    }

    return out;
}

