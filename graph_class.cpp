#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Graph
{
public:
    map<int, vector<int>> graph;

    Graph() {}

    void add_edge(int a, int b)
    {
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<int> nodes()
    {
        vector<int> res;

        // map<int, vector<int>>::iterator itr = graph.begin();
        auto itr = graph.begin();
        while (itr != graph.end())
            res.push_back(itr++->first);

        return res;
    }

    // just for help
    void print()
    {
        for (int node : nodes())
        {
            vector<int> neis = graph.at(node);

            cout << node << ": ";
            for (int nei : neis)
                cout << nei << " ";
            cout << endl;
        }
    }
};