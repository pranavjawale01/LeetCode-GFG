class Solution:
    def shortestPathAllKeys(self, grid: List[str]) -> int:
        m, n = len(grid), len(grid[0])
        totalKeys = 0
        startx, starty = -1, -1

        for i in range(m):
            for j in range(n):
                cell = grid[i][j]
                if cell == '@':
                    startx, starty = i, j
                elif cell.islower():
                    totalKeys |= (1 << (ord(cell) - ord('a')))

        dirx = [0, 0, 1, -1]
        diry = [1, -1, 0, 0]

        q = deque([(startx, starty, 0)])
        vis = [[[False] * (1 << 6) for _ in range(n)] for _ in range(m)]
        vis[startx][starty][0] = True

        level = 0

        while q:
            size = len(q)
            for _ in range(size):
                x, y, keys = q.popleft()
                if keys == totalKeys:
                    return level
                for i in range(4):
                    newx, newy = x + dirx[i], y + diry[i]
                    if newx < 0 or newy < 0 or newx >= m or newy >= n:
                        continue
                    cell = grid[newx][newy]
                    if cell == '#':
                        continue
                    if cell.isupper() and not (keys & (1 << (ord(cell) - ord('A')))):
                        continue
                    newKeys = keys
                    if cell.islower():
                        newKeys |= (1 << (ord(cell) - ord('a')))
                    if not vis[newx][newy][newKeys]:
                        vis[newx][newy][newKeys] = True
                        q.append((newx, newy, newKeys))
            level += 1
        return -1