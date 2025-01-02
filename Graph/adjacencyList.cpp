#include <iostream>
#include <vector>
using namespace std;

int main()
{

    int vertices;
    cout << "Enter the vertices: ";
    cin >> vertices;

    int edges;
    cout << "Enter the number of edges: ";
    cin >> edges;

    // Initialize a list
    vector<int> adjList[vertices];

    int u, v;

    for (int i = 0; i < edges; i++)
    {
        cout << "Enter the edges " << i << "(u, v)";
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    // print
    for (int i = 0; i < vertices; i++)
    {
        cout << i << "->";
        for (int j = 0; j < adjList[i].size(); j++)
        {
            cout << adjList[i][j];
        }
        cout << endl;
    }
    return 0;
}