#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool isPossible(vector<int> list[], int V)
{
    int count = 0;
    vector<int> indegree(V, 0);

    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < list[i].size(); j++)
        {
            indegree[list[i][j]]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < V; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        count++;

        for (int i = 0; i < list[node].size(); i++)
        {
            indegree[list[node][i]]--;

            if (indegree[list[node][i]] == 0)
            {
                q.push(list[node][i]);
            }
        }
    }

    return count == V;
}

int main()
{
    int N = 2;
    int P = 2;
    vector<pair<int, int>> prerequisites = {make_pair(1, 0), make_pair(0, 1)};

    vector<int>
        adj[N];

    for (int i = 0; i < P; i++)
    {
        adj[prerequisites[i].second].push_back(prerequisites[i].first);
    }

    if (isPossible(adj, 4))
    {
        cout << "Possible!" << endl;
    }
    else
    {
        cout << "Not possible!" << endl;
    }

    return 0;
}
