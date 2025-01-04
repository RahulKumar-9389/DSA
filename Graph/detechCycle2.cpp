#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool isCycle(int V, vector<int> adjList[])
{
    queue<pair<int, int>> q;
    vector<bool> visited(V, false);

    visited[0] = true;

    q.push(make_pair(0, -1));

    while (!q.empty())
    {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for (int j = 0; j < adjList[node].size(); j++)
        {
            if (adjList[node][j] == parent)
            {
                continue;
            }

            if (visited[adjList[node][j]])
            {
                return true;
            }

            visited[adjList[node][j]] = 1;

            q.push(make_pair(adjList[node][j], node));
        }
    }
    return false;
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
