class Solution {
    private int n;
    private long[][] dp;

    private long solve(int[] nums, int idx, boolean pos) {
        if (idx >= n) return 0;

        if (dp[idx][pos ? 1 : 0] != -1) return dp[idx][pos ? 1 : 0];

        if (pos) {
            dp[idx][1] = nums[idx] + solve(nums, idx + 1, false);
            return dp[idx][1];
        } else {
            long take = solve(nums, idx + 1, true) - nums[idx];
            long notTake = solve(nums, idx + 1, false) + nums[idx];
            dp[idx][0] = Math.max(take, notTake);
            return dp[idx][0];
        }
    }

    public long maximumTotalCost(int[] nums) {
        n = nums.length;
        dp = new long[n][2];
        for (int i = 0; i < n; i++) {
            Arrays.fill(dp[i], -1);
        }
        return solve(nums, 0, true);
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        int[] nums = {1, 2, 3, 4, 5};
        System.out.println(sol.maximumTotalCost(nums)); 
    }
}