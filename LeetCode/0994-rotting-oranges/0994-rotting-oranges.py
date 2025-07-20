class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        dirs = [(-1, 0), (0, -1), (1, 0), (0, 1)]
        q = deque()
        n, m = len(grid), len(grid[0])
        total = 0

        for i in range(n):
            for j in range(m):
                if grid[i][j] == 2:
                    q.append((i, j))
                if grid[i][j] != 0:
                    total += 1

        count = 0
        days = 0

        while q:
            k = len(q)
            count += k

            for _ in range(k):
                x, y = q.popleft()

                for dx, dy in dirs:
                    nx, ny = x + dx, y + dy

                    if 0 <= nx < n and 0 <= ny < m and grid[nx][ny] == 1:
                        grid[nx][ny] = 2
                        q.append((nx, ny))

            if q:
                days += 1

        return days if count == total else -1