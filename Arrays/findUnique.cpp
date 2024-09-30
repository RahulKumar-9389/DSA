#include <iostream>
using namespace std;

int getUniqueElem(int arr[], int size)
{

    int ans = 0;

    for (int i = 0; i < size; i++)
    {
        ans = ans ^ arr[i];
    }
    return ans;
}

int main()
{

    int arr[5] = {2, 4, 6, 2, 6};
    cout << getUniqueElem(arr, 5);
    return 0;
}