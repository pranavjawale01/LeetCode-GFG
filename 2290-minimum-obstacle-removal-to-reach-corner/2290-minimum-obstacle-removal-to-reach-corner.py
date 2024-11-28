class Solution:
    def minimumObstacles(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        ans = [[float('inf')] * n for _ in range(m)]
        ans[0][0] = 0
        pq = [(0, 0, 0)]
        dirs = [(0, 1), (0, -1), (1, 0), (-1, 0)]
        
        while pq:
            wt, i, j = heapq.heappop(pq)
            for dx, dy in dirs:
                x, y = i + dx, j + dy
                if 0 <= x < m and 0 <= y < n:
                    cost = 1 if grid[x][y] == 1 else 0
                    if wt + cost < ans[x][y]:
                        ans[x][y] = wt + cost
                        heapq.heappush(pq, (wt + cost, x, y))
        
        return ans[m - 1][n - 1]