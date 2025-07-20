class Solution:
    def maxMoves(self, grid: List[List[int]]) -> int:
        self.n, self.m = len(grid), len(grid[0])
        self.memo = [[-1] * self.m for _ in range(self.n)]

        def solve(i, j):
            if i < 0 or j < 0 or i >= self.n or j >= self.m:
                return 0
            if self.memo[i][j] != -1:
                return self.memo[i][j]
            
            up = down = fwd = 0
            if i - 1 >= 0 and j + 1 < self.m and grid[i][j] < grid[i - 1][j + 1]:
                up = 1 + solve(i - 1, j + 1)
            if j + 1 < self.m and grid[i][j] < grid[i][j + 1]:
                fwd = 1 + solve(i, j + 1)
            if i + 1 < self.n and j + 1 < self.m and grid[i][j] < grid[i + 1][j + 1]:
                down = 1 + solve(i + 1, j + 1)
            
            self.memo[i][j] = max(up, fwd, down)
            return self.memo[i][j]

        ans = 0
        for i in range(self.n):
            ans = max(ans, solve(i, 0))
        return ans