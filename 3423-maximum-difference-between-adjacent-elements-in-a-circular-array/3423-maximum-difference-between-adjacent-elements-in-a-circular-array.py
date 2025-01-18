class Solution:
    def maxAdjacentDistance(self, nums: List[int]) -> int:
        ans = abs(nums[0] - nums[-1])
        n = len(nums)
        for i in range(n - 1):
            ans = max(ans, abs(nums[i] - nums[i + 1]))
        return ans