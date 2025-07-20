class Solution {
public:
    bool isSafe(int row, int col, int n, vector<string>& board) {
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q') {
                return false;
            }
        }
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }
        for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }
        return true;
    }

    void solve(int n, vector<string>& board, int row, vector<vector<string>>& solutions) {
        if (row == n) {
            solutions.push_back(board);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (isSafe(row, i, n, board)) {
                board[row][i] = 'Q';
                solve(n, board, row + 1, solutions);
                board[row][i] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> solutions;
        vector<string> board(n, string(n, '.'));

        solve(n, board, 0, solutions);

        return solutions;
    }
};