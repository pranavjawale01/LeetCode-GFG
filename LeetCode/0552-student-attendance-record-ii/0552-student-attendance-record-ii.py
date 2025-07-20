class Solution:
    def checkRecord(self, n: int) -> int:
        M = 1000000007
        t = [[[0] * 3 for _ in range(2)] for _ in range(100001)]

        for A in range(2):
            for L in range(3):
                t[0][A][L] = 1

        for i in range(1, n + 1):
            for A in range(2):
                for L in range(3):
                    result = t[i - 1][A][0]
                    result += t[i - 1][A][L + 1] if L < 2 else 0
                    result += t[i - 1][A + 1][0] if A == 0 else 0
                    t[i][A][L] = result % M

        return t[n][0][0]


# class Solution:
#     def __init__(self):
#         self.dp = [[[-1] * 3 for _ in range(2)] for _ in range(100001)]
#         self.MOD = 1000000007

#     def solve(self, n: int, absent: int, late: int) -> int:
#         if absent >= 2 or late >= 3:
#             return 0
#         if n == 0:
#             return 1
#         if self.dp[n][absent][late] != -1:
#             return self.dp[n][absent][late]
#         A = self.solve(n-1, absent + 1, 0) % self.MOD
#         B = self.solve(n-1, absent, late + 1) % self.MOD
#         C = self.solve(n-1, absent, 0) % self.MOD
#         self.dp[n][absent][late] = ((A + B) % self.MOD + C) % self.MOD
#         return self.dp[n][absent][late]
                
#     def checkRecord(self, n: int) -> int:
#         return self.solve(n, 0, 0)