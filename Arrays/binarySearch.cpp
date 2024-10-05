#include <iostream>
#include <vector>
using namespace std;

int isItemPresent(vector<int> &arr, int size, int target)
{

    int start = 0;
    int end = size - 1;

    while (start <= end)
    {

        int mid = (start + ((end - start) / 2));
        if (arr[mid] == target)
        {
            return mid;
        }

        if (arr[mid] > target)
        {
            end = mid - 1; // Search in left part
        }
        else
        {
            start = mid + 1; // Search in right part
        }
    }
    return -1;
}

int main()
{

    vector<int> arr = {2, 4, 7, 9, 10};
    int res = isItemPresent(arr, arr.size(), 9);
    cout << res << endl;
    if (res != -1)
    {
        cout << "Item is present at index: " << res;
    }
    else
    {
        cout << "Item is not present!";
    }
    return 0;
}