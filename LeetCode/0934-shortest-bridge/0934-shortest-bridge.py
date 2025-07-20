class Solution:
    def dfs(self, grid: List[List[int]], i: int, j: int, q: deque):
        n = len(grid)
        if i < 0 or j < 0 or i >= n or j >= n or grid[i][j] != 1:
            return
        grid[i][j] = 2
        q.append((i, j))
        self.dfs(grid, i + 1, j, q)
        self.dfs(grid, i - 1, j, q)
        self.dfs(grid, i, j + 1, q)
        self.dfs(grid, i, j - 1, q)

    def shortestBridge(self, grid: List[List[int]]) -> int:
        n = len(grid)
        q = deque()
        found = False
        
        for i in range(n):
            if found:
                break
            for j in range(n):
                if grid[i][j] == 1:
                    self.dfs(grid, i, j, q)
                    found = True
                    break
        
        dirs = [(1, 0), (-1, 0), (0, 1), (0, -1)]
        steps = 0
        
        while q:
            size = len(q)
            for _ in range(size):
                x, y = q.popleft()
                for dx, dy in dirs:
                    nx, ny = x + dx, y + dy
                    if 0 <= nx < n and 0 <= ny < n:
                        if grid[nx][ny] == 1:
                            return steps
                        if grid[nx][ny] == 0:
                            grid[nx][ny] = 2
                            q.append((nx, ny))
            steps += 1
        
        return -1