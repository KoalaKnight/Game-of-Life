#ifndef RANDOM_H_INCLUDED
#define RANDOM_H_INCLUDED

#include <random>
#include <cstdint>
#include <ctime>

namespace Random
{
    void init();
    int64_t intInRange(int64_t low, int64_t high);
    float floatInRange(float low, float high);
}

#endif // RANDOM_H_INCLUDED
