#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> fourSum(vector<int> &arr, int k)
{

    // Initialize  ans vector
    vector<vector<int>> ans;

    // find the size of the given array
    int n = arr.size();

    // Sort the array
    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; i++)
    {
        if (i > 0 && arr[i] == arr[i - 1])
        {
            continue;
        }

        for (int j = i + 1; j < n;)
        {
            // Initialize two pointers
            int p = j + 1;
            int q = n - 1;

            while (p < q)
            {
                // Calculate the sum
                long long sum = (long long)arr[i] + (long long)arr[j] + (long long)arr[p] + (long long)arr[q];

                if (sum < k)
                {
                    p++;
                }
                else if (sum > k)
                {
                    q--;
                }
                else
                {
                    ans.push_back({arr[i], arr[j], arr[p], arr[q]});
                    p++;
                    q--;

                    while (p < q && arr[p] == arr[p - 1])
                        p++;
                }
            }
            j++;
            while (j < n && arr[j] == arr[j - 1])
            {
                j++;
            }
        }
    }

    return ans;
}

int main()
{

    vector<int> arr = {1, 0, -1, 0, -2, 2};
    int target = 0;

    vector<vector<int>> result = fourSum(arr, target);

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