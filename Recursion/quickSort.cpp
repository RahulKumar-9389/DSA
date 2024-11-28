#include <iostream>
using namespace std;

int getPartitionIndex(int arr[], int low, int high)
{

    int i = low - 1;
    int pivot = arr[high];

    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high)
{

    if (low < high)
    {

        int pi = getPartitionIndex(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main()
{

    int arr[6] = {4, 3, 6, 2, 8, 1};
    quickSort(arr, 0, 5);
    for (int i = 0; i < 6; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}