#include <iostream>
using namespace std;

// Function to perform binary search using recursion
int binarySearch(int arr[], int left, int right, int target)
{
    // Base case: if the range is invalid (left > right), return -1
    if (left > right)
    {
        return -1;
    }

    // Find the middle element
    int mid = left + (right - left) / 2;

    // Check if the target is at the middle
    if (arr[mid] == target)
    {
        return mid;
    }

    // If the target is smaller than mid, search in the left half
    if (arr[mid] > target)
    {
        return binarySearch(arr, left, mid - 1, target);
    }

    // If the target is larger than mid, search in the right half
    return binarySearch(arr, mid + 1, right, target);
}

int main()
{
    // Example array (sorted)
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 47, 52, 63};
    int n = sizeof(arr) / sizeof(arr[0]);

    int target = 23;

    // Call binary search function
    int result = binarySearch(arr, 0, n - 1, target);

    // Output the result
    if (result != -1)
    {
        cout << "Element found at index: " << result << endl;
    }
    else
    {
        cout << "Element not found!" << endl;
    }

    return 0;
}
