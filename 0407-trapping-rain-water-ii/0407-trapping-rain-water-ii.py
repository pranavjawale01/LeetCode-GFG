class Solution:
    def trapRainWater(self, heightMap: List[List[int]]) -> int:
        m, n = len(heightMap), len(heightMap[0])
        pq = []
        vis = [[False] * n for _ in range(m)]
        for i in range(m):
            heapq.heappush(pq, (heightMap[i][0], i, 0))
            vis[i][0] = True
            heapq.heappush(pq, (heightMap[i][n - 1], i, n - 1))
            vis[i][n - 1] = True
        for i in range(n):
            heapq.heappush(pq, (heightMap[0][i], 0, i))
            vis[0][i] = True
            heapq.heappush(pq, (heightMap[m - 1][i], m - 1, i))
            vis[m - 1][i] = True
        ans = 0
        dirs = [(0, 1), (1, 0), (0, -1), (-1, 0)]
        while pq:
            height, i, j = heapq.heappop(pq)
            for dx, dy in dirs:
                x, y = i + dx, j + dy
                if 0 <= x < m and 0 <= y < n and not vis[x][y]:
                    ans += max(0, height - heightMap[x][y])
                    heapq.heappush(pq, (max(height, heightMap[x][y]), x, y))
                    vis[x][y] = True
        return ans