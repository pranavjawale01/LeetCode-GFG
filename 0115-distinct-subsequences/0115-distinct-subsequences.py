class Solution:
    def numDistinct(self, s: str, t: str) -> int:
        m, n = len(s), len(t)
        dp = [[0.0] * (n + 1) for _ in range(m + 1)]

        for i in range(m + 1):
            dp[i][0] = 1.0

        for i in range(1, m + 1):
            for j in range(1, n + 1):
                if s[i - 1] == t[j - 1]:
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j]
                else:
                    dp[i][j] = dp[i - 1][j]

        return int(dp[m][n])



# class Solution:
#     def __init__(self):
#         self.m = 0
#         self.n = 0
#         self.dp = [[-1 for _ in range(1001)] for _ in range(1001)]

#     def solve(self, s: str, t: str, i: int, j: int) -> int:
#         if j == self.n:
#             return 1
#         if i == self.m:
#             return 0
#         if self.dp[i][j] != -1:
#             return self.dp[i][j]
#         if s[i] == t[j]:
#             self.dp[i][j] = self.solve(s, t, i+1, j+1) + self.solve(s, t, i+1, j)
#         else:
#             self.dp[i][j] = self.solve(s, t, i+1, j)
#         return self.dp[i][j]

#     def numDistinct(self, s: str, t: str) -> int:
#         self.m = len(s)
#         self.n = len(t)
#         return self.solve(s, t, 0, 0)