class Solution {
public:
    int totalNQueens(int n) {
        int count = 0;
        vector<string> board(n, string(n, '.'));
        solve(n, board, 0, count);
        return count;
    }

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

    void solve(int n, vector<string>& board, int row, int& count) {
        if (row == n) {
            count++;
            return;
        }
        for (int i = 0; i < n; i++) {
            if (isSafe(row, i, n, board)) {
                board[row][i] = 'Q';
                solve(n, board, row + 1, count);
                board[row][i] = '.';
            }
        }
    }
};