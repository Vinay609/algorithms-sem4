#include <iostream>
#include <deque>
#include <vector>
using namespace std;

class Graph
{
public:
    int size;
    vector<vector<int>> graph;

    Graph(int n)
    {
        size = n;
        for (int i = 0; i < n; i++)
            graph.push_back(vector<int>());
    }

    void add_edge(int a, int b)
    {
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<int> nodes()
    {
        vector<int> res;
        for (int i = 0; i < size; i++)
            res.push_back(i);
        return res;
    }

    vector<int> neighbors(int src)
    {
        if (src < 0 || src >= size)
            return vector<int>();
        return graph[src];
    }

    void DFS(int source)
    {
        deque<int> st;

        bool visited[size];
        for (int i = 0; i < size; i++)
            visited[i] = 0;

        st.push_back(source);
        while (!st.empty())
        {
            int node = st.back();
            st.pop_back();

            if (visited[node])
                continue;
            visited[node] = 1;

            cout << node << " ";
            for (int nei : neighbors(node))
                st.push_back(nei);
        }
    }

    void BFS(int source)
    {
        deque<int> q;
        bool visited[size];
        for (int i = 0; i < size; i++)
            visited[i] = 0;

        q.push_back(source);
        while (!q.empty())
        {
            int node = q.front();
            q.pop_front();

            if (visited[node])
                continue;
            visited[node] = 1;

            cout << node << " ";
            for (int nei : neighbors(node))
                q.push_back(nei);
        }
    }
};

int main()
{
    /*
            0 --- 1
            |     |
            3 --- 2
             \   /
              \ /
               4
    */

    int n = 5;
    Graph graph = Graph(n);

    vector<vector<int>> edges;
    edges.push_back({0, 1});
    edges.push_back({1, 2});
    edges.push_back({2, 3});
    edges.push_back({3, 0});
    edges.push_back({3, 4});
    edges.push_back({2, 4});

    for (int i = 0; i < edges.size(); i++)
        graph.add_edge(edges[i][0], edges[i][1]);

    // // input number of nodes
    // cout << "Enter number of nodes: ";
    // int num_nodes;
    // cin >> num_nodes;

    // // initialization
    // Graph graph(num_nodes);

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