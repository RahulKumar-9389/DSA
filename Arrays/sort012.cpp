#include <iostream>
using namespace std;

void sort012(int arr[], int n)
{

    int low = 0;
    int mid = 0;
    int high = n - 1;

    while (mid <= high)
    {

        if (arr[mid] == 0)
        {
            swap(arr[low++], arr[mid++]);
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{

    int arr[6] = {2, 0, 2, 1, 1, 0};
    cout << "Array without sorting: ";
    printArray(arr, 6);

    cout << "Array after sorting: ";
    sort012(arr, 6);
    printArray(arr, 6);
    return 0;
}