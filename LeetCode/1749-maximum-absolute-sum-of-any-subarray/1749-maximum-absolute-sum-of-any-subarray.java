class Solution {
    public int maxAbsoluteSum(int[] nums) {
        int n = nums.length;
        int maxsum = 0, minsum = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            maxsum = Math.max(nums[i], maxsum + nums[i]);
            minsum = Math.min(nums[i], minsum + nums[i]);
            ans = Math.max(ans, Math.max(Math.abs(maxsum), Math.abs(minsum)));
        }
        return ans;
    }
}