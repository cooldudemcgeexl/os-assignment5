#pragma once

#include <iostream>
#include <chrono>
#include <ctime>
#include <random>
typedef std::chrono::high_resolution_clock Clock;
typedef std::chrono::milliseconds milliseconds;

milliseconds rand_ms(int min, int max);