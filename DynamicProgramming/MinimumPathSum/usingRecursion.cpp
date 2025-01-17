#include <iostream>
#include <vector>
using namespace std;

int minPathSum(vector<vector<int>> &grid, int i, int j)
{

    // Base case
    if (i == 0 && j == 0)
    {
        return grid[i][j];
    }

    if (i < 0 || j < 0)
    {
        return 1e9;
    }

    int top = grid[i][j] + minPathSum(grid, i - 1, j);
    int left = grid[i][j] + minPathSum(grid, i, j - 1);

    return min(left, top);
}

int main()
{

    int m = 3;
    int n = 3;

    vector<vector<int>> grid = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}};

    cout << minPathSum(grid, m - 1, n - 1);
    return 0;
}