#include <mutex>
#include <vector>

typedef std::vector<std::mutex> MutexVector;
typedef std::vector<MutexVector> MutexGraph;

class PhilGraph
{
    MutexGraph b_graph;

public:
    PhilGraph(int num_phils);
};