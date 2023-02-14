#include "./helper/Graph.cpp"
#include <iostream>
#include <set>
#include <deque>
using namespace std;

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
}