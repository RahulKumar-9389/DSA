#include <iostream>
#include <vector>
using namespace std;

bool dfs(int node, vector<int> graph[], vector<bool> &visited, vector<bool> &inRecursion)
{
    visited[node] = true;
    inRecursion[node] = true;

    for (int i = 0; i < graph[node].size(); i++)
    {
        if (!visited[graph[node][i]])
        {
            if (dfs(graph[node][i], graph, visited, inRecursion))
            {
                return true;
            }
        }
        else if (inRecursion[graph[node][i]])
        {
            return true;
        }
    }

    inRecursion[node] = false;
    return false;
}

bool isCycle(int V, vector<int> graph[])
{
    vector<bool> visited(V, false);
    vector<bool> inRecursion(V, false);

    for (int i = 0; i < V; i++)
    {
        if (!visited[i] && dfs(i, graph, visited, inRecursion))
        {
            return true;
        }
    }

    return false;
}

int main()
{

    vector<int> graph[3];
    graph[0].push_back(1);
    graph[1].push_back(2);
    // graph[2].push_back(0);

    if (isCycle(3, graph))
    {
        cout << "Cycle present!";
    }
    else
    {
        cout << "No is cycle present!";
    }
    return 0;
}