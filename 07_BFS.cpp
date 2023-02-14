#include "./helper/Graph.cpp"
#include <iostream>
#include <deque>
#include <set>
using namespace std;

void bfs(Graph graph, int source)
{
    deque<int> q;
    set<int> seen;

    q.push_back(source);
    while (!q.empty())
    {
        int node = q.front();
        q.pop_front();

        if (seen.find(node) != seen.end())
            continue;
        seen.insert(node);

        cout << node << " ";
        for (int nei : graph.neighbors(node))
            q.push_back(nei);
    }
}

int main()
{
    Graph graph;

    // input edges
    cout << "Enter number of edges: ";
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter edge: ";
        int a, b;
        cin >> a >> b;
        graph.add_edge(a, b);
    }

    // print bfs for each node
    cout << endl;
    for (int node : graph.nodes())
    {
        cout << "Node " << node << ": ";
        bfs(graph, node);
        cout << endl;
    }
}