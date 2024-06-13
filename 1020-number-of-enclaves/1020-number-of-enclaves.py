class Solution:
    def bfs(self, grid: List[List[int]], i: int, j: int):
        q = deque()
        q.append((i, j))
        grid[i][j] = 0
        directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]
        
        while q:
            x, y = q.popleft()
            for d in directions:
                nx, ny = x + d[0], y + d[1]
                if 0 <= nx < len(grid) and 0 <= ny < len(grid[0]) and grid[nx][ny] == 1:
                    grid[nx][ny] = 0
                    q.append((nx, ny))

    def numEnclaves(self, grid: List[List[int]]) -> int:
        row, col = len(grid), len(grid[0])
        for i in range(row):
            for j in range(col):
                if i == 0 or j == 0 or i == row - 1 or j == col - 1:
                    if grid[i][j] == 1:
                        self.bfs(grid, i, j)
        count = 0
        for i in range(row):
            for j in range(col):
                if grid[i][j] == 1:
                    count += 1
        return count


# class Solution:
#     def dfs(self, grid: List[List[int]], i: int, j: int):
#         if i < 0 or j < 0 or i == len(grid) or j == len(grid[0]) or grid[i][j] != 1:
#             return 
#         grid[i][j] = 0
#         self.dfs(grid, i+1, j)
#         self.dfs(grid, i-1, j)
#         self.dfs(grid, i, j+1)
#         self.dfs(grid, i, j-1)

#     def numEnclaves(self, grid: List[List[int]]) -> int:
#         row, col = len(grid), len(grid[0])
#         for i in range(row):
#             for j in range(col):
#                 if i == 0 or j == 0 or i == row - 1 or j == col - 1:
#                     if grid[i][j] == 1:
#                         self.dfs(grid, i, j)
#         count = 0
#         for i in range(row):
#             for j in range(col):
#                 if grid[i][j] == 1:
#                     count += 1
#         return count