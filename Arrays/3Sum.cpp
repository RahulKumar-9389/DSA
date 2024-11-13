#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Funtion to find three element which sum equal to 0
vector<vector<int>> threeSum(vector<int> &nums)
{

    // Create a ans vector
    vector<vector<int>> ans;

    // Find the size of the array
    int n = nums.size();

    // Sort the array
    sort(nums.begin(), nums.end());

    for (int i = 0; i < n; i++)
    {

        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        // Initialize two pointers j and k

        int j = i + 1; // Points the i+1 element
        int k = n - 1; // Points the last(largest) element

        while (j < k)
        {

            // Calculate the sum
            int sum = nums[i] + nums[j] + nums[k];

            if (sum > 0)
            {
                k--;
            }
            else if (sum < 0)
            {
                j++;
            }
            else
            {
                ans.push_back({nums[i], nums[j], nums[k]});
                j++;
                k--;

                while (j < k && nums[j] == nums[j - 1])
                    j++;
            }
        }
    }

    return ans;
}

int main()
{
    vector<int> arr = {-1, 0, 1, 2, -1, -4};

    vector<vector<int>> result = threeSum(arr);

    for (int i = 0; i < result.size(); i++)
    {
        cout << "[";
        for (int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j];
            if (j < result[i].size() - 1)
                cout << ", ";
        }
        cout << "]" << endl;
    }
    return 0;
}