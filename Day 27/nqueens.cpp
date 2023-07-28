//https://www.codingninjas.com/studio/problems/n-queens_8230707?challengeSlug=striver-sde-challenge&leftPanelTab=1

#include <vector>

// Function to add a valid solution to the answer vector
void addSolution(const std::vector<std::vector<int>>& board, std::vector<std::vector<int>>& ans, int n) {
    std::vector<int> temp;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            temp.push_back(board[i][j]);
        }
    }
    ans.push_back(temp);
}

// Function to check if placing a queen at a given position is safe
bool isSafe(int row, int col, const std::vector<std::vector<int>>& board, int n) {
    int x = row;
    int y = col;

    // Check the entire row on the left since the right is obviously empty
    while (y >= 0) {
        if (board[x][y] == 1) {
            return false;
        }
        y--;
    }

    x = row;
    y = col;

    // Check the 1st diagonal on the left going up
    while (x >= 0 && y >= 0) {
        if (board[x][y] == 1) {
            return false;
        }
        x--;
        y--;
    }

    x = row;
    y = col;

    // Check the 2nd diagonal on the left going down
    while (x < n && y >= 0) {
        if (board[x][y] == 1) {
            return false;
        }
        x++;
        y--;
    }

    return true;
}

// Function to solve the N-Queens problem using backtracking
void solve(int col, std::vector<std::vector<int>>& ans, std::vector<std::vector<int>>& board, int n) {
    // Base case: All columns are filled, we found a valid solution
    if (col == n) {
        addSolution(board, ans, n);
        return;
    }

    // Try placing a queen in each row of the current column
    for (int row = 0; row < n; row++) {
        if (isSafe(row, col, board, n)) { // If all conditions are satisfied
            board[row][col] = 1; // Place the queen
            solve(col + 1, ans, board, n); // Recurse for the next column
            board[row][col] = 0; // Backtrack: Remove the queen for other possibilities
        }
    }
}

// Function to find all possible solutions to the N-Queens problem
std::vector<std::vector<int>> solveNQueens(int n) {
    std::vector<std::vector<int>> board(n, std::vector<int>(n, 0));
    std::vector<std::vector<int>> ans;
    solve(0, ans, board, n);
    return ans;
}
