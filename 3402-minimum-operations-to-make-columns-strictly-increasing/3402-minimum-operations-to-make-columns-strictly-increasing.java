class Solution {
    public int minimumOperations(int[][] grid) {
        int row = grid.length;
        int col = grid[0].length;
        int ans = 0;
        
        for (int i = 0; i < col; i++) {
            for (int j = 1; j < row; j++) {
                if (grid[j][i] <= grid[j-1][i]) {
                    int temp = Math.abs(grid[j][i] - grid[j-1][i]) + 1;
                    ans += temp;
                    grid[j][i] += temp;
                }
            }
        }
        
        return ans;
    }
}