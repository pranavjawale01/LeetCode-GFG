class Solution:
    def __init__(self):
        self.row = 0
        self.col = 0

    def dfs(self, grid: List[List[int]], i: int, j: int):
        if i < 0 or j < 0 or i >= self.row or j >= self.col or grid[i][j] == 1:
            return
        grid[i][j] = 1 
        self.dfs(grid, i + 1, j)
        self.dfs(grid, i - 1, j)
        self.dfs(grid, i, j + 1)
        self.dfs(grid, i, j - 1)

    def closedIsland(self, grid: List[List[int]]) -> int:
        self.row = len(grid)
        self.col = len(grid[0])
        
        for i in range(self.row):
            for j in range(self.col):
                if (i == 0 or j == 0 or i == self.row - 1 or j == self.col - 1) and grid[i][j] == 0:
                    self.dfs(grid, i, j)
        
        count = 0
        for i in range(self.row):
            for j in range(self.col):
                if grid[i][j] == 0:
                    self.dfs(grid, i, j)
                    count += 1
        
        return count