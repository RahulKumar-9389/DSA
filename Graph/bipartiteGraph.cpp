#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool isBipartite(vector<int> adj[], int n)
{
    vector<int> color(n, -1);
    queue<int> q;

    for (int i = 0; i < n; i++)
    {
        if (!color[i])
        {

            color[i] = 1;

            q.push(i);

            while (!q.empty())
            {
                int node = q.front();
                q.pop();

                for (int j = 0; j < adj[node].size(); j++)
                {
                    if (color[adj[node][j]] == -1)
                    {
                        color[adj[node][j]] = (color[node] + 1) % 2;
                    }
                    else if (color[adj[node][j]] == color[node])
                    {
                        return false;
                    }
                }
            }

            return true;
        }
    }
}

int main()
{

    vector<int> adj[4];
    adj[0].push_back(1);
    adj[0].push_back(2);

    adj[1].push_back(0);
    adj[1].push_back(3);

    adj[2].push_back(0);
    adj[2].push_back(3);

    adj[3].push_back(1);
    adj[3].push_back(2);

    if (isBipartite(adj, 4))
    {
        cout << "This is bipartite graph!";
    }
    else
    {
        cout << "This is not a bipartite graph!";
    }
    return 0;
}