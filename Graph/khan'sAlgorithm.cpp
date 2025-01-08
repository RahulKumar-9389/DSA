#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void kAlgo(vector<int> list[], int V)
{
    vector<int> inDegree(V, 0);

    // Count the In-Degree for each vertex
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < list[i].size(); j++)
        {
            inDegree[list[i][j]]++; // Increment the in-degree of destination node
        }
    }

    // Initialize a queue
    queue<int> q;

    // Add nodes with 0 in-degree to the queue
    for (int i = 0; i < V; i++)
    {
        if (inDegree[i] == 0)
        {
            q.push(i);
        }
    }

    // Process the queue for topological sort
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        cout << node << " "; // Output the node in topological order

        // Reduce the in-degree of the neighbors
        for (int i = 0; i < list[node].size(); i++)
        {
            inDegree[list[node][i]]--; // Reduce the in-degree of the neighbor

            // If in-degree of neighbor becomes 0, add it to the queue
            if (inDegree[list[node][i]] == 0)
            {
                q.push(list[node][i]);
            }
        }
    }
}

int main()
{
    // Adjust graph construction to ensure it's correct for topological sort
    vector<int> list[4]; // 4 nodes

    // Add edges to the graph
    list[0].push_back(1); // 0 -> 1
    list[0].push_back(2); // 0 -> 2
    list[3].push_back(0); // 3 -> 0

    // Perform topological sort
    kAlgo(list, 4);
    return 0;
}
