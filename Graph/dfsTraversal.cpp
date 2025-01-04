#include <iostream>
#include <vector>
using namespace std;

void helper(int node, vector<int> adjList[], vector<bool> &visited, vector<int> &ans)
{
    visited[node] = true; // Mark the node as visited
    ans.push_back(node);  // Add the node to the result

    // Traverse all adjacent nodes of the current node
    for (int j = 0; j < adjList[node].size(); j++)
    {
        if (!visited[adjList[node][j]]) // If the node is not visited
        {
            helper(adjList[node][j], adjList, visited, ans); // Recursive DFS call
        }
    }
}

vector<int> dfsTraversal(int node, vector<int> adjList[], int vertices)
{
    vector<bool> visited(vertices, false); // Initialize visited vector with size 'vertices'
    vector<int> ans;
    helper(node, adjList, visited, ans); // Start DFS from the given node
    return ans;
}

int main()
{
    int vertices = 5;

    // Initialize an adjacency list
    vector<int> adjList[vertices];

    // Initialize edges (Undirected Graph)
    adjList[0].push_back(1);
    adjList[0].push_back(2);

    adjList[1].push_back(0);
    adjList[2].push_back(2); // Self-loop at node 2 (if intentional)
    adjList[1].push_back(3);

    adjList[2].push_back(0);
    adjList[2].push_back(1);
    adjList[2].push_back(4);

    adjList[3].push_back(1);
    adjList[3].push_back(4);

    adjList[4].push_back(2);
    adjList[4].push_back(3);

    // Perform DFS starting from node 0
    vector<int> result = dfsTraversal(0, adjList, vertices);

    // Print the result of DFS traversal
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }

    return 0;
}
