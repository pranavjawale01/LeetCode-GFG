class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        i = 0
        for j in range(len(nums)):
            if nums[j] != 0:
                nums[i], nums[j] = nums[j], nums[i]
                i += 1

# class Solution:
#     def moveZeroes(self, nums: List[int]) -> None:
#         """
#         Do not return anything, modify nums in-place instead.
#         """
#         k = 0
#         n = len(nums)
#         for i in range(n):
#             if nums[i] == 0:
#                 continue
#             else:
#                 nums[k] = nums[i]
#                 k += 1
#         for i in range(k, n):
#             nums[i] = 0