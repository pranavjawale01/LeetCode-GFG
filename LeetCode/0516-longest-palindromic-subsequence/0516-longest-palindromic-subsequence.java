class Solution {
    public int longestPalindromeSubseq(String s) {
        int n = s.length();
        int[][] dp = new int[n][n];
        for (int len = 1; len <= n; len++) {
            for (int start = 0; start <= n - len; start++) {
                int end = start + len - 1;
                if (len == 1) {
                    dp[start][end] = 1;
                    continue;
                }
                if (s.charAt(start) == s.charAt(end)) {
                    dp[start][end] = 2 + dp[start+1][end-1];
                } else {
                    dp[start][end] = Math.max(dp[start+1][end], dp[start][end-1]);
                }
            }
        }
        return dp[0][n-1];
    }
}


// class Solution {
//     private int[][] dp = new int[1000][1000];
//     private int solve(String s, int start, int end) {
//         if (start == end) {
//             return 1;
//         }
//         if (start > end) {
//             return 0;
//         }
//         if (dp[start][end] != -1) {
//             return dp[start][end];
//         }
//         if (s.charAt(start) == s.charAt(end)) {
//             return dp[start][end] = 2 + solve(s, start+1, end-1);
//         }
//         return dp[start][end] = Math.max(solve(s, start+1, end), solve(s, start, end-1));
//     }
//     public int longestPalindromeSubseq(String s) {
//         int n = s.length();
//         for (int i = 0; i < n; i++) {
//             Arrays.fill(dp[i], -1);
//         }
//         return solve(s, 0, s.length()-1);
//     }
// }