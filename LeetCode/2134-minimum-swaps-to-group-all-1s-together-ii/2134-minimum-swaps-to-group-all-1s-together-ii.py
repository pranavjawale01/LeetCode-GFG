class Solution:
    def minSwaps(self, nums: List[int]) -> int:
        n = len(nums)
        totalOnes = sum(nums)
        i = 0
        j = 0
        currOnes = 0
        maxCount = 0
        while j < 2 * n:
            if nums[j%n] == 1:
                currOnes += 1
            if j - i + 1 > totalOnes:
                currOnes -= nums[i%n]
                i += 1
            maxCount = max(maxCount, currOnes)
            j += 1
        return totalOnes - maxCount






# class Solution:
#     def minSwaps(self, nums: List[int]) -> int:
#         n = len(nums)
#         temp = nums * 2
#         totalOnes = sum(nums)
#         i = 0
#         j = 0
#         currOnes = 0
#         maxCount = 0
#         while j < 2 * n:
#             if temp[j] == 1:
#                 currOnes += 1
#             if j - i + 1 > totalOnes:
#                 currOnes -= temp[i]
#                 i += 1
#             maxCount = max(maxCount, currOnes)
#             j += 1
#         return totalOnes - maxCount