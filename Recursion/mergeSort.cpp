#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &arr, int start, int mid, int end)
{

    int left = start;
    int right = mid + 1;

    // Initialize a vector
    vector<int> temp;

    while (left <= mid && right <= end)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }
    }

    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }

    while (right <= end)
    {
        temp.push_back(arr[right]);
        right++;
    }

    for (int i = start; i <= end; i++)
    {
        arr[i] = temp[i - start];
    }
}

void mergeSort(vector<int> &arr, int start, int end)
{

    if (start == end)
    {
        return;
    }

    // calculate the mid
    int mid = (start + ((end - start) / 2));
    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);
    merge(arr, start, mid, end);
}

int main()
{

    vector<int> arr = {4, 9, 1, 10, 6};
    mergeSort(arr, 0, 4);
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}