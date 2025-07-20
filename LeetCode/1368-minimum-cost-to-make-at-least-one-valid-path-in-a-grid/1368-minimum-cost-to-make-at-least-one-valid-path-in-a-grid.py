class Solution:
    def minCost(self, grid: List[List[int]]) -> int:
        dirs = [(0, 1), (0, -1), (1, 0), (-1, 0)]
        m, n = len(grid), len(grid[0])
        pq = []
        heappush(pq, (0, 0, 0))
        res = [[float('inf')] * n for _ in range(m)]
        res[0][0] = 0
        
        while pq:
            currCost, i, j = heappop(pq)
            if res[i][j] < currCost:
                continue
            for dir, (dx, dy) in enumerate(dirs):
                x, y = i + dx, j + dy
                if 0 <= x < m and 0 <= y < n:
                    gridDir = grid[i][j]
                    dirCost = 1 if gridDir - 1 != dir else 0
                    newCost = currCost + dirCost
                    if newCost < res[x][y]:
                        res[x][y] = newCost
                        heappush(pq, (newCost, x, y))
        
        return res[m - 1][n - 1]