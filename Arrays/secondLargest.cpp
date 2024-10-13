#include <iostream>
using namespace std;

int secondLargest(int arr[], int n)
{

    int largest = arr[0];
    int second_largest = -1;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > largest)
        {
            second_largest = largest;
            largest = arr[i];
        }
        else if (arr[i] < largest && arr[i] > second_largest)
        {
            second_largest = arr[i];
        }
    }
    return second_largest;
}

int main()
{

    int arr[6] = {6, 2, 4, 8, 10, 9};
    cout << secondLargest(arr, 6) << " is the second largest element in the array!";
    return 0;
}