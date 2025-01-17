#include <iostream>
using namespace std;

int uniquePath(int mat[][3], int m, int n)
{
    if (m == 0 && n == 0)
    {
        return 1;
    }

    if (m < 0 || n < 0)
    {
        return 0;
    }

    if (mat[m][n] != -1)
    {
        return mat[m][n];
    }

    int up = uniquePath(mat, m - 1, n);
    int left = uniquePath(mat, m, n - 1);

    return mat[m][n] = up + left;
}

int main()
{

    int m = 3;
    int n = 3;
    int matrix[3][3] = {
        {-1, -1, -1},
        {-1, -1, -1},
        {-1, -1, -1}};

    cout << uniquePath(matrix, m - 1, n - 1);
    return 0;
}