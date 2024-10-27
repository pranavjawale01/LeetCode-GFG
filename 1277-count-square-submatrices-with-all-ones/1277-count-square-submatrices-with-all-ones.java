class Solution {
    public int countSquares(int[][] matrix) {
        int m = matrix.length, n = matrix[0].length;
        if (m == 0) return 0;
        int[][] dp = new int[m][n];
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 || j == 0) {
                    dp[i][j] = matrix[i][j];
                } else {
                    if (matrix[i][j] == 1) {
                        dp[i][j] = 1 + Math.min(dp[i - 1][j], Math.min(dp[i][j - 1], dp[i - 1][j - 1]));
                    }
                }
                ans += dp[i][j];
            }
        }
        return ans;
    }
}







// class Solution {
//     int m, n;
//     int solve(int i, int j, int[][] mat, int[][] dp) {
//         if (i >= m || j >= n) return 0;
//         if (mat[i][j] == 0) return 0;
//         if (dp[i][j] != -1) return dp[i][j];
//         int right = solve(i, j + 1, mat, dp);
//         int diagonal = solve(i + 1, j + 1, mat, dp);
//         int below = solve(i + 1, j, mat, dp);
//         return dp[i][j] = 1 + Math.min(right, Math.min(diagonal, below));
//     }
    
//     public int countSquares(int[][] matrix) {
//         int ans = 0;
//         m = matrix.length;
//         n = matrix[0].length;
//         int[][] dp = new int[m][n];
//         for (int[] row : dp) Arrays.fill(row, -1);
        
//         for (int i = 0; i < m; i++) {
//             for (int j = 0; j < n; j++) {
//                 ans += solve(i, j, matrix, dp);
//             }
//         }
//         return ans;
//     }
// }