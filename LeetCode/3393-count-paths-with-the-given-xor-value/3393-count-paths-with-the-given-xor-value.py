class Solution:
    MOD = 10**9 + 7

    def __init__(self):
        self.dp = []

    def solve(self, grid, i, j, x, k):
        n, m = len(grid), len(grid[0])
        if i >= n or j >= m:
            return 0
        x ^= grid[i][j]
        if self.dp[i][j][x] != -1:
            return self.dp[i][j][x]

        ans = 0
        if i == n - 1 and j == m - 1 and x == k:
            ans = 1
        ans = (ans + self.solve(grid, i + 1, j, x, k)) % self.MOD
        ans = (ans + self.solve(grid, i, j + 1, x, k)) % self.MOD

        self.dp[i][j][x] = ans
        return ans

    def countPathsWithXorValue(self, grid: List[List[int]], k: int) -> int:
        n, m = len(grid), len(grid[0])
        self.dp = [[[-1] * 16 for _ in range(m)] for _ in range(n)]
        return self.solve(grid, 0, 0, 0, k)        