class Solution {
    private int n;
    private int[][] dp;
    private int solve(int l, int r, String s) {
        if (l == r) {
            return 1;
        }
        if (l > r) {
            return 0;
        }
        if (dp[l][r] != -1) {
            return dp[l][r];
        }
        int i = l + 1;
        while (i <= r && s.charAt(i) == s.charAt(l)) {
            i++;
        }
        if (i == r + 1) {
            return 1;
        }
        int basic = 1 + solve(i, r, s);
        int greedy = Integer.MAX_VALUE;
        for (int j = i; j <= r; j++) {
            if (s.charAt(j) == s.charAt(l)) {
                int ans = solve(i, j-1, s) + solve(j, r, s);
                greedy = Math.min(greedy, ans);
            }
        }
        return dp[l][r] = Math.min(greedy, basic);
    }
    public int strangePrinter(String s) {
        n = s.length();
        dp = new int[n+1][n+1];
        for (int i = 0; i <= n; i++) {
            Arrays.fill(dp[i], -1);
        }
        return solve(0, n-1, s);
    }
}