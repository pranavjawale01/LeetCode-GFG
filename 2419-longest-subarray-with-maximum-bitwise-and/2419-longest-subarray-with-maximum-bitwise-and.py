class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        maxEl = max(nums)
        n = len(nums)
        ans = 0
        count = 0
        for i in range(n):
            if nums[i] == maxEl:
                count += 1
                ans = max(ans, count)
            else:
                count = 0
        return ans