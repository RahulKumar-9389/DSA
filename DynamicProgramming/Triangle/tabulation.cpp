#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minimumTotal(vector<vector<int>> &triangle)
{
    int n = triangle.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int j = 0; j < n; j++)
    {
        dp[n - 1][j] = triangle[n - 1][j];
    }

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = i; j >= 0; j--)
        {
            int down = triangle[i][j] + dp[i + 1][j];
            int diagonal = triangle[i][j] + dp[i + 1][j + 1];

            dp[i][j] = min(down, diagonal);
        }
    }

    return dp[0][0];
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
