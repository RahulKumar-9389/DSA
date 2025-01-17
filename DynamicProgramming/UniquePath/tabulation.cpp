#include <iostream>
using namespace std;

int main()
{

    int m = 2, n = 2;

    // Create a matrix of size mxn
    int mat[m][n];

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {

            if (i == 0 && j == 0)
            {
                mat[i][j] = 1;
            }
            else
            {
                int up = 0;
                int left = 0;

                if (i > 0)
                {
                    up = mat[i - 1][j];
                }
                if (j > 0)
                {
                    left = mat[i][j - 1];
                }

                mat[i][j] = up + left;
            }
        }
    }

    cout << mat[m - 1][n - 1];

    return 0;
}