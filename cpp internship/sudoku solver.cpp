#include <iostream>
using namespace std;

const int SIZE = 9;

// Function to print Sudoku
void printBoard(int board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

// Check if a number can be placed
bool isSafe(int board[SIZE][SIZE], int row, int col, int num) {

    // Check row
    for (int x = 0; x < SIZE; x++) {
        if (board[row][x] == num)
            return false;
    }

    // Check column
    for (int x = 0; x < SIZE; x++) {
        if (board[x][col] == num)
            return false;
    }

    // Check 3x3 subgrid
    int startRow = row - row % 3;
    int startCol = col - col % 3;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[startRow + i][startCol + j] == num)
                return false;
        }
    }

    return true;
}

// Solve Sudoku using Backtracking
bool solveSudoku(int board[SIZE][SIZE]) {

    int row, col;
    bool empty = false;

    // Find an empty cell
    for (row = 0; row < SIZE; row++) {
        for (col = 0; col < SIZE; col++) {
            if (board[row][col] == 0) {
                empty = true;
                goto FOUND;
            }
        }
    }

FOUND:

    if (!empty)
        return true;

    // Try numbers 1 to 9
    for (int num = 1; num <= 9; num++) {

        if (isSafe(board, row, col, num)) {

            board[row][col] = num;

            if (solveSudoku(board))
                return true;

            // Backtrack
            board[row][col] = 0;
        }
    }

    return false;
}

int main() {

    int board[SIZE][SIZE] = {
        {5,3,0,0,7,0,0,0,0},
        {6,0,0,1,9,5,0,0,0},
        {0,9,8,0,0,0,0,6,0},
        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},
        {0,6,0,0,0,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},
        {0,0,0,0,8,0,0,7,9}
    };

    cout << "Original Sudoku:\n";
    printBoard(board);

    if (solveSudoku(board)) {
        cout << "\nSolved Sudoku:\n";
        printBoard(board);
    } else {
        cout << "No solution exists.";
    }

    return 0;
}