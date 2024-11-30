#include <iostream>
#include <vector>
using namespace std;

void findCombination(vector<int> &arr, int index, int target, vector<int> &temp, vector<vector<int>> &ans)
{
    if (target == 0) // Base case: target reached
    {
        ans.push_back(temp);
        return;
    }

    if (index == arr.size()) // No more elements to check
    {
        return;
    }

    // If arr[index] can be used in the combination (only if it is <= target)
    if (arr[index] <= target)
    {
        temp.push_back(arr[index]);                                  // Choose the current number
        findCombination(arr, index, target - arr[index], temp, ans); // Try with the same index (repetition allowed)
        temp.pop_back();                                             // Backtrack
    }

    // Skip the current number and move to the next
    findCombination(arr, index + 1, target, temp, ans);
}

vector<vector<int>> combinationSum(vector<int> &arr, int target)
{
    vector<int> temp;
    vector<vector<int>> ans;

    findCombination(arr, 0, target, temp, ans);
    return ans;
}

int main()
{
    vector<int> arr = {2, 3, 6, 7};

    vector<vector<int>> result = combinationSum(arr, 7);

    cout << "[ ";
    for (int i = 0; i < result.size(); i++)
    {
        cout << "[";
        for (int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j];
            if (j != result[i].size() - 1) // To avoid trailing commas
                cout << " ";
        }
        cout << "]";
        if (i != result.size() - 1) // To avoid trailing commas
            cout << ", ";
    }
    cout << " ]" << endl;

    return 0;
}
