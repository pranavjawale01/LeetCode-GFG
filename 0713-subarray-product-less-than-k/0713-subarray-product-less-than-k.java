class Solution {
    public int numSubarrayProductLessThanK(int[] nums, int k) {
        int n = nums.length, count = 0;
        for (int i = 0; i < n; i++) {
            int mul = 1;
            for (int j = i; j < n; j++) {
                if (mul * nums[j] >= k) {
                    break;
                }
                mul *= nums[j];
                count++;
            }
        }
        return count;
    }
}