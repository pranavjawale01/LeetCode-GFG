class Solution {
    public int minDistance(String word1, String word2) {
        int m = word1.length(), n = word2.length();
        int[][] dp = new int[m + 1][n + 1];
        
        for (int i = 0; i <= m; i++) {
            dp[i][0] = i;
        }
        for (int j = 0; j <= n; j++) {
            dp[0][j] = j;
        }
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (word1.charAt(i - 1) == word2.charAt(j - 1)) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = 1 + Math.min(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[m][n];
    }
}



// class Solution {
//     private int[][] dp = new int[501][501];
//     private int solve(String word1, String word2, int i, int j) {
//         if (i == 0) {
//             return j;
//         }
//         if (j == 0) {
//             return i;
//         }
//         if (dp[i][j] != -1) {
//             return dp[i][j];
//         }
//         if (word1.charAt(i-1) == word2.charAt(j-1)) {
//             return dp[i][j] = solve(word1, word2, i-1, j-1);
//         }
//         return dp[i][j] = 1 + Math.min(solve(word1, word2, i-1, j), solve(word1, word2, i, j-1));
//     }
//     public int minDistance(String word1, String word2) {
//         int m = word1.length(), n = word2.length();
//         for (int i = 0; i <= m; i++) {
//             Arrays.fill(dp[i], -1);
//         }
//         return solve(word1, word2, m, n);
//     }
// }