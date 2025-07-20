class Solution {
    private int OR = 0;
    private int count = 0;
    private void solve(int i, int[] nums, int ans) {
        if (nums.length <= i) {
            if (ans == OR) {
                count++;
            }
            return;
        }
        solve(i+1, nums, ans | nums[i]);
        solve(i+1, nums, ans);
    }
    public int countMaxOrSubsets(int[] nums) {
        for (int x : nums) OR = OR | x;
        solve(0, nums, 0);
        return count;
    }
}