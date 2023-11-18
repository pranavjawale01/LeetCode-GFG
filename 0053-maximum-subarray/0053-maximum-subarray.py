class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        maxSum, currentSum = float('-inf'), 0
        
        for i in range(len(nums)):
            currentSum = max(nums[i], currentSum + nums[i])
            maxSum = max(currentSum , maxSum)
            
        return maxSum