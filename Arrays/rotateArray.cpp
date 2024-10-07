#include <iostream>
using namespace std;

void getReversedArray(int arr[], int left, int right)
{

    while (left <= right)
    {
        swap(arr[left], arr[right]);
        left++;
        right--;
    }
};

void getRotatedArray(int arr[], int size, int k)
{
    k = k % size;
    getReversedArray(arr, 0, (size - k - 1));
    getReversedArray(arr, (size - k), (size - 1));
    getReversedArray(arr, 0, (size - 1));
};

int main()
{

    int arr[6] = {2, 4, 6, 8, 10, 12};
    cout << "Array without rotation" << endl;
    for (int i = 0; i < 6; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Array after 2 rotation " << endl;
    getRotatedArray(arr, 6, 2);
    for (int i = 0; i < 6; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}