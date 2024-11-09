#include <iostream>
#include <vector>
using namespace std;

int removeDuplicate(vector<int> &arr)
{

    int i = 0;

    for (int j = 1; j < arr.size(); j++)
    {

        if (arr[i] != arr[j])
        {
            arr[i + 1] = arr[j];
            i++;
        }
    }
    return i + 1;
}

int main()
{

    vector<int> arr = {1, 2, 2, 2, 3, 4, 4};
    int n = removeDuplicate(arr);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}