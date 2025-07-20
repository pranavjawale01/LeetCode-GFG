class Solution {
    public int uniquePaths(int m, int n) {
        int[][] dp = new int[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 || j == 0) {
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }
        return dp[m-1][n-1];
    }
}





// class Solution {
//     private int[][] dp = new int[101][101];

//     private int solve(int i, int j, int m, int n) {
//         if (i == m - 1 && j == n - 1) {
//             return 1;
//         }
//         if (i >= m || j >= n) {
//             return 0;
//         }
//         if (dp[i][j] != -1) {
//             return dp[i][j];
//         }
//         return dp[i][j] = solve(i+1, j, m, n) + solve(i, j+1, m, n);
//     }

//     public int uniquePaths(int m, int n) {
//         for (int i = 0; i < m; i++) {
//             Arrays.fill(dp[i], -1);
//         }
//         return solve(0, 0, m, n);
//     }
// }