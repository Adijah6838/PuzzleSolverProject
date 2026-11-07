#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

// Check if a number can be placed in a specific row and column
bool is_valid(vector<vector<int>>& board, int num, int row, int col) {
    for (int i = 0; i < 9; i++) {
        // Check row
        if (board[row][i] == num && i != col) return false;
        // Check column
        if (board[i][col] == num && i != row) return false;
    }

    // Check 3x3 box
    int box_row = row - row % 3;
    int box_col = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[box_row + i][box_col + j] == num && (box_row + i != row || box_col + j != col)) {
                return false;
            }
        }
    }
    return true;
}

// Find an empty space (represented by 0)
bool find_empty(vector<vector<int>>& board, int& row, int& col) {
    for (row = 0; row < 9; row++) {
        for (col = 0; col < 9; col++) {
            if (board[row][col] == 0) {
                return true; // Found an empty space
            }
        }
    }
    return false; // No empty spaces left
}

// Print the board
void print_board(const vector<vector<int>>& board) {
    for (int i = 0; i < 9; i++) {
        if (i % 3 == 0 && i != 0) {
            cout << "- - - - - - - - - - - -" << endl;
        }
        for (int j = 0; j < 9; j++) {
            if (j % 3 == 0 && j != 0) {
                cout << " | ";
            }
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

// The recursive backtracking algorithm
bool solve(vector<vector<int>>& board) {
    int row, col;
    if (!find_empty(board, row, col)) {
        return true; // Solved!
    }

    for (int num = 1; num <= 9; num++) {
        if (is_valid(board, num, row, col)) {
            board[row][col] = num; // Try the number
            
            if (solve(board)) {
                return true;
            }
            
            board[row][col] = 0; // Backtrack
        }
    }
    return false;
}

int main() {
    vector<vector<int>> board = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    cout << "Here is your unsolved puzzle:" << endl;
    print_board(board);
    
    cout << "\nSolving...\n" << endl;

    // START THE TIMER
    auto start = chrono::high_resolution_clock::now();

    solve(board);

    // END THE TIMER
    auto end = chrono::high_resolution_clock::now();

    cout << "Here is your solved puzzle:" << endl;
    print_board(board);

    // CALCULATE TIME
    chrono::duration<double> duration = end - start;
    cout << "\nAlgorithm finished in: " << duration.count() << " seconds" << endl;

    return 0;
}
