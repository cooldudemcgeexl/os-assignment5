#pragma once
#include <mutex>
#include <vector>
#include <deque>
#include <array>
#include "defines.h"

typedef std::array<std::mutex, NUM_PHILS> MutexDeque;
typedef std::array<MutexDeque, NUM_PHILS> MutexGraph;

class PhilGraph
{
    MutexGraph b_graph;

public:
    PhilGraph(int num_phils);

    bool is_drink_free(int i, int j);
    std::mutex *get_lock(int i, int j);
};