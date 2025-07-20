class Solution:
    def subarraySum(self, nums: List[int]) -> int:
        ans = 0
        n = len(nums)
        for i in range(n):
            s = max(0, i - nums[i])
            for j in range(s, i + 1):
                ans += nums[j]
        return ans