#include <iostream>
#include <vector>
using namespace std;

void subsequence(vector<int> &arr, int index, int n, vector<int> temp, vector<vector<int>> &ans)
{
    if (index == n)
    {
        ans.push_back(temp);
        return;
    }

    // Not include
    subsequence(arr, index + 1, n, temp, ans);

    // Include
    temp.push_back(arr[index]);
    subsequence(arr, index + 1, n, temp, ans);
}

int main()
{
    vector<int> arr = {1, 2, 3};
    vector<int> temp;
    vector<vector<int>> ans;

    subsequence(arr, 0, arr.size(), temp, ans);

    cout << "Subsequences are: " << endl;

    for (int i = 0; i < ans.size(); i++)
    {
        if (ans[i].empty())
        {
            cout << "{}" << endl; // For the empty subsequence
        }
        else
        {
            cout << "{ ";
            for (int j = 0; j < ans[i].size(); j++)
            {
                cout << ans[i][j] << " ";
            }
            cout << "}" << endl;
        }
    }
    return 0;
}