public class Solution {
    int m, n;
    int[][][] t;
    int[] colDir = {-1, 0, 1};
    
    boolean isSafe(int i) {
        return i >= 0 && i < n;
    }
    
    int solve(int[][] grid, int row, int c1, int c2) {
        if (row >= m)
            return 0;
        
        if (t[row][c1][c2] != -1) {
            return t[row][c1][c2];
        }
        
        int count = grid[row][c1];
        if (c1 != c2) {
            count += grid[row][c2];
        }
        
        int ans = 0;
        for(int x : colDir) {
            for(int y : colDir) {
                int c1_ = x + c1;
                int c2_ = y + c2;
                if(isSafe(c1_) && isSafe(c2_)) {
                    ans = Math.max(ans, solve(grid, row+1, c1_, c2_));
                }
            }
        }
        
        return t[row][c1][c2] = count + ans;
    }
    
    public int cherryPickup(int[][] grid) {
        m = grid.length;
        n = grid[0].length;
        t = new int[m][n][n];
        for(int[][] arr : t) {
            for(int[] row : arr) {
                Arrays.fill(row, -1);
            }
        }
        return solve(grid, 0, 0, n-1);
    }
}