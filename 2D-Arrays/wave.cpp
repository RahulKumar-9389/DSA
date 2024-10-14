#include <iostream>
using namespace std;

void printWave(int arr[][4], int rows, int cols)
{
    for (int col = 0; col < cols; ++col)
    {
        if (col % 2 == 0)
        {
            // Print top to bottom
            for (int row = 0; row < rows; ++row)
            {
                cout << arr[row][col] << " ";
            }
            cout << endl;
        }
        else
        {
            // Print bottom to top
            for (int row = rows - 1; row >= 0; --row)
            {
                cout << arr[row][col] << " ";
            }
            cout << endl;
        }
    }
}

int main()
{
    const int rows = 3;
    const int cols = 4;
    int arr[rows][cols] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}};

    cout << "Wave pattern output:\n";
    printWave(arr, rows, cols);

    return 0;
}
