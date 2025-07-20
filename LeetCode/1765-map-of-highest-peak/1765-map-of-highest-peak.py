class Solution:
    def highestPeak(self, isWater: List[List[int]]) -> List[List[int]]:
        dirs = [(0, 1), (0, -1), (-1, 0), (1, 0)]
        m, n = len(isWater), len(isWater[0])
        height = [[-1] * n for _ in range(m)]
        q = deque()
        for i in range(m):
            for j in range(n):
                if isWater[i][j] == 1:
                    height[i][j] = 0
                    q.append((i, j))
        while q:
            i, j = q.popleft()
            for dx, dy in dirs:
                x, y = i + dx, j + dy
                if 0 <= x < m and 0 <= y < n and height[x][y] == -1:
                    height[x][y] = height[i][j] + 1
                    q.append((x, y))
        return height