#include <cmath>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <random>
#include <string>
#include <vector>
#include <QByteArray>
#include <QAudioBuffer>
#include <QAudioFormat>


std::map<int, int> gen_white()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> d(5,2);

    std::map<int, int> hist;
    for(int n=0; n<10000; ++n)
    {
        ++hist[std::round(d(gen))];
    }

    return hist;
}


int makeSignal()
{
    std::random_device rand_dev;
    std::mt19937 rand_gen(rand_dev());
    std::normal_distribution<> dist(5.0,2.0);

    QByteArray qarray;

    for (int i=0; i<10; ++i)
    {
        std::cout << dist(rand_gen) << std::endl;
        char c = dist(rand_gen);
        qarray.append(c);
    }

    for (int j=0; j<qarray.size(); ++j)
    {
        std::cout << static_cast<unsigned>(qarray.at(j)) << std::endl;
    }

    QAudioFormat format;
    QAudioBuffer qaudbuffer(qarray, format);
    std::cout << qaudbuffer.constData<int>() << std::endl;

    return 0;
};

