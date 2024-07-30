class Solution {
    private int[] memo = new int[101];
    private int solve(int i, int j, int[] nums) {
        if (i >= j) {
            return 0;
        }
        if (memo[i] != -1) {
            return memo[i];
        }
        int take = nums[i] + solve(i+2, j, nums);
        int skip = solve(i+1, j, nums);
        return memo[i] = Math.max(take, skip);
    }
    public int rob(int[] nums) {
        int n = nums.length;
        if (n == 1) {
            return nums[0];
        }
        if (n == 2) {
            return Math.max(nums[0], nums[1]);
        }
        Arrays.fill(memo, -1);
        int takeZero = solve(0, n-1, nums);
        Arrays.fill(memo, -1);
        int takeOne  = solve(1, n, nums);
        return Math.max(takeZero, takeOne);
    }
}