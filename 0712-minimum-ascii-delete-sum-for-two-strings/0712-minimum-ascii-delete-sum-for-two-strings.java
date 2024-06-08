class Solution {
    private int m, n;
    private int[][] dp;

    public int solve(String s1, String s2, int i, int j) {
        if (i >= m && j >= n) {
            return 0;
        }
        if (i >= m) {
            return s2.charAt(j) + solve(s1, s2, i, j + 1);
        }
        if (j >= n) {
            return s1.charAt(i) + solve(s1, s2, i + 1, j);
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        if (s1.charAt(i) == s2.charAt(j)) {
            return dp[i][j] = solve(s1, s2, i + 1, j + 1);
        }
        int take_i = s1.charAt(i) + solve(s1, s2, i + 1, j);
        int take_j = s2.charAt(j) + solve(s1, s2, i, j + 1);
        return dp[i][j] = Math.min(take_i, take_j);
    }

    public int minimumDeleteSum(String s1, String s2) {
        m = s1.length();
        n = s2.length();
        dp = new int[m + 1][n + 1];
        for (int i = 0; i <= m; i++) {
            Arrays.fill(dp[i], -1);
        }
        return solve(s1, s2, 0, 0);
    }
}