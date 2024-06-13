class Solution:
    def dfs(self, grid: List[List[int]], i: int, j: int):
        if i < 0 or j < 0 or i == len(grid) or j == len(grid[0]) or grid[i][j] != 1:
            return 
        grid[i][j] = 0
        self.dfs(grid, i+1, j)
        self.dfs(grid, i-1, j)
        self.dfs(grid, i, j+1)
        self.dfs(grid, i, j-1)

    def numEnclaves(self, grid: List[List[int]]) -> int:
        row, col = len(grid), len(grid[0])
        for i in range(row):
            for j in range(col):
                if i == 0 or j == 0 or i == row - 1 or j == col - 1:
                    if grid[i][j] == 1:
                        self.dfs(grid, i, j)
        count = 0
        for i in range(row):
            for j in range(col):
                if grid[i][j] == 1:
                    count += 1
        return count