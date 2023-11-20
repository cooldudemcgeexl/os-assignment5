#include "phil_graph.h"

PhilGraph::PhilGraph(int num_phils)
{
    b_graph = MutexGraph(num_phils, MutexVector(num_phils, std::mutex()));
}