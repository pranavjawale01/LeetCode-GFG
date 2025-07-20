class Solution {
    public int numberOfSubmatrices(char[][] grid) {
        int row = grid.length, col = grid[0].length;

        int[][] x = new int[row][col];
        int[][] y = new int[row][col];

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 'X') {
                    x[i][j] = 1;
                }
                if (grid[i][j] == 'Y') {
                    y[i][j] = 1;
                }
            }
        }

        for (int i = 0; i < row; i++) {
            for (int j = 1; j < col; j++) {
                x[i][j] += x[i][j-1];
                y[i][j] += y[i][j-1];
            }
        }

        for (int j = 0; j < col; j++) {
            for (int i = 1; i < row; i++) {
                x[i][j] += x[i-1][j];
                y[i][j] += y[i-1][j];
            }
        }

        int ans = 0;

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (x[i][j] == y[i][j] && x[i][j] > 0) {
                    ans++;
                }
            }
        }
        
        return ans;
    }
}