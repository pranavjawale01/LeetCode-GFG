class Solution {
    public int[] getMaximumXor(int[] nums, int maximumBit) {
        int n = nums.length;
        int maxVal = (1 << maximumBit) - 1;
        int xorAll = 0;
        for (int x : nums) xorAll ^= x;
        int[] ans = new int[n];
        for (int i = 0; i < n; i++) {
            ans[i] = maxVal ^ xorAll;
            xorAll ^= nums[n - 1 - i];
        }
        return ans;
    }
}