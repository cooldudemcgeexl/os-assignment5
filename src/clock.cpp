#include "clock.h"
milliseconds rand_ms(int min, int max)
{
    static std::mt19937 rnd(time(nullptr));
    return milliseconds(std::uniform_int_distribution<>(min, max)(rnd));
}