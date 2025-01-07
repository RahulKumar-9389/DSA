#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool isValid(int i, int j, int row, int col)
{
    return (i >= 0 && i < row && j >= 0 && j < col);
}

void solve(string grid[4][4])
{

    int r = 4;
    int c = 4;

    // Initialize a queue
    queue<pair<int, int>> q;

    // first row
    for (int i = 0; i < c; i++)
    {
        if (grid[0][i] == "O")
        {
            q.push(make_pair(0, i));
            grid[0][i] = "T";
        }
    }

    // first column
    for (int i = 1; i < r; i++)
    {
        if (grid[i][0] == "O")
        {
            q.push(make_pair(i, 0));
            grid[i][0] = "T";
        }
    }

    // last row
    for (int i = 1; i < c; i++)
    {
        if (grid[r - 1][i] == "O")
        {
            q.push(make_pair(r - 1, i));
            grid[r - 1][i] = "T";
        }
    }

    // last column
    for (int i = 1; i < r - 1; i++)
    {
        if (grid[i][c - 1] == "O")
        {
            q.push(make_pair(i, c - 1));
            grid[i][c - 1] = "T";
        }
    }

    while (!q.empty())
    {
        int i = q.front().first;
        int j = q.front().second;
        q.pop();

        int row[4] = {-1, 1, 0, 0};
        int col[4] = {0, 0, -1, 1};

        for (int k = 0; k < 4; k++)
        {
            if (isValid(i + row[k], j + col[k], r, c) && grid[i + row[k]][j + col[k]] == "O")
            {
                grid[i + row[k]][j + col[k]] = "T";
                q.push(make_pair(i + row[k], j + row[k]));
            }
        }
    }

    for (int row = 0; row < r; row++)
    {
        for (int col = 0; col < c; col++)
        {
            if (grid[row][col] == "O")
            {
                grid[row][col] = "X";
            }
            else if (grid[row][col] == "T")
            {
                grid[row][col] = "O";
            }
        }
    }
}

int main()
{

    string grid[4][4] = {
        {"X", "X", "X", "X"},
        {"X", "O", "O", "X"},
        {"X", "X", "O", "X"},
        {"X", "O", "X", "X"},
    };

    solve(grid);

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}