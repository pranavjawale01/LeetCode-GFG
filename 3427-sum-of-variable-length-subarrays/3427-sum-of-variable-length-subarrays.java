class Solution {
    public int subarraySum(int[] nums) {
        int ans = 0;
        int n = nums.length;
        for (int i = 0; i < n; i++) {
            int s = Math.max(0, i - nums[i]);
            for (int j = s; j <= i; j++) {
                ans += nums[j];
            }
        }
        return ans;
    }
}