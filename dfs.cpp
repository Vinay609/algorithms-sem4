#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Graph
{
public:
    map<int, vector<int>> graph;

    Graph(vector<vector<int>> edges)
    {
        for (int i = 0; i < edges.size(); i++)
        {
            int a = edges[i][0];
            int b = edges[i][1];

            graph[a].push_back(b);
            graph[b].push_back(a);
        }
    }

    void print()
    {
        for (auto data = graph.begin(); data != graph.end(); data++)
        {
            int src = data->first;
            vector<int> nei = data->second;

            cout << src << ": ";
            for (int j = 0; j < nei.size(); j++)
                cout << nei[j] << " ";
            cout << endl;
        }
    }
};

vector<vector<int>> input_edges()
{
    cout << "Enter number of edges: ";
    int n;
    cin >> n;
    vector<vector<int>> edges;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter edge: ";
        int a, b;
        cin >> a >> b;
        edges.push_back(vector<int>());
        edges[i].push_back(a);
        edges[i].push_back(b);
    }

    return edges;
}

int main()
{
    vector<vector<int>> edges = input_edges();
    
    Graph graph = Graph(edges);
    graph.print();
    
}