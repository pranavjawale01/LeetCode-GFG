class Solution:
    def minFlips(self, grid: List[List[int]]) -> int:
        row = len(grid)
        col = len(grid[0])
        ans1 = 0
        ans2 = 0

        for i in range(row):
            for j in range(col // 2):
                if grid[i][j] != grid[i][col - 1 - j]:
                    ans1 += 1

        for j in range(col):
            for i in range(row // 2):
                if grid[i][j] != grid[row - 1 - i][j]:
                    ans2 += 1
    
        return min(ans1, ans2)