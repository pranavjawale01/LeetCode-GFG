class Solution {
    public int longestSubarray(int[] nums) {
        int maxEl = Arrays.stream(nums).max().getAsInt();
        int ans = 0;
        int n = nums.length;
        for (int i = 0; i < n; i++) {
            if (nums[i] == maxEl) {
                int temp = 0;
                while (i < n && nums[i] == maxEl) {
                    temp++;
                    i++;
                }
                ans = Math.max(ans, temp);
            }
        }
        return ans;
    }
}