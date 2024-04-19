class Solution:
    def dfs(self, grid: List[List[str]], i : int, j : int, row : int, col : int):
        if i < 0 or j < 0 or i >= row or j >= col or grid[i][j] == '0':
            return
        grid[i][j] = '0'
        self.dfs(grid, i+1, j, row, col)
        self.dfs(grid, i-1, j, row, col)
        self.dfs(grid, i, j+1, row, col)
        self.dfs(grid, i, j-1, row, col)

    def numIslands(self, grid: List[List[str]]) -> int:
        row, col, count = len(grid), len(grid[0]), 0
        for i in range(row):
            for j in range(col):
                if grid[i][j] == '1':
                    self.dfs(grid, i, j, row, col)
                    count += 1
        return count