#include <iostream>
#include <algorithm>
using namespace std;

int getPathMaxSum(int i, int j, int matrix[4][4], int dp[4][4])
{

    if (j < 0 || j >= 4)
    {
        return -1e9;
    }

    if (i == 0)
    {
        return matrix[0][j];
    }

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    int up = matrix[i][j] + getPathMaxSum(i - 1, j, matrix, dp);
    int ld = matrix[i][j] + getPathMaxSum(i - 1, j - 1, matrix, dp);
    int rd = matrix[i][j] + getPathMaxSum(i - 1, j + 1, matrix, dp);

    return dp[i][j] = max({up, ld, rd});
}

int main()
{

    int n = 4; // number of rows
    int m = 4; // number of columns

    int matrix[4][4] = {
        {1, 2, 10, 4},
        {100, 3, 2, 1},
        {1, 1, 20, 2},
        {1, 1, 2, 1}};

    int dp[4][4];
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            dp[i][j] = -1;
        }
    }

    int ans = -1e9;

    for (int j = 0; j < 4; j++)
    {
        ans = max(ans, getPathMaxSum(n - 1, j, matrix, dp));
    }
    cout << ans;

    return 0;
}