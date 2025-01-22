#include <iostream>
#include <vector>
using namespace std;

int main()
{

    int W = 6;
    int n = 3;

    vector<int> wt = {3, 2, 4};
    vector<int> val = {30, 40, 60};

    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; ++i)
    {
        for (int w = 1; w <= W; ++w)
        {
            if (wt[i - 1] <= w)
            {
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - wt[i - 1]] + val[i - 1]);
            }
            else
            {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    cout << dp[n][W] << endl;

    return 0;
}
