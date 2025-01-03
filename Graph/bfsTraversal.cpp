#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(int start, vector<int> adjList[], int n)
{

    // Build a visited array
    vector<bool> visited(n, false);

    // Initialize a queue
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        cout << node << " ";

        // Visit all the adjacent nodes of the current node
        for (int neighbor : adjList[node])
        {
            if (!visited[neighbor])
            {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main()
{
    vector<int> adjList[6];
    adjList[0].push_back(1);
    adjList[0].push_back(2);
    adjList[1].push_back(3);
    adjList[2].push_back(3);
    adjList[3].push_back(4);
    adjList[4].push_back(5);

    cout << "BFS traversal of graph is: ";
    bfs(0, adjList, 6);
    return 0;
}