#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

vector<int> dijkstr(vector<vector<pair<int, int>>> &adj, int src, int V)
{
    // Initialize a priority queue
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    vector<int> dist(V, INT_MAX);

    dist[src] = 0;
    pq.push(make_pair(0, src));

    while (!pq.empty())
    {

        int dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for (int i = 0; i < adj[node].size(); i++)
        {
            int edgeWeight = adj[node][i].second;
            int adjNode = adj[node][i].first;

            if (dis + edgeWeight < dist[adjNode])
            {
                dist[adjNode] = dis + edgeWeight;
                pq.push(make_pair(dist[adjNode], adjNode));
            }
        }
    }

    return dist;
}

int main()
{

    vector<vector<pair<int, int>>> adj = {
        {{1, 1}, {2, 6}},
        {{2, 3}, {0, 1}},
        {{1, 3}, {0, 6}}};

    int V = 3;
    int src = 2;

    vector<int> ans = dijkstr(adj, src, V);

    for (int it : ans)
    {
        cout << it << " ";
    }

    return 0;
}