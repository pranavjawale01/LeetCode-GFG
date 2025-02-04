class Solution {
    public int maxAscendingSum(int[] nums) {
        int ans = nums[0];
        int n = nums.length;
        int sum = nums[0];
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i-1]) {
                sum += nums[i];
                ans = Math.max(ans, sum);
            } else {
                sum = nums[i];
            }
        }
        return ans;
    }
}