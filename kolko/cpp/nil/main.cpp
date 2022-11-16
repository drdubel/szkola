#include <iostream>
#include <algorithm>
using namespace std;
#include <limits.h>
int il_odnog;

int minDistance(int dist[], bool sptSet[])
{
    int min = INT_MAX, min_index;
    for (int v = 0; v < il_odnog; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;
    return min_index;
}

void printSolution(int dist[])
{
    cout << "Vertex \t Distance from Source" << endl;
    for (int i = 0; i < il_odnog; i++)
        cout << i << " \t\t\t\t" << dist[i] << endl;
}

void dijkstra(int graph[il_odnog][il_odnog], int src)
{
    int dist[il_odnog];
    bool sptSet[il_odnog];
    for (int i = 0; i < il_odnog; i++)
        dist[i] = INT_MAX, sptSet[i] = false;
    dist[src] = 0;
    for (int count = 0; count < il_odnog - 1; count++)
    {
        int u = minDistance(dist, sptSet);
        sptSet[u] = true;
        for (int v = 0; v < il_odnog; v++)
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }
    printSolution(dist);
}

int main()
{
    cin >> il_odnog;
    int graph[il_odnog][il_odnog];
    fill(graph[0], graph[0] + il_odnog * il_odnog, 0);
    dijkstra(graph, 0);
    return 0;
}