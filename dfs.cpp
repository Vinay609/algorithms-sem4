#include <iostream>
#include <map>
#include <vector>
using namespace std;

map<int, vector<int>> build_graph(vector<vector<int>> edges)
{
    map<int, vector<int>> graph;

    for (int i = 0; i < edges.size(); i++)
    {
        int a = edges[i][0];
        int b = edges[i][1];

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    return graph;
}

int main()
{
    cout << "Enter number of edges: ";
    int n;
    cin >> n;

    vector<vector<int>> edges;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        edges.push_back(vector<int>());
        edges[i].push_back(a);
        edges[i].push_back(b);
    }

    map<int, vector<int>> graph = build_graph(edges);

    for (map<int, vector<int>>::iterator data = graph.begin(); data != graph.end(); data++)
    {
        cout << data->first << " : ";
        for (int j = 0; j < data->second.size(); j++)
            cout << data->second[j] << " ";
        cout << endl;
    }
}