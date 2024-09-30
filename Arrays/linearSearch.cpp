#include <iostream>
using namespace std;

int linearSearch(int arr[], int size, int key)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == key)
        {
            return i;
        }
    }
    return 0;
}

int main()
{

    int arr[6] = {2, 4, 6, 8, 10};
    int size = sizeof(arr) / sizeof(arr[0]);
    int result = linearSearch(arr, size, 6);
    if (result)
    {
        cout << "item is present at index: " << result;
    }
    else
    {
        cout << "Items is not present in the array!";
    }
    return 0;
}