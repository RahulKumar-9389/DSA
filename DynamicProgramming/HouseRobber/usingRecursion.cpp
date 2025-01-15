#include <iostream>
using namespace std;

int rob(int idx, int nums[])
{

    if (idx == 0)
    {
        return nums[idx];
    }

    if (idx < 0)
    {
        return 0;
    }

    // we start from last index and we picked that item
    int pick = nums[idx] + rob(idx - 2, nums);

    // if we not pick that element
    int notPick = 0 + rob(idx - 1, nums);

    return max(pick, notPick);
}

int main()
{
    int nums[] = {2, 7, 9, 3, 1};
    int n = sizeof(nums) / sizeof(nums[0]);
    cout << rob(n - 1, nums);
    return 0;
}