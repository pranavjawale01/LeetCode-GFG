class Solution:
    def numSubarrayProductLessThanK(self, nums: List[int], k: int) -> int:
        if k <= 1:
            return 0
        i, j, mul, count, n = 0, 0, 1, 0, len(nums)
        while j < n:
            mul *= num[i]
            while mul >= k:
                mul /= nums[i]
                i += 1
            count += j - i + 1
            j += 1
        return count
        
# class Solution:
#     def numSubarrayProductLessThanK(self, nums: List[int], k: int) -> int:
#         n = len(nums)
#         count = 0
#         for i in range(n):
#             mul = 1
#             for j in range(i, n):
#                 if mul * nums[j] >= k:
#                     break
#                 mul *= nums[j]
#                 count += 1
#         return count