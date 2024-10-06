#include <iostream>
using namespace std;

void movesZeors(int arr[], int size)
{

    int i = 0;

    for (int j = 0; j < size; j++)
    {
        if (arr[j] != 0)
        {
            swap(arr[i], arr[j]);
            i++;
        }
    }
}

int main()
{

    int arr[5] = {0, 2, 0, 3, 4};
    movesZeors(arr, 5);

    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}