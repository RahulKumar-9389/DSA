#include <iostream>
#include <vector>
using namespace std;

void subsetSum(vector<int> &arr, int index, int sum)
{
    if (index == arr.size())
    {
        cout << sum << endl;
        return;
    }

    // take
    subsetSum(arr, index + 1, sum + arr[index]);

    // not take
    subsetSum(arr, index + 1, sum);
}

int main()
{

    vector<int> arr = {3, 1, 2};
    subsetSum(arr, 0, 0);
    return 0;
}