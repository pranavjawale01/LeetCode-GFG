class Solution:
    def minInsertions(self, s: str) -> int:
        reversed_s = s[::-1]
        n = len(s)
        dp = [[0 for j in range(n+1)] for i in range(n+1)]
        
        for i in range(1, n+1):
            for j in range(1, n+1):
                if s[i-1] == reversed_s[j-1]:
                    dp[i][j] = dp[i-1][j-1] + 1
                else:
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1])
        return n - dp[n][n]



# class Solution:
#     def minInsertions(self, s: str) -> int:
#         n = len(s)
#         dp = [[0] * n for _ in range(n)]

#         for length in range(2, n + 1):
#             for i in range(n - length + 1):
#                 j = i + length - 1
#                 if s[i] == s[j]:
#                     dp[i][j] = dp[i + 1][j - 1]
#                 else:
#                     dp[i][j] = 1 + min(dp[i + 1][j], dp[i][j - 1])

#         return dp[0][n - 1]



# class Solution:
#     def solve(self, s: str, i: int, j: int) -> int:
#         if i > j:
#             return 0
#         if self.dp[i][j] != -1:
#             return self.dp[i][j]
#         if s[i] == s[j]:
#             self.dp[i][j] = self.solve(s, i+1, j-1)
#             return self.dp[i][j]
#         self.dp[i][j] = 1 + min(self.solve(s, i+1, j), self.solve(s, i, j-1))
#         return self.dp[i][j]

#     def minInsertions(self, s: str) -> int:
#         self.n = len(s)
#         self.dp = [[-1 for _ in range(self.n)] for _ in range(self.n)]
#         return self.solve(s, 0, self.n-1)