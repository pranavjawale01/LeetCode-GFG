class Solution {
    public int kadaneAlgorithm(int[] nums, int n) {
        int currSum = nums[0];
        int maxSum = nums[0];
        for (int i = 1; i < n; i++) {
            currSum = Math.max(currSum + nums[i], nums[i]);
            maxSum = Math.max(maxSum, currSum);
        }
        return maxSum;
    }
    public int maxSubarraySumCircular(int[] nums) {
        int n = nums.length;
        int maxSum = kadaneAlgorithm(nums, n);
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            nums[i] = -nums[i];
        }
        int minSum = kadaneAlgorithm(nums, n);
        if (maxSum > 0) {
            return Math.max(maxSum, sum + minSum);
        }
        return maxSum;
    }
}