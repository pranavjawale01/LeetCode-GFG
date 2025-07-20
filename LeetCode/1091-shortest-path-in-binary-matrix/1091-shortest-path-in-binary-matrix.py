class Solution:
    def shortestPathBinaryMatrix(self, grid: List[List[int]]) -> int:
        n = len(grid)
        if grid[0][0] != 0 or grid[n-1][n-1] != 0:
            return -1
        q = deque()
        q.append((0, 0))
        level = 1
        grid[0][0] = 1
        directions = [(-1, -1), (-1, 0), (-1, 1), (0, -1), (0, 1), (1, -1), (1, 0), (1, 1)]
        
        while q:
            size = len(q)
            for _ in range(size):
                x, y = q.popleft()
                if x == n - 1 and y == n - 1:
                    return level
                for dx, dy in directions:
                    newx, newy = x + dx, y + dy
                    if 0 <= newx < n and 0 <= newy < n and grid[newx][newy] == 0:
                        q.append((newx, newy))
                        grid[newx][newy] = 1
            level += 1
        return -1