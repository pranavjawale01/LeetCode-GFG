class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        n = len(nums)
        dp = [1] * n
        maxL = 1
        for i in range(0, n):
            for j in range(0, i):
                if nums[j] < nums[i]:
                    dp[i] = max(dp[i], dp[j] + 1)
                    maxL = max(maxL, dp[i])
        return maxL



# TLE
# class Solution:
#     def __init__(self):
#         self.n = 0
#         self.dp = [[-1 for _ in range(2501)] for _ in range(2501)]

#     def solve(self, nums: List[int], i: int, p: int) -> int:
#         if i >= self.n:
#             return 0
#         if p != -1 and self.dp[i][p] != -1:
#             return self.dp[i][p]
#         take = 0
#         if p == -1 or nums[i] > nums[p]:
#             take = 1 + self.solve(nums, i+1, i)
#         skip = self.solve(nums, i+1, p)
#         if p != -1:
#             self.dp[i][p] = max(take, skip)
#         return max(take, skip)

#     def lengthOfLIS(self, nums: List[int]) -> int:
#         self.n = len(nums)
#         return self.solve(nums, 0, -1)



# class Solution:
#     def lengthOfLIS(self, nums: List[int]) -> int:
#         size = 0
#         for x in nums:
#             i , j = 0 , size
#             while i != j:
#                 n = (i + j) // 2
#                 if nums[n] < x:
#                     i = n + 1
#                 else:
#                     j = n
#             nums[i] = x
#             if i == size:
#                 size += 1
#         return size