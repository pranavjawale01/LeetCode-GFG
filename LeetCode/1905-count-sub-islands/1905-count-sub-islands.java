class Solution {
    private int row, col;
    private int[][] dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    private boolean dfs(int i, int j, int[][] grid1, int[][] grid2) {
        if (i < 0 || j < 0 || i >= row || j >= col || grid2[i][j] == 0) {
            return true;
        }
        grid2[i][j] = 0;
        boolean ans = grid1[i][j] == 1;
        for (int[] dir : dirs) {
            int x = dir[0] + i;
            int y = dir[1] + j;
            ans = ans & dfs(x, y, grid1, grid2);
        }
        return ans;
    }
    public int countSubIslands(int[][] grid1, int[][] grid2) {
        row = grid1.length;
        col = grid1[0].length;
        int count = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid2[i][j] == 1 && dfs(i, j, grid1, grid2)) {
                    count++;
                }
            }
        }
        return count;
    }
}