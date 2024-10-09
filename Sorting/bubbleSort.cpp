#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n)
{

    for (int i = 0; i < n - 1; i++)
    {

        bool swaped = false;

        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swaped = true;
            }
        }

        if (!swaped)
        {
            break;
        }
    }
}

void printArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[5] = {5, 2, 9, 1, 0};
    cout << "Array before sorting " << endl;
    printArr(arr, 5);
    cout << "Array after sorting " << endl;
    bubbleSort(arr, 5);
    printArr(arr, 5);
    return 0;
}
