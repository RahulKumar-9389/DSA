#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool isValid(int i, int j, int row, int col)
{
    return (i >= 0 && i < row && j >= 0 && j < col);
}

int numIslands(string grid[4][5])
{

    int r = 4;
    int c = 5;
    int count = 0;

    queue<pair<int, int>> q;

    for (int i = 0; i < r; i++)
    {

        for (int j = 0; j < c; j++)
        {
            if (grid[i][j] == "1")
            {
                count++;
                q.push(make_pair(i, j));
                grid[i][j] = "0";

                while (!q.empty())
                {
                    int m = q.front().first;
                    int n = q.front().second;
                    q.pop();

                    int row[4] = {-1, 1, 0, 0};
                    int col[4] = {0, 0, -1, 1};

                    for (int k = 0; k < 4; k++)
                    {
                        if (isValid(m + row[k], n + col[k], r, c) && grid[m + row[k]][n + col[k]] == "1")
                        {
                            grid[m + row[k]][n + col[k]] = "0";
                            q.push(make_pair(m + row[k], n + col[k]));
                        }
                    }
                }
            }
        }
    }
    return count;
}

int main()
{

    string grid[4][5] = {
        {"1", "1", "1", "1", "0"},
        {"1", "1", "0", "1", "0"},
        {"1", "1", "0", "0", "0"},
        {"0", "0", "0", "0", "0"}};

    cout << "There are " << numIslands(grid) << " Islands.";

    return 0;
}