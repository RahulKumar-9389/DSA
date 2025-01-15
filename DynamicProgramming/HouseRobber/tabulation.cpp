#include <iostream>
using namespace std;

// Function to find the maximum sum of non-adjacent elements
int rob(int nums[], int n)
{
    int prev = nums[0];
    int prev2 = 0;

    for (int i = 1; i < n; i++)
    {

        // take that element
        int take = nums[i];
        if (i > 1)
        {
            take = nums[i] + prev2;
        }

        // not take
        int notTake = 0 + prev;

        int current = max(take, notTake);
        prev2 = prev;
        prev = current;
    }

    return prev;
}

int main()
{

    int nums[] = {1, 2, 3, 1};

    // calculate the size of the array
    int n = sizeof(nums) / sizeof(nums[0]);
    cout << rob(nums, n);
    return 0;
}