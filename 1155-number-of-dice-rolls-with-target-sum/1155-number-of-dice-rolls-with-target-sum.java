class Solution {
    public int numRollsToTarget(int n, int k, int target) {
        int MOD = 1000000007;
        int[][] dp = new int[n + 1][target + 1];
        dp[0][0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= target; j++) {
                for (int faces = 1; faces <= k; faces++) {
                    if (j - faces >= 0) {
                        dp[i][j] = (dp[i][j] + dp[i - 1][j - faces]) % MOD;
                    }
                }
            }
        }
        return dp[n][target];
    }
}