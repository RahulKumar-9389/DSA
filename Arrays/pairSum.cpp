#include <iostream>
#include <vector>
using namespace std;

bool pairSum(vector<int> &arr, int size, int target, int &num1, int &num2)
{

    int left = 0;
    int right = size - 1;

    while (left < right)
    {
        if (arr[left] + arr[right] == target)
        {
            num1 = arr[left];
            num2 = arr[right];
            return true;
        }
        else if (arr[left] + arr[right] > target)
        {
            right--;
        }
        else
        {
            left++;
        }
    }
    return false;
}

int main()
{
    vector<int> arr = {2, 5, 7, 10, 11};
    int size = arr.size();
    int num1, num2;

    if (pairSum(arr, size, 15, num1, num2))
    {
        cout << "Pair found: " << num1 << " and " << num2;
    }
    else
    {
        cout << "No pair found!";
    }

    return 0;
}