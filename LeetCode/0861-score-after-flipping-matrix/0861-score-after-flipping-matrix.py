class Solution:
    def matrixScore(self, grid: List[List[int]]) -> int:
        n = len(grid)
        m = len(grid[0])

        for i in range(n):
            if grid[i][0] == 0:
                for j in range(m):
                    grid[i][j] ^= 1

        for j in range(1, m):
            colCount = sum(grid[i][j] for i in range(n))
            if colCount < n - colCount:
                for i in range(n):
                    grid[i][j] ^= 1

        ans = 0
        for i in range(n):
            for j in range(m):
                ans += grid[i][j] * (1 << (m - 1 - j))

        return ans