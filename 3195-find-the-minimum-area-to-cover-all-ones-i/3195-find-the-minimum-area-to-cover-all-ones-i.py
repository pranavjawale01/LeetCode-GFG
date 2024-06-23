class Solution:
    def minimumArea(self, grid: List[List[int]]) -> int:
        row, col = len(grid), len(grid[0])
        minRow, maxRow, minCol, maxCol = row, -1, col, -1

        for i in range(row):
            for j in range(col):
                if grid[i][j] == 1:
                    minRow = min(minRow, i)
                    minCol = min(minCol, j)
                    maxRow = max(maxRow, i)
                    maxCol = max(maxCol, j)
        if minRow == row or minCol == col or maxRow == -1 or maxCol == -1:
            return 0
        return (maxRow - minRow + 1) * (maxCol - minCol + 1)