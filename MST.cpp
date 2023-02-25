#include <iostream>
using namespace std;

#define V 9
#define INF 999

int minKey(int key[], bool visited[])
{
    int min = INF;
    int min_index;

    for (int v = 0; v < V; v++)
    {
        if (!visited[v] && key[v] < min)
        {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

void primMST(int graph[V][V], int src)
{
    int parent[V];
    int key[V];
    bool visited[V];

    for (int i = 0; i < V; i++)
    {
        parent[i] = -1;
        key[i] = INF;
        visited[i] = false;
    }

    key[src] = 0;

    for (int tmp = 0; tmp < V - 1; tmp++)
    {
        int u = minKey(key, visited);
        visited[u] = true;

        for (int v = 0; v < V; v++)
        {
            if (graph[u][v] && !visited[v] && graph[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    for (int i = 1; i < V; i++)
        printf("%c - %c\n", 'a' + i, 'a' + parent[i]);
}

int main()
{
    /*
    int graph[V][V] = {{0, 2, 0, 6, 0},
                       {2, 0, 3, 8, 5},
                       {0, 3, 0, 0, 7},
                       {6, 8, 0, 0, 9},
                       {0, 5, 7, 9, 0}};
    V = 5
    */

    int graph[V][V] = {
        //   a  b   c  d   e   f   g  h   i
        {0, 4, 0, 0, 0, 0, 0, 8, 0},   // a
        {4, 0, 8, 0, 0, 0, 0, 11, 0},  // b
        {0, 8, 0, 7, 0, 4, 0, 0, 2},   // c
        {0, 0, 7, 0, 9, 14, 0, 0, 0},  // d
        {0, 0, 0, 9, 0, 10, 0, 0, 0},  // e
        {0, 0, 4, 14, 10, 0, 2, 0, 0}, // f
        {0, 0, 0, 0, 0, 2, 0, 1, 6},   // g
        {8, 11, 0, 0, 0, 0, 1, 0, 7},  // h
        {0, 0, 2, 0, 0, 0, 6, 7, 0},   // i
    };

    primMST(graph, 0);
}
