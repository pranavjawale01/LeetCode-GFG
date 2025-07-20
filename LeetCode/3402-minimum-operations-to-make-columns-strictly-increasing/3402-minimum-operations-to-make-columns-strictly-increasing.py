class Solution:
    def minimumOperations(self, grid: List[List[int]]) -> int:
        row = len(grid)
        col = len(grid[0])
        ans = 0
        
        for i in range(col):
            for j in range(1, row):
                if grid[j][i] <= grid[j-1][i]:
                    temp = abs(grid[j][i] - grid[j-1][i]) + 1
                    ans += temp
                    grid[j][i] += temp
        
        return ans