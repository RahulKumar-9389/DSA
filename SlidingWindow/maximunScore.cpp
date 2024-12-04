#include <iostream>
#include <vector>
using namespace std;

int maxScore(vector<int> &arr, int k)
{
    int leftSum = 0;
    int rightSum = 0;
    int maxSum = 0;
    int n = arr.size();

    // Sum the first k elements for leftSum
    for (int i = 0; i < k; i++)
    {
        leftSum += arr[i];
    }
    maxSum = leftSum;

    // rightSum starts with the sum of the last k elements
    for (int i = n - 1; i >= n - k; i--)
    {
        rightSum += arr[i];
    }

    // Sliding window: gradually replace one element from the right with one element from the left
    for (int i = 0; i < k; i++)
    {
        leftSum -= arr[k - 1 - i];                // Remove one element from the left part
        rightSum += arr[n - 1 - i];               // Add one element from the right part
        maxSum = max(maxSum, leftSum + rightSum); // Track maximum sum
    }

    return maxSum;
}

int main()
{
    vector<int> arr = {6, 2, 3, 4, 7, 2, 1, 7, 1};
    cout << maxScore(arr, 4); // Output the maximum score
    return 0;
}
