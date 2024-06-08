class Solution:
    def __init__(self):
        self.m = 0
        self.n = 0
        self.dp = [[-1 for _ in range(1001)] for _ in range(1001)]

    def solve(self, s1: str, s2: str, i: int, j: int) -> int:
        if i >= self.m and j >= self.n:
            return 0
        if i >= self.m:
            self.dp[i][j] = ord(s2[j]) + self.solve(s1, s2, i, j+1)
            return self.dp[i][j]
        if j >= self.n:
            self.dp[i][j] = ord(s1[i]) + self.solve(s1, s2, i+1, j)
            return self.dp[i][j]
        if self.dp[i][j] != -1:
            return self.dp[i][j]
        if s1[i] == s2[j]:
            self.dp[i][j] = self.solve(s1, s2, i+1, j+1)
            return self.dp[i][j]
        take_i = ord(s1[i]) + self.solve(s1, s2, i+1, j)
        take_j = ord(s2[j]) + self.solve(s1, s2, i, j+1)
        self.dp[i][j] = min(take_i, take_j)
        return self.dp[i][j]

    def minimumDeleteSum(self, s1: str, s2: str) -> int:
        self.m = len(s1)
        self.n = len(s2)
        return self.solve(s1, s2, 0, 0)