#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int func(int i, int j, vector<vector<int>> &triangle, int n, vector<vector<int>> &dp)
{
    if (i == n - 1)
    {
        return triangle[n - 1][j];
    }

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    int down = triangle[i][j] + func(i + 1, j, triangle, n, dp);
    int diagonal = triangle[i][j] + func(i + 1, j + 1, triangle, n, dp);

    return dp[i][j] = min(down, diagonal);
}

int minimumTotal(vector<vector<int>> &triangle)
{
    int n = triangle.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return func(0, 0, triangle, n, dp);
}

int main()
{
    vector<vector<int>> triangle = {
        {2},
        {3, 4},
        {6, 5, 7},
        {4, 1, 8, 3}};

    cout << "Minimum path sum: " << minimumTotal(triangle) << endl;

    return 0;
}
