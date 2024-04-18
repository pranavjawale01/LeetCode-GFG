from typing import List

class Solution:
    def solve(self, grid: List[List[int]], i: int, j: int, row: int, col: int):
        if i < 0 or i >= row or j < 0 or j >= col or grid[i][j] == 0:
            self.peri += 1
            return
        if grid[i][j] == -1:
            return
        grid[i][j] = -1
        self.solve(grid, i+1, j, row, col)
        self.solve(grid, i-1, j, row, col)
        self.solve(grid, i, j+1, row, col)
        self.solve(grid, i, j-1, row, col)

    def islandPerimeter(self, grid: List[List[int]]) -> int:
        row, col, self.peri = len(grid), len(grid[0]), 0
        for i in range(row):
            for j in range(col):
                if grid[i][j] == 1:
                    self.solve(grid, i, j, row, col)
                    return self.peri
        return 0