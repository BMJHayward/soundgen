#include <iostream> 
#include <random> 
#define BITRATE_HI 96000
#define BITRATE_LO 48000


int main()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0,1000);
    while (1)
    {
        char c = dis(gen);
        std::cout << c << std::endl;
    }

    return 0;
}

