class Solution:
    def canSortArray(self, nums: List[int]) -> bool:
        numOfSetBits = bin(nums[0]).count('1')
        maxOfSegment = nums[0]
        minOfSegment = nums[0]
        maxOfPrevSegment = float('-inf')

        for i in range(1, len(nums)):
            if bin(nums[i]).count('1') == numOfSetBits:
                maxOfSegment = max(maxOfSegment, nums[i])
                minOfSegment = min(minOfSegment, nums[i])
            else:
                if minOfSegment < maxOfPrevSegment:
                    return False
                maxOfPrevSegment = maxOfSegment
                maxOfSegment = nums[i]
                minOfSegment = nums[i]
                numOfSetBits = bin(nums[i]).count('1')
        
        return minOfSegment >= maxOfPrevSegment





# class Solution:
#     def canSortArray(self, nums: List[int]) -> bool:
#         n = len(nums)
#         swapped = True
#         for i in range(n):
#             swapped = False
#             for j in range(n - i - 1):
#                 if nums[j] <= nums[j + 1]:
#                     continue
#                 else:
#                     if bin(nums[j]).count('1') == bin(nums[j + 1]).count('1'):
#                         nums[j], nums[j + 1] = nums[j + 1], nums[j]
#                         swapped = True
#                     else:
#                         return False
#             if not swapped:
#                 break
#         return True