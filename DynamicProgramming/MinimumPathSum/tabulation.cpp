#include <iostream>
#include <vector>
using namespace std;

int minPathSum(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();

    // DP table to store the minimum path sum to reach each cell
    vector<vector<int>> dp(m, vector<int>(n));

    // Fill the DP table
    for (int i = m - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            if (i == m - 1 && j == n - 1)
            {
                dp[i][j] = grid[i][j]; // Starting point (bottom-right corner)
            }
            else if (i == m - 1)
            {
                dp[i][j] = grid[i][j] + dp[i][j + 1]; // Last row
            }
            else if (j == n - 1)
            {
                dp[i][j] = grid[i][j] + dp[i + 1][j]; // Last column
            }
            else
            {
                dp[i][j] = grid[i][j] + min(dp[i + 1][j], dp[i][j + 1]); // Minimum of down and right
            }
        }
    }

    // The top-left corner will contain the minimum path sum
    return dp[0][0];
}

int main()
{
    vector<vector<int>> grid = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}};

    cout << minPathSum(grid);
    return 0;
}
