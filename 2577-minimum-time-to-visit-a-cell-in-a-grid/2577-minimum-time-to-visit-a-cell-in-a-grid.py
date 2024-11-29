class Solution:
    def minimumTime(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        if grid[0][1] > 1 and grid[1][0] > 1:
            return -1

        vis = [[False] * n for _ in range(m)]
        dirs = [(1, 0), (-1, 0), (0, 1), (0, -1)]
        pq = []
        heapq.heappush(pq, (grid[0][0], 0, 0))  # Min-Heap: (time, row, col)

        while pq:
            time, i, j = heapq.heappop(pq)
            if i == m - 1 and j == n - 1:
                return time
            if vis[i][j]:
                continue
            vis[i][j] = True

            for dr, dc in dirs:
                r, c = i + dr, j + dc
                if r < 0 or r >= m or c < 0 or c >= n or vis[r][c]:
                    continue
                if grid[r][c] <= time + 1:
                    heapq.heappush(pq, (time + 1, r, c))
                elif (grid[r][c] - time) % 2 == 0:
                    heapq.heappush(pq, (grid[r][c] + 1, r, c))
                else:
                    heapq.heappush(pq, (grid[r][c], r, c))

        return -1