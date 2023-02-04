#include "./graph_class.cpp"
#include <iostream>

using namespace std;

int main()
{
    Graph graph;

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

    graph.print();
}