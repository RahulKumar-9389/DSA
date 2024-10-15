#include <iostream>

void rotateMatrix90Degrees(int matrix[][10], int n)
{
    // Transpose the matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            // Swap elements
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }

    // Reverse each row
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n / 2; j++)
        {
            // Swap elements
            int temp = matrix[i][j];
            matrix[i][j] = matrix[i][n - 1 - j];
            matrix[i][n - 1 - j] = temp;
        }
    }
}

void printMatrix(int matrix[][10], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main()
{
    int n = 3; // Size of the matrix
    int matrix[10][10] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    std::cout << "Original Matrix:\n";
    printMatrix(matrix, n);

    rotateMatrix90Degrees(matrix, n);

    std::cout << "\nRotated Matrix:\n";
    printMatrix(matrix, n);

    return 0;
}
