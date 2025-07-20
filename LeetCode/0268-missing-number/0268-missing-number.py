class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        n = len(nums)
        result = n
        for i in range(n):
            result ^= i
            result ^= nums[i]
        return result