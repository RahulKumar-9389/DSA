#include <iostream>
#include <vector>
using namespace std;

int LIS(int ind, int prev, vector<int> &nums)
{

    if (ind == nums.size())
    {
        return 0;
    }

    // not take
    int notTake = 0 + LIS(ind + 1, prev, nums);

    // take
    int take = 0;
    if (ind == -1 || nums[ind] > nums[prev])
    {
        take = 1 + LIS(ind + 1, ind, nums);
    }

    return max(notTake, take);
}

int main()
{
    vector<int> nums = {2, 1, 0, 3, 5, 9};
    cout << LIS(0, -1, nums);
    return 0;
}