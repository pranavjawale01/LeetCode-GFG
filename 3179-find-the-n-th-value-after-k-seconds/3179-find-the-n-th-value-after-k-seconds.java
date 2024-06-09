class Solution {
    public int valueAfterKSeconds(int n, int k) {
        int[] ans = new int[n];
        int MOD = 1000000007;
        Arrays.fill(ans, 1);
        for (int j = 0; j < k; j++) {
            int[] dp = new int[n];
            dp[0] = ans[0];
            for (int i = 1; i < n; i++) {
                dp[i] = (dp[i-1] + ans[i]) % MOD;
            }
            ans = dp;
        }
        return ans[n-1];
    }
}