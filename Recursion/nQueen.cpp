#include <iostream>
using namespace std;

// Function to print the chessboard
void printSolution(int board[][10], int N)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << board[i][j] << " "; // Print 1 for Queen, 0 for empty space
        }
        cout << endl;
    }
    cout << endl;
}

// Function to check if a queen can be placed on board[row][col]
bool isSafe(int board[][10], int row, int col, int N)
{
    // Check the column
    for (int i = 0; i < row; i++)
    {
        if (board[i][col] == 1)
        {
            return false;
        }
    }

    // Check upper left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
    }

    // Check upper right diagonal
    for (int i = row, j = col; i >= 0 && j < N; i--, j++)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
    }

    return true;
}

// Recursive function to solve the N-Queens problem
bool solveNQueens(int board[][10], int row, int N)
{
    if (row == N)
    {
        // If all queens are placed successfully
        printSolution(board, N);
        return true;
    }

    bool res = false;
    for (int col = 0; col < N; col++)
    {
        // Check if it's safe to place the queen at board[row][col]
        if (isSafe(board, row, col, N))
        {
            board[row][col] = 1; // Place queen

            // Recur to place the next queen
            res = solveNQueens(board, row + 1, N) || res;

            // Backtrack
            board[row][col] = 0; // Remove queen (backtrack)
        }
    }

    return res;
}

int main()
{
    int N;
    cout << "Enter the value of N: ";
    cin >> N; // Take input for the size of the chessboard

    // Initialize the chessboard with all 0s (empty spaces)
    int board[10][10] = {0};

    if (!solveNQueens(board, 0, N))
    {
        cout << "Solution does not exist" << endl;
    }

    return 0;
}
