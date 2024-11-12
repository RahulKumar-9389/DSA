#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int maxSubArray(vector<int> &arr)
{

    int currentSum = 0;
    int maxSum = INT_MIN;

    for (int i = 0; i < arr.size(); i++)
    {
        currentSum += arr[i];
        maxSum = max(currentSum, maxSum);

        if (currentSum < 0)
        {
            currentSum = 0;
        }
    }
    return maxSum;
}

int main()
{

    vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << "max subarray is: " << maxSubArray(arr);
    return 0;
}