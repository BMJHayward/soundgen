#include <cmath>
#include <iostream>
#include <random>
#include <string>
#include <vector>

#include <QByteArray>
#include <QAudioBuffer>
#include <QAudioFormat>

int main()
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

