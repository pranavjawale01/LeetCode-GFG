class Solution {
    public void solve(int[][] grid, int i, int j, int row, int col, int[] peri) {
        if (i < 0 || i >= row || j < 0 || j >= col || grid[i][j] == 0) {
            peri[0]++;
            return;
        }
        if (grid[i][j] == -1) {
            return;
        }
        grid[i][j] = -1;
        solve(grid, i+1, j, row, col, peri);
        solve(grid, i-1, j, row, col, peri);
        solve(grid, i, j+1, row, col, peri);
        solve(grid, i, j-1, row, col, peri);
    }
    public int islandPerimeter(int[][] grid) {
        int row = grid.length;
        int col = grid[0].length;
        int[] peri = new int[1];
        peri[0] = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 1) {
                    solve(grid, i, j, row, col, peri);
                    return peri[0];
                }
            }
        }
        return 0;
    }
}