#include <cassert>
#include <random>
#include <typeinfo>
#include <vector>

std::vector<double> white(int length)
{
    assert(length);
    assert(typeid(length).name() == typeid(1).name());
    std::vector whitelist(length);
    std::random_device randev;
    std::mt19937 genertr(randev());
    std::uniform_real_distribution<> unf_dist(0, length);
    for(auto j : whitelist)
    {
        whitelist.push_back(unf_dist(gen));
    }
    return whitelist
}
