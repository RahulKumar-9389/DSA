#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> plusOne(vector<int> &arr)
{

    // find the size of the array
    int n = arr.size();

    // Start the loop from the last digit
    for (int i = n - 1; i >= 0; i++)
    {
        if (arr[i] < 9)
        {
            arr[i]++;
            return arr;
        }
        arr[i] = 0;
    }

    arr.insert(arr.begin(), 1);
    return arr;
}

int main()
{

    vector<int> arr = {1, 9};

    vector<int> ans = plusOne(arr);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}