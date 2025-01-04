#include <iostream>
#include <vector>
using namespace std;

bool detectCycle(int node, int parent, vector<int> adjList[], vector<bool> &visited)
{
    visited[node] = true;

    // Explore the neighbors of the current node
    for (int j = 0; j < adjList[node].size(); j++)
    {
        int neighbor = adjList[node][j];

        // Skip the parent node to avoid trivial cycle (back edge to the parent)
        if (neighbor == parent)
        {
            continue;
        }

        // If the neighbor is visited, there is a cycle
        if (visited[neighbor])
        {
            return true;
        }

        // Recur for the neighbor node
        if (detectCycle(neighbor, node, adjList, visited))
        {
            return true;
        }
    }

    return false;
}

bool isCycle(int V, vector<int> adjList[])
{
    vector<bool> visited(V, false);

    // Loop through all nodes in the graph
    for (int i = 0; i < V; i++)
    {
        // If a node is unvisited, start a DFS from it
        if (!visited[i])
        {
            if (detectCycle(i, -1, adjList, visited))
            {
                return true;
            }
        }
    }

    return false; // If no cycle is found
}

int main()
{
    // Adjacency list for the graph
    vector<int> adjList[3];

    // Create edges
    adjList[0].push_back(1);
    adjList[0].push_back(2);

    adjList[2].push_back(0);
    adjList[2].push_back(1);

    if (isCycle(3, adjList))
    {
        cout << "Graph has a cycle!" << endl;
    }
    else
    {
        cout << "No cycle is present in given graph!" << endl;
    }
    return 0;
}
