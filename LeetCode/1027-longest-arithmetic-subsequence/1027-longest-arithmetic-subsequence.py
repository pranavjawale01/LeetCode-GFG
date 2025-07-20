class Solution:
    def longestArithSeqLength(self, nums: List[int]) -> int:
        n = len(nums)
        if n <= 2:
            return n
        dp = [[-1 for _ in range(1001)] for _ in range(n)]
        ans = 0
        for i in range(1, n):
            for j in range(i):
                diff = nums[i] - nums[j] + 500
                dp[i][diff] = dp[j][diff] + 1 if dp[j][diff] > 0 else 2
                ans = max(ans, dp[i][diff])
        return ans


# TLE
# class Solution:
#     def __init__(self):
#         self.n = 0
#         self.dp = [[-1 for _ in range(1003)] for _ in range(1001)]

#     def solve(self, nums: List[int], i: int, diff: int) -> int:
#         if i < 0:
#             return 0
#         if self.dp[i][diff + 501] != -1:
#             return self.dp[i][diff + 501]
#         ans = 0
#         for k in range(i-1, -1, -1):
#             if nums[i] - nums[k] == diff:
#                 ans = max(ans, 1 + self.solve(nums, k, diff))
#         self.dp[i][diff + 501] = ans
#         return ans

#     def longestArithSeqLength(self, nums: List[int]) -> int:
#         self.n = len(nums)
#         if self.n <= 2:
#             return n
#         ans = 0
#         for i in range(self.n):
#             for j in range(i+1, self.n):
#                 ans = max(ans, 2 + self.solve(nums, i, nums[j] - nums[i]))
#         return ans