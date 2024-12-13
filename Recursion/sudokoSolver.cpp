#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool isSafe(vector<vector<char>> &board, int row, int col, char digit)
    {
        // Check row
        for (int i = 0; i < 9; i++)
        {
            if (board[row][i] == digit)
            {
                return false;
            }
        }

        // Check column
        for (int i = 0; i < 9; i++)
        {
            if (board[i][col] == digit)
            {
                return false;
            }
        }

        // Check 3x3 subgrid
        int sr = (row / 3) * 3;
        int sc = (col / 3) * 3;
        for (int i = sr; i < sr + 3; i++)
        {
            for (int j = sc; j < sc + 3; j++)
            {
                if (board[i][j] == digit)
                {
                    return false;
                }
            }
        }

        return true;
    }

    bool helper(vector<vector<char>> &board, int row, int col)
    {
        // Base case: If we have filled all rows, Sudoku is solved
        if (row == 9)
        {
            return true;
        }

        // Move to next column, and if we reach the end of the row, move to the next row
        int nextRow = row;
        int nextCol = col + 1;
        if (nextCol == 9)
        {
            nextRow = row + 1;
            nextCol = 0;
        }

        // If the current cell is already filled, move to the next cell
        if (board[row][col] != '.')
        {
            return helper(board, nextRow, nextCol);
        }

        // Try digits '1' to '9'
        for (char digit = '1'; digit <= '9'; digit++)
        {
            if (isSafe(board, row, col, digit))
            {
                board[row][col] = digit;
                if (helper(board, nextRow, nextCol))
                {
                    return true;
                }
                board[row][col] = '.'; // Backtrack
            }
        }

        return false; // If no solution is found, return false
    }

    void solveSudoku(vector<vector<char>> &board)
    {
        helper(board, 0, 0); // Start solving from the top-left corner
    }
};

int main()
{
    Solution sol;
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '8', '.', '6', '.', '.', '3'},
        {'4', '.', '9', '.', '.', '8', '.', '7', '9'},
        {'7', '.', '.', '.', '6', '.', '.', '.', '2'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'1', '9', '5', '.', '.', '.', '.', '8', '.'}};

    sol.solveSudoku(board);

    // Print the solved Sudoku board
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
