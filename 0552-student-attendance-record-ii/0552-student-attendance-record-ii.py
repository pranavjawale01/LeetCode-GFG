class Solution:
    def __init__(self):
        self.dp = [[[-1] * 3 for _ in range(2)] for _ in range(100001)]
        self.MOD = 1000000007

    def solve(self, n: int, absent: int, late: int) -> int:
        if absent >= 2 or late >= 3:
            return 0
        if n == 0:
            return 1
        if self.dp[n][absent][late] != -1:
            return self.dp[n][absent][late]
        A = self.solve(n-1, absent + 1, 0) % self.MOD
        B = self.solve(n-1, absent, late + 1) % self.MOD
        C = self.solve(n-1, absent, 0) % self.MOD
        self.dp[n][absent][late] = ((A + B) % self.MOD + C) % self.MOD
        return self.dp[n][absent][late]
                
    def checkRecord(self, n: int) -> int:
        return self.solve(n, 0, 0)