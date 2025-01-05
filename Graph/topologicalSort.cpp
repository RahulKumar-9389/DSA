#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void dfs(int node, vector<int> adj[], vector<bool> &visited, stack<int> &st)
{
    visited[node] = 1;

    for (int i = 0; i < adj[node].size(); i++)
    {
        if (!visited[adj[node][i]])
        {
            dfs(adj[node][i], adj, visited, st);
        }
    }
    st.push(node);
}

void topologicalSort(vector<int> adj[], int V)
{

    // Visited array
    vector<bool> visited(V, 0);
    stack<int> st;
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            dfs(i, adj, visited, st);
        }
    }

    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
}

int main()
{

    vector<int> adj[4];
    adj[1].push_back(0);
    adj[2].push_back(0);
    adj[3].push_back(0);

    topologicalSort(adj, 4);
    return 0;
}