class Solution:
    def findMaximumScore(self, nums: List[int]) -> int:
        res = 0
        n = len(nums)
        left = nums[0]
        j = 0
        for i in range(1, n-1):
            if nums[i] > nums[j]:
                res += left * (i - j)
                left = nums[i]
                j = i
        res += left * (n - 1 - j)
        return res