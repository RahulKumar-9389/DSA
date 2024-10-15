#include <iostream>
using namespace std;

void addMatrix(int arr1[][2], int arr2[][2], int rows, int cols)
{

    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            arr1[row][col] = arr1[row][col] + arr2[row][col];
        }
    }
}

int main()
{

    int arr1[2][2] = {
        {1, 2},
        {3, 4}};

    int arr2[2][2] = {
        {5, 6},
        {7, 8}};
    addMatrix(arr1, arr2, 2, 2);
    cout << "Sum of arrays is: ";
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << arr1[i][j] << " ";
        }
    }

    return 0;
}