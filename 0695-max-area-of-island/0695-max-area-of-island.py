class Solution:
    def __init__(self):
        self.row = 0
        self.col = 0

    def dfs(self, grid: List[List[int]], i: int, j: int) -> int:
        if i < 0 or j < 0 or i >= self.row or j >= self.col or grid[i][j] == 0:
            return 0
        grid[i][j] = 0
        return 1 + self.dfs(grid, i+1, j) + self.dfs(grid, i-1, j) + self.dfs(grid, i, j+1) + self.dfs(grid, i, j-1)

    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        self.row = len(grid)
        self.col = len(grid[0])
        ans = 0
        for i in range(self.row):
            for j in range(self.col):
                if grid[i][j] == 1:
                    ans = max(ans, self.dfs(grid, i, j))
        return ans