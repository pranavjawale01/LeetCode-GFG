class Solution:
    def solve(self, i: int, j: int, m: int, n: int) -> int:
        if i == m - 1 and j == n - 1:
            return 1
        if i >= m or j >= n:
            return 0
        if self.dp[i][j] != -1:
            return self.dp[i][j]
        self.dp[i][j] = self.solve(i+1, j, m, n) + self.solve(i, j+1, m, n)
        return self.dp[i][j]

    def uniquePaths(self, m: int, n: int) -> int:
        self.dp = [[-1 for _ in range(n+1)] for _ in range(m+1)]
        return self.solve(0, 0, m, n)