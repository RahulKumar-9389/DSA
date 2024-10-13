#include <iostream>
#include <climits>
using namespace std;

int getLargestElem(int arr[], int n)
{

    int largest = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > largest)
        {
            largest = arr[i];
        }
    }
    return largest;
}

int main()
{

    int arr[6] = {2, 5, 1, 3, 9, 0};
    cout << getLargestElem(arr, 6);

    return 0;
}