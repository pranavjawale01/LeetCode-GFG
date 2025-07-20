class Solution {
    public int minOperations(int[] nums, int k) {
        int ans = nums[0];
        int n = nums.length;
        for (int i = 1; i < n; i++) {
            ans ^= nums[i];
        }
        int count = ans ^ k;
        return Integer.bitCount(count);
    }
}