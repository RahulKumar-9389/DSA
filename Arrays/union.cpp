#include <iostream>
#include <vector>
using namespace std;

vector<int> findUnion(vector<int> &arr1, vector<int> &arr2)
{
    int i = 0;
    int j = 0;
    int n = arr1.size();
    int m = arr2.size();
    vector<int> ans;

    while (i < n && j < m)
    {
        if (arr1[i] <= arr2[j])
        {
            if (ans.size() == 0 || ans.back() != arr1[i])
            {
                ans.push_back(arr1[i]);
            }
            i++;
        }
        else
        {
            if (ans.size() == 0 || ans.back() != arr2[j])
            {
                ans.push_back(arr2[j]);
            }
            j++;
        }
    }

    while (i < n)
    {
        if (ans.back() != arr1[i])
        {
            ans.push_back(arr1[i]);
        }
        i++;
    }

    while (j < m)
    {
        if (ans.back() != arr2[j])
        {
            ans.push_back(arr2[j]);
        }
        j++;
    }

    return ans;
}

int main()
{

    vector<int> arr1 = {1, 2, 3, 4, 5};
    vector<int> arr2 = {1, 2, 3, 6, 7};

    vector<int> result = findUnion(arr1, arr2);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }

    return 0;
}