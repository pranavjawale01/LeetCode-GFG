class Solution {
    public int[] resultsArray(int[] nums, int k) {
        int n = nums.length;
        int[] dp = new int[n];
        int[] ans = new int[n - k + 1];
        Arrays.fill(dp, 1);
        Arrays.fill(ans, -1);
        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i-1] + 1) {
                dp[i] = 1 + dp[i-1];
            }
        }
        for (int i = k - 1, j = 0; i < n; i++, j++) {
            if (dp[i] >= k) {
                ans[j] = nums[i];
            }
        }
        return ans;
    }
}