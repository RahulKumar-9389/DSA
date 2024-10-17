#include <iostream>
#include <vector>
using namespace std;

int mojorityElement(vector<int> &arr)
{

    int freq = 0, ans = 0;
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        if (freq == 0)
        {
            ans = arr[i];
        }
        if (ans == arr[i])
        {
            freq++;
        }
        else
        {
            freq--;
        }
    }
    return ans;
}

int main()
{

    vector<int> arr = {1, 2, 2, 1, 1, 1};
    cout << mojorityElement(arr) << " is the element that appears more than " << arr.size() / 2 << " times.";
    return 0;
}