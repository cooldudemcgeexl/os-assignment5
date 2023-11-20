#include "phil_graph.h"
#include "iostream"
PhilGraph::PhilGraph(int num_phils)
{
    for (auto &i : b_graph)
    {
        for (auto &j : i)
        {
            std::cout << j.try_lock() << " ";
        }
        std::cout << std::endl;
    }
};