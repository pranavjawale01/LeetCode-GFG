class Solution:
    def numSubarrayProductLessThanK(self, nums: List[int], k: int) -> int:
        n = len(nums)
        count = 0
        for i in range(n):
            mul = 1
            for j in range(i, n):
                if mul * nums[j] >= k:
                    break
                mul *= nums[j]
                count += 1
        return count