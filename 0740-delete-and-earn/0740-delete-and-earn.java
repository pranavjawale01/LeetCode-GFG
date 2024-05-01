class Solution {
    public int deleteAndEarn(int[] nums) {
        int n = 10001;
        int[] count = new int[n];
        for (int num : nums) {
            count[num] += num;
        }
        int[] dp = new int[n];
        dp[1] = count[1];
        for (int i = 2; i < n; i++) {
            dp[i] = Math.max(count[i] + dp[i-2], dp[i-1]);
        }
        return dp[n-1];
    }
}