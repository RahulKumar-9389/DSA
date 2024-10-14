#include <iostream>
#include <climits>
using namespace std;

void largestRowSum(int arr[3][3])
{
    int maxSum = INT_MIN;

    for (int i = 0; i < 3; i++)
    {
        int sum = 0;
        for (int j = 0; j < 3; j++)
        {
            sum += arr[i][j];
        }
        if (maxSum < sum)
        {
            maxSum = sum;
        }
    }
    cout << "Max sum of row is: " << maxSum;
}

int main()
{

    int arr[3][3] = {{2, 5, 6}, {3, 1, 0}, {4, 7, 9}};
    largestRowSum(arr);
    return 0;
}