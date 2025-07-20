class Solution {
    public int findTargetSumWays(int[] nums, int target) {
        int n = nums.length;
        int sum = Arrays.stream(nums).sum();
        int[][] dp = new int[n + 1][2 * sum + 1];
        for (int[] row : dp) Arrays.fill(row, -1);
        return solve(nums, target, 0, 0, dp, sum);
    }

    private int solve(int[] nums, int target, int i, int currSum, int[][] dp, int offset) {
        if (i == nums.length) {
            return currSum == target ? 1 : 0;
        }
        if (dp[i][currSum + offset] != -1) return dp[i][currSum + offset];
        int plus = solve(nums, target, i + 1, currSum + nums[i], dp, offset);
        int minus = solve(nums, target, i + 1, currSum - nums[i], dp, offset);
        dp[i][currSum + offset] = plus + minus;
        return dp[i][currSum + offset];
    }
}