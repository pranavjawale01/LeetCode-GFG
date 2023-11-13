class Solution {
    public List<List<String>> solveNQueens(int n) {
        List<List<String>> solutions = new ArrayList<>();
        char[][] board = new char[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                board[i][j] = '.';
            }
        }
        solve(n, board, 0, solutions);
        return solutions;
    }

    private boolean isSafe(int row, int col, int n, char[][] board) {
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

    private void solve(int n, char[][] board, int row, List<List<String>> solutions) {
        if (row == n) {
            solutions.add(constructSolution(board));
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
 
    private List<String> constructSolution(char[][] board) {
        List<String> solution = new ArrayList<>();
        for (char[] row : board) {
            solution.add(new String(row));
        }
        return solution;
    }
}