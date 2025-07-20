class Solution:
    def maxAbsoluteSum(self, nums: List[int]) -> int:
        n = len(nums)
        maxsum, minsum, ans = 0, 0, 0
        for i in range(n):
            maxsum = max(nums[i], maxsum + nums[i])
            minsum = min(nums[i], minsum + nums[i])
            ans = max(ans, max(abs(maxsum), abs(minsum)))
        return ans