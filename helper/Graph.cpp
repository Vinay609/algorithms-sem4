#include <map>
#include <vector>
using namespace std;

class Graph
{
public:
    map<int, vector<int>> graph;

    void add_edge(int a, int b)
    {
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<int> nodes()
    {
        vector<int> res;
        map<int, vector<int>>::iterator itr;
        // auto itr;
        for (itr = graph.begin(); itr != graph.end(); itr++)
            res.push_back(itr->first);

        return res;
    }

    vector<int> neighbors(int src)
    {
        if (graph.find(src) == graph.end())
            return vector<int>();
        return graph.at(src);
    }
};