#include <iostream>
#include <set>
#include <deque>
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

void dfs(Graph graph, int source)
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
        for (int nei : graph.neighbors(node))
            st.push_back(nei);
    }
}

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

    // print dfs for each node
    cout << endl;
    for (int node : graph.nodes())
    {
        cout << "Node " << node << ": ";
        dfs(graph, node);
        cout << endl;
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