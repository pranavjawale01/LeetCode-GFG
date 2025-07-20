class Solution {
    public int minInsertions(String s) {
        String reversed = new StringBuilder(s).reverse().toString();
        int n = s.length();
        int[][] dp = new int[n+1][n+1];
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                if(s.charAt(i-1) == reversed.charAt(j-1)) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = Math.max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return n - dp[n][n];
    }
}




// class Solution {
//     public int minInsertions(String s) {
//         int n = s.length();
//         int[][] dp = new int[n][n];

//         for (int len = 2; len <= n; ++len) {
//             for (int i = 0; i <= n - len; ++i) {
//                 int j = i + len - 1;
//                 if (s.charAt(i) == s.charAt(j)) {
//                     dp[i][j] = dp[i + 1][j - 1];
//                 } else {
//                     dp[i][j] = 1 + Math.min(dp[i + 1][j], dp[i][j - 1]);
//                 }
//             }
//         }

//         return dp[0][n - 1];
//     }
// }





// class Solution {
//     private int n;
//     private int solve(String s, int i, int j, int[][] dp) {
//         if (i > j) {
//             return 0;
//         }
//         if (dp[i][j] != -1) {
//             return dp[i][j];
//         }
//         if (s.charAt(i) == s.charAt(j)) {
//             return dp[i][j] = solve(s, i+1, j-1, dp);
//         }
//         return dp[i][j] = 1 + Math.min(solve(s, i, j-1, dp), solve(s, i+1, j, dp));
//     }
//     public int minInsertions(String s) {
//         n = s.length();
//         int[][] dp = new int[n][n];
//         for (int i = 0; i < n; i++) {
//             Arrays.fill(dp[i], -1);
//         }
//         return solve(s, 0, n-1, dp);
//     }
// }