#include <iostream>
using namespace std;

void sort01(int arr[], int size)
{

    int start = 0;
    int end = size - 1;

    while (start < end)
    {
        if (arr[start] > arr[end])
        {
            swap(arr[start], arr[end]);
            start++;
            end--;
        }
        else
        {
            start++;
            end--;
        }
    }
}

void printArray(int arr[], int size)
{

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int arr[6] = {0, 0, 1, 0, 1, 1};
    sort01(arr, 6);
    printArray(arr, 6);
    return 0;
}