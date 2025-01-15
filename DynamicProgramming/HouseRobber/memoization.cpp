#include <iostream>
using namespace std;

int rob(int idx, int nums[], int dp[])
{

    if (idx == 0)
    {
        return nums[idx];
    }

    if (idx < 0)
    {
        return 0;
    }

    if (dp[idx] != -1)
    {
        return dp[idx];
    }

    // we start from last index and we picked that item
    int pick = nums[idx] + rob(idx - 2, nums, dp);

    // if we not pick that element
    int notPick = 0 + rob(idx - 1, nums, dp);

    return dp[idx] = max(pick, notPick);
}

int main()
{
    int nums[] = {2, 7, 9, 3, 1};
    int n = sizeof(nums) / sizeof(nums[0]);
    int dp[n];
    for (int i = 0; i < n; i++)
    {
        dp[i] = -1;
    }
    cout << rob(n - 1, nums, dp);

    return 0;
}