class Solution:
    def maxAscendingSum(self, nums: List[int]) -> int:
        ans = nums[0]
        sum_ = nums[0]
        for i in range(1, len(nums)):
            if nums[i] > nums[i-1]:
                sum_ += nums[i]
                ans = max(ans, sum_)
            else:
                sum_ = nums[i]
        return ans