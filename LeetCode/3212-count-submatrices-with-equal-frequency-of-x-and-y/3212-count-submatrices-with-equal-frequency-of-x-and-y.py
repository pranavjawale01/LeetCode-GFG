class Solution:
    def numberOfSubmatrices(self, grid: List[List[str]]) -> int:
        row, col = len(grid), len(grid[0])

        x = [[0 for _ in range(col)] for _ in range(row)]
        y = [[0 for _ in range(col)] for _ in range(row)]

        for i in range(row):
            for j in range(col):
                if grid[i][j] == 'X':
                    x[i][j] = 1
                if grid[i][j] == 'Y':
                    y[i][j] = 1
            
        for i in range(row):
            for j in range(1, col):
                x[i][j] += x[i][j-1]
                y[i][j] += y[i][j-1]
        
        for j in range(col):
            for i in range(1, row):
                x[i][j] += x[i-1][j]
                y[i][j] += y[i-1][j]
        
        ans = 0

        for i in range(row):
            for j in range(col):
                if x[i][j] == y[i][j] and x[i][j] > 0:
                    ans += 1
        
        return ans