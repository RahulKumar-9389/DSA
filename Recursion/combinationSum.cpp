#include <iostream>
#include <vector>
using namespace std;

void combinationSum(int arr[], int target, int index, vector<int> &ans)
{

    if (target == 0)
    {
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
        return;
    }

    if (index >= 3)
    {
        return;
    }

    if (arr[index] <= target)
    {
        ans.push_back(arr[index]);
        combinationSum(arr, target - arr[index], index, ans);
        ans.pop_back();
    }

    combinationSum(arr, target, index + 1, ans);
}

int main()
{

    int arr[3] = {2, 3, 5};
    vector<int> ans;
    int target = 8;

    combinationSum(arr, target, 0, ans);

    return 0;
}