class Solution {
    public int[] constructTransformedArray(int[] nums) {
        int n = nums.length;
        int[] ans = new int[n];

        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                ans[i] = nums[(i + Math.abs(nums[i])) % n];
            } else if (nums[i] < 0) {
                int j = i;
                int t = Math.abs(nums[i]);
                while (t-- > 0) {
                    j = (j <= 0) ? n - 1 : j - 1;
                }
                ans[i] = nums[j];
            } else {
                ans[i] = nums[i];
            }
        }
        return ans;
    }
}