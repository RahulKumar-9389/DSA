#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void kAlgo(vector<int> list[], int V)
{

    vector<int> inDegree(V, 0);

    // count the In-Degree
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < list[i].size(); j++)
        {
            inDegree[list[i][j]++];
        }
    }

    // Initialize a queue
    queue<int> q;

    for (int i = 0; i < V; i++)
    {
        if (!inDegree[i])
        {
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int i = 0; i < list[i].size(); i++)
        {
            inDegree[list[node][i]]--;

            if (inDegree[list[node][i]] == 0)
            {
                q.push(list[node][i]);
            }
        }
    }
}

int main()
{

    vector<int> list[4];
    list[0].push_back(1);
    list[0].push_back(2);
    list[3].push_back(0);
    kAlgo(list, 4);
    return 0;
}