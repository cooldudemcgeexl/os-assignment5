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

bool PhilGraph::is_drink_free(int i, int j)
{
    std::cout << "Philosopher " << i << " trying drink " << j << std::endl;
    bool attempt = b_graph[i][j].try_lock();
    b_graph[i][j].unlock();
    return attempt;
}

std::mutex *PhilGraph::get_lock(int i, int j)
{
    return &b_graph[i][j];
}