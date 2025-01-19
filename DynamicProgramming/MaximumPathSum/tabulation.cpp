#include <iostream>
#include <vector>
using namespace std;

#include <climits>

int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size(), m = matrix[0].size();

    //  Iterate over matrix
    for (int row = 1; row < n; row++)
    {
        for (int col = 0; col < m; col++)
        {
            //  Get maximum of all valid path
            matrix[row][col] = matrix[row][col] + max(matrix[row - 1][col], max(matrix[row - 1][max(0, col - 1)], matrix[row - 1][min(m - 1, col + 1)]));
        }
    }

    //  Get the max path sum
    int maxPathSum = INT_MIN;
    for (int col = 0; col < m; col++)
    {
        if (maxPathSum < matrix[n - 1][col])
        {
            maxPathSum = matrix[n - 1][col];
        }
    }
    return maxPathSum;
}

int main()
{

    int n = 4; // number of rows
    int m = 4; // number of columns

    vector<vector<int>> matrix = {
        {1, 2, 10, 4},
        {100, 3, 2, 1},
        {1, 1, 20, 2},
        {1, 1, 2, 1}};

    cout << getMaxPathSum(matrix);

    return 0;
}