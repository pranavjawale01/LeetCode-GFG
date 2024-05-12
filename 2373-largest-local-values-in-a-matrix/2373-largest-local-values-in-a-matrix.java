class Solution {
    public int[][] largestLocal(int[][] grid) {
        int n = grid.length;
        int[][] ans = new int[n-2][n-2];
        
        for (int i = 0; i < n - 2; i++) {
            for (int j = 0; j < n - 2; j++) {
                int temp = Integer.MIN_VALUE;
                temp = Math.max(Math.max(grid[i][j], grid[i][j+1]), Math.max(Math.max(grid[i][j+2], grid[i+1][j]), Math.max(grid[i+1][j+1], Math.max(grid[i+1][j+2], Math.max(grid[i+2][j], Math.max(grid[i+2][j+1], grid[i+2][j+2]))))));
                ans[i][j] = temp;
            }
        }
        
        return ans;
    }
}