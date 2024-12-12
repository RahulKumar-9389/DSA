#include <iostream>
#include <vector>
using namespace std;

void solve(int index, vector<int> &ds, int size, vector<int> &arr)
{

    if (index == size)
    {
        cout << "{ ";
        for (int i = 0; i < ds.size(); i++)
        {
            cout << ds[i] << " ";
        }
        cout << "}";
        cout << endl;
        return;
    }

    // not take
    solve(index + 1, ds, size, arr);

    // take
    ds.push_back(arr[index]);
    solve(index + 1, ds, size, arr);

    // remove
    ds.pop_back();
}

int main()
{

    vector<int> arr = {3, 1, 2};

    int n = arr.size();
    vector<int> ds;

    solve(0, ds, n, arr);

    return 0;
}