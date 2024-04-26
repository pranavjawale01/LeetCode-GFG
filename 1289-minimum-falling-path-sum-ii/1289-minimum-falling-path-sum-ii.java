class Solution {
    public int minFallingPathSum(int[][] grid) {
        int n = grid.length;
        int[][] dp = new int[n+1][n+1];
        for (int i = 0; i < n; i++) {
            dp[n-1][i] = grid[n-1][i];
        }
        for (int row = n - 2; row >= 0; row--) {
            for (int col = 0; col < n; col++) {
                int ans = Integer.MAX_VALUE;
                for (int nextCol = 0; nextCol < n; nextCol++) {
                    if (nextCol != col) {
                        ans = Math.min(ans, dp[row+1][nextCol]);
                    }
                    dp[row][col] = grid[row][col] + ans;
                }
            }
        }
        int ans = Integer.MAX_VALUE;
        for (int i = 0; i < n; i++) {
            ans = Math.min(ans, dp[0][i]);
        }
        return ans;
    }
}

// class Solution {
//     public int[][] dp = new int[201][201];

//     public int solve(int[][] grid, int n, int level, int col) {
//         if (level == n - 1) {
//             return dp[level][col] = grid[level][col];
//         }
//         if (dp[level][col] != -1) {
//             return dp[level][col];
//         }
//         int ans = Integer.MAX_VALUE;
//         for (int j = 0; j < n; j++) {
//             if (col == j) {
//                 continue;
//             }
//             ans = Math.min(ans, grid[level][col] + solve(grid, n, level + 1, j));
//         }
//         return dp[level][col] = ans;
//     }

//     public int minFallingPathSum(int[][] grid) {
//         int n = grid.length;
//         for (int[] row : dp) {
//             Arrays.fill(row, -1);
//         }
//         int ans = Integer.MAX_VALUE;
//         for (int j = 0; j < n; j++) {
//             ans = Math.min(ans, solve(grid, n, 0, j));
//         }
//         return ans;
//     }
// }