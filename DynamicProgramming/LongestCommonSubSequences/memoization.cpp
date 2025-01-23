#include <iostream>
#include <vector>
using namespace std;

int LCS(int i, int j, string &str1, string &str2, vector<vector<int>> &dp)
{

    if (i == str1.size() || j == str2.size())
    {
        return 0;
    }
    else if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    else if (str1[i] == str2[j])
    {
        return 1 + LCS(i + 1, j + 1, str1, str2, dp);
    }
    else
    {
        return dp[i][j] = max(LCS(i + 1, j, str1, str2, dp), LCS(i, j + 1, str1, str2, dp));
    }
}

int main()
{

    string str1 = "abcde";
    string str2 = "ace";

    vector<vector<int>> dp(str1.size() + 1, vector<int>(str2.size() + 1, -1));

    cout << LCS(0, 0, str1, str2, dp);

    return 0;
}