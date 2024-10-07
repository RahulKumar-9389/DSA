#include <iostream>
using namespace std;

int getSingleElement(int arr[], int size)
{

    int start = 0;
    int end = size - 1;

    while (start <= end)
    {

        int mid = start + (end - start) / 2;

        if (arr[mid - 1] != arr[mid] && arr[mid] != arr[mid + 1])
        {
            return arr[mid];
        }

        if (mid % 2 == 0)
        {
            if (arr[mid - 1] == arr[mid])
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        else
        {
            if (arr[mid - 1] == arr[mid])
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
    }
}

int main()
{

    int nums[9] = {1, 2, 2, 3, 3, 4, 4, 8, 8};
    cout << getSingleElement(nums, 9);

    return 0;
}