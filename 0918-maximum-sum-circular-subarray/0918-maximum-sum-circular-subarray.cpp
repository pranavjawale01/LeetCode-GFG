class Solution {
public:
    int kadaneAlgo(vector<int> &nums, int n) {
        int currSum = nums[0];
        int maxSum  = nums[0];
        for (int i = 1; i < n; i++) {
            currSum = max(currSum + nums[i], nums[i]);
            maxSum  = max(maxSum, currSum);
        }
        return maxSum;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int maxSum = kadaneAlgo(nums, n);
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            nums[i] = -nums[i];
        }
        int minSum = kadaneAlgo(nums, n);
        if (maxSum > 0) {
            return max(maxSum, sum + minSum);
        }
        return maxSum;
    }
};