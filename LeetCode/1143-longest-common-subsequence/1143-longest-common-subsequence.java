class Solution {
    public int longestCommonSubsequence(String text1, String text2) {
        int m = text1.length();
        int n = text2.length();
        int[][] dp = new int[m+1][n+1];
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (text1.charAt(i-1) == text2.charAt(j-1)) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                } else {
                    dp[i][j] = Math.max(dp[i][j-1], dp[i-1][j]);
                }
            }
        }
        return dp[m][n];
    }
}



// class Solution {
//     private int[][] t;

//     public int LCS(String s1, String s2, int m, int n) {
//         if (m == 0 || n == 0)
//             return t[m][n] = 0;

//         if (t[m][n] != -1)
//             return t[m][n];

//         if (s1.charAt(m - 1) == s2.charAt(n - 1))
//             return t[m][n] = 1 + LCS(s1, s2, m - 1, n - 1);

//         return t[m][n] = Math.max(LCS(s1, s2, m, n - 1), LCS(s1, s2, m - 1, n));
//     }

//     public int longestCommonSubsequence(String text1, String text2) {
//         int m = text1.length();
//         int n = text2.length();

//         t = new int[m + 1][n + 1];
//         for (int[] row : t) {
//             Arrays.fill(row, -1);
//         }

//         return LCS(text1, text2, m, n);
//     }
// }