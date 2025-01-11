#include <iostream>
using namespace std;
#include <vector>
#include <climits>

vector<int> bellmenFord(int V, int E, vector<vector<int>> &edges, int source)
{
    vector<int> dist(V, INT_MAX);
    dist[source] = 0;

    for (int i = 0; i < (V - 1); i++)
    {
        for (int j = 0; j < E; j++)
        {
            int u = edges[j][0];
            int v = edges[j][1];
            int weight = edges[j][2];

            if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
            {
                dist[v] = dist[u] + weight;
            }
        }
    }

    // check for negative weight cycle
    for (int i = 0; i < E; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int weight = edges[i][2];

        if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
        {
            dist[v] = dist[u] + weight;
        }
    }

    return dist;
}

int main()
{

    int V = 4, E = 4;

    vector<vector<int>> edges = {
        {0, 1, 5},
        {0, 2, 3},
        {1, 3, 2},
        {3, 2, -1}};

    int source = 0;

    vector<int> ans = bellmenFord(V, E, edges, source);
    for (int it : ans)
    {
        cout << it << " ";
    }

    return 0;
}