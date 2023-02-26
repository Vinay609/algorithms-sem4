#include <iostream>
#include <deque>
#include <vector>
#include <map>
#include <set>
using namespace std;

class GraphGeneric
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

    void DFS(int source)
    {
        deque<int> st;
        set<int> seen;

        st.push_back(source);
        while (!st.empty())
        {
            int node = st.back();
            st.pop_back();

            if (seen.find(node) != seen.end())
                continue;
            seen.insert(node);

            cout << node << " ";
            for (int nei : neighbors(node))
                st.push_back(nei);
        }
    }

    void BFS(int source)
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
            for (int nei : neighbors(node))
                q.push_back(nei);
        }
    }
};

int main()
{
    /*
            10 --- 3
            |      |
            38 --- 2
             \   /
              \ /
               7
    */

    GraphGeneric graph;

    vector<vector<int>> edges;
    edges.push_back({10, 3});
    edges.push_back({3, 2});
    edges.push_back({2, 38});
    edges.push_back({38, 10});
    edges.push_back({2, 7});
    edges.push_back({38, 7});

    for (int i = 0; i < edges.size(); i++)
        graph.add_edge(edges[i][0], edges[i][1]);

    // // initialization
    // GraphGeneric graph;

    // // input of edges
    // cout << "Enter number of edges: ";
    // int n;
    // cin >> n;
    // for (int i = 0; i < n; i++)
    // {
    //     cout << "Enter edge: ";
    //     int a, b;
    //     cin >> a >> b;
    //     graph.add_edge(a, b);
    // }

    // print dfs for each node
    cout << endl;
    for (int node : graph.nodes())
    {
        cout << "Node " << node << ": ";
        graph.DFS(node);
        cout << endl;
    }

    // print bfs for each node
    cout << endl;
    for (int node : graph.nodes())
    {
        cout << "Node " << node << ": ";
        graph.BFS(node);
        cout << endl;
    }
}