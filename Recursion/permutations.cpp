#include <iostream>
#include <vector>
using namespace std;

void getPermutations(vector<int> &arr, vector<vector<int>> &ans, vector<int> &temp, vector<int> &visited)
{
    if (temp.size() == arr.size())
    {
        ans.push_back(temp);
        return;
    }

    for (int i = 0; i < arr.size(); i++)
    {
        if (!visited[i])
        {
            temp.push_back(arr[i]);
            visited[i] = 1;
            getPermutations(arr, ans, temp, visited);
            visited[i] = 0;
            temp.pop_back();
        }
    }
}

vector<vector<int>> permute(vector<int> &arr)
{
    vector<int> temp;
    vector<vector<int>> ans;
    vector<int> visited(arr.size(), 0);

    getPermutations(arr, ans, temp, visited);

    return ans;
}

int main()
{

    vector<int> arr = {1, 2, 3};

    vector<vector<int>> result = permute(arr);

    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}