class Solution:
    def __init__(self):
        self.dp = [[-1] * 201 for _ in range(201)]

    def solve(self, grid, n, level, col):
        if level == n - 1:
            self.dp[level][col] = grid[level][col]
            return self.dp[level][col]
        
        if self.dp[level][col] != -1:
            return self.dp[level][col]
        
        ans = float('inf')
        for j in range(n):
            if col == j:
                continue
            ans = min(ans, grid[level][col] + self.solve(grid, n, level + 1, j))
        
        self.dp[level][col] = ans
        return self.dp[level][col]

    def minFallingPathSum(self, grid: List[List[int]]) -> int:
        n = len(grid)
        ans = float('inf')
        for j in range(n):
            ans = min(ans, self.solve(grid, n, 0, j))
        return ans