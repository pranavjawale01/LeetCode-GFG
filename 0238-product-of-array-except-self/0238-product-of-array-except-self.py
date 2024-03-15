class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        left, right = [1] * n, [1] * n
        for i in range(1, n):
            left[i] = left[i-1]*nums[i-1]
            right[n-i-1] = right[n-i]*nums[n-i]
        for i in range(n):
            nums[i] = left[i] * right[i]
        return nums
        
# class Solution:
#     def productExceptSelf(self, nums: List[int]) -> List[int]:
#         n = len(nums)
#         zeroCount, productWithoutZero = 0, 1
#         for num in nums:
#             if num == 0:
#                 zeroCount += 1
#             else:
#                 productWithoutZero *= num
#         for i in range(n):
#             if (nums[i] != 0):
#                 if zeroCount > 0:
#                     nums[i] = 0
#                 else:
#                     nums[i] = productWithoutZero // nums[i]
#             else:
#                 if zeroCount > 1:
#                     nums[i] = 0
#                 else:
#                     nums[i] = productWithoutZero
#         return nums

# Brute Force        
# class Solution:
#     def productExceptSelf(self, nums: List[int]) -> List[int]:
#         n = len(nums)
#         temp = [1] * n
#         for i in range(n):
#             for j in range(n):
#                 if i != j:
#                     temp[i] *= nums[j]
#         return temp