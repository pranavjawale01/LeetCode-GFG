class Solution:
    def solve(self, s: str, i: int, j: int) -> int:
        if i > j:
            return 0
        if self.dp[i][j] != -1:
            return self.dp[i][j]
        if s[i] == s[j]:
            self.dp[i][j] = self.solve(s, i+1, j-1)
            return self.dp[i][j]
        self.dp[i][j] = 1 + min(self.solve(s, i+1, j), self.solve(s, i, j-1))
        return self.dp[i][j]

    def minInsertions(self, s: str) -> int:
        self.n = len(s)
        self.dp = [[-1 for _ in range(self.n)] for _ in range(self.n)]
        return self.solve(s, 0, self.n-1)