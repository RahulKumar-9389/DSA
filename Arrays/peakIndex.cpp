#include <iostream>
using namespace std;

int getPeakIndex(int arr[], int size)
{

    int start = 1;
    int end = size - 2;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1])
        {
            return mid;
        }

        if (arr[mid] > arr[mid - 1])
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return -1;
}

int main()
{

    int arr[6] = {0, 3, 8, 9, 10, 2}; // mountain array
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "Peak index is: " << getPeakIndex(arr, size);
}