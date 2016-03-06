#include <cmath>
#include <iostream>
#include <random>
#include <string>
#include <vector>

#include <QByteArray>
#include <QAudioBuffer>

int main()
{
    std::random_device rand_dev;
    std::mt19937 rand_gen(rand_dev());
    std::normal_distribution<> dist(5.0,2.0);

    QByteArray qarray;

    for (int i=0; i<10; ++i)
    {
        std::cout << dist(rand_gen) << std::endl;
        char j = (char)(dist(rand_gen));
        qarray.append(j);
    }

    for (char k=0; k<qarray.size(); ++k)
    {
        std::cout << qarray[k] << std::endl;
    }

    return 0;
};

