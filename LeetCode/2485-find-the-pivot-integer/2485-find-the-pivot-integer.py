# 1. Mathematics + Binary Search

class Solution:
    def pivotInteger(self, n: int) -> int:
        totalSum = n  * (n + 1) / 2
        left = 1
        right = n
        while left <= right:
            mid_pivot = left + (right - left) // 2
            if mid_pivot * mid_pivot == totalSum:
                return mid_pivot
            elif mid_pivot * mid_pivot > totalSum:
                right = mid_pivot - 1
            else:
                left = mid_pivot + 1
        return -1

# # 2. Mathematics

# class Solution:
#     def pivotInteger(self, n: int) -> int:
#         totalSum = n * (n + 1) // 2
#         i = int(sqrt(totalSum))
#         if i * i == totalSum:
#             return i
#         return -1

# # 3. Two Pointer

# class Solution:
#     def pivotInteger(self, n: int) -> int:
#         lSum , rSum  = 1, n
#         left , right = 1 , n
#         while left < right:
#             if lSum == rSum:
#                 right -= 1
#                 left += 1
#                 lSum += left
#                 rSum += right
#             elif rSum > lSum:
#                 left += 1
#                 lSum += left
#             else:
#                 right -= 1
#                 rSum += right
#         if lSum == rSum:
#             return left
#         return -1

# 4. Brute Force Optimized

# class Solution:
#     def pivotInteger(self, n: int) -> int:
#         lSum , rSum , totalSum = 0, 0 , n * (n + 1) // 2
#         for i in range(1, n+1):
#             lSum = i * (i + 1) // 2
#             rSum = totalSum - lSum + i
#             if rSum == lSum:
#                 return i
#         return -1

# 5.Brute Force

# class Solution:
#     def pivotInteger(self, n: int) -> int:
#         lSum , rSum = 0, 0
#         for i in range(1, n+1):
#             lSum += i
#             for j in range(i, n+1):
#                 rSum += j
#             if rSum == lSum:
#                 return i
#             rSum = 0
#         return -1