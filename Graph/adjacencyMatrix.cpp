#include <iostream>
using namespace std;

int main()
{
    int vertices;
    cout << "Enter the number of vertices: ";
    cin >> vertices;

    int edges;
    cout << "Enter the number of edges: ";
    cin >> edges;

    int u, v;
    // Adjacency Matrix
    bool arr[vertices][vertices] = {false}; // Initialize all elements to false

    // Taking input for edges
    for (int i = 0; i < edges; i++)
    {
        cout << "Enter edge " << i + 1 << " (u v): ";
        cin >> u >> v;
        arr[u][v] = 1;
        arr[v][u] = 1; // Since it's an undirected graph
    }

    // Printing the adjacency matrix
    cout << "Graph representation using Adjacency matrix: " << endl;
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
