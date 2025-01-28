class Solution:
    def __init__(self):
        self.dirs = [(-1, 0), (1, 0), (0, -1), (0, 1)]
    
    def bfs(self, i, j, grid):
        queue = deque([(i, j)])
        fish_count = grid[i][j]
        grid[i][j] = 0

        while queue:
            x, y = queue.popleft()
            for dx, dy in self.dirs:
                nx, ny = x + dx, y + dy
                if 0 <= nx < len(grid) and 0 <= ny < len(grid[0]) and grid[nx][ny] > 0:
                    queue.append((nx, ny))
                    fish_count += grid[nx][ny]
                    grid[nx][ny] = 0
        return fish_count
    
    def findMaxFish(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        max_fish = 0

        for i in range(m):
            for j in range(n):
                if grid[i][j] > 0:
                    max_fish = max(max_fish, self.bfs(i, j, grid))
        
        return max_fish        