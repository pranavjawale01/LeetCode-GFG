class Solution:
    def __init__(self):
        self.row = 0
        self.col = 0

    def bfs(self, grid: List[List[int]], i: int, j: int) -> int:
        q = deque()
        grid[i][j] = 0
        q.append([i, j])
        area = 1
        while q:
            x, y = q.popleft()
            for dx, dy in [(1, 0), (-1, 0), (0, 1), (0, -1)]:
                nx, ny = x + dx, y + dy
                if 0 <= nx < self.row and 0 <= ny < self.col and grid[nx][ny] == 1:
                    grid[nx][ny] = 0
                    area += 1
                    q.append([nx, ny])
        return area


    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        self.row = len(grid)
        self.col = len(grid[0])
        ans = 0
        for i in range(self.row):
            for j in range(self.col):
                if grid[i][j] == 1:
                    ans = max(ans, self.bfs(grid, i, j))
        return ans



# class Solution:
#     def __init__(self):
#         self.row = 0
#         self.col = 0

#     def dfs(self, grid: List[List[int]], i: int, j: int) -> int:
#         if i < 0 or j < 0 or i >= self.row or j >= self.col or grid[i][j] == 0:
#             return 0
#         grid[i][j] = 0
#         return 1 + self.dfs(grid, i+1, j) + self.dfs(grid, i-1, j) + self.dfs(grid, i, j+1) + self.dfs(grid, i, j-1)

#     def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
#         self.row = len(grid)
#         self.col = len(grid[0])
#         ans = 0
#         for i in range(self.row):
#             for j in range(self.col):
#                 if grid[i][j] == 1:
#                     ans = max(ans, self.dfs(grid, i, j))
#         return ans