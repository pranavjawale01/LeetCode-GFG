class Solution:
    def islandPerimeter(self, grid: List[List[int]]) -> int:
        row = len(grid)
        col = len(grid[0])
        peri = 0
        for i in range(row):
            for j in range(col):
                if grid[i][j] == 1:
                    if j+1 == col or grid[i][j+1] == 0:
                        peri += 1
                    if j-1 < 0 or grid[i][j-1] == 0:
                        peri += 1
                    if i-1 < 0 or grid[i-1][j] == 0:
                        peri += 1
                    if i+1 == row or grid[i+1][j] == 0:
                        peri += 1
        return peri

# class Solution:
#     def bfs(self, grid: List[List[int]], i: int, j: int, row: int, col: int) -> int:
#         peri = 0
#         q = deque([(i, j)])
#         grid[i][j] = -1
#         dir = [(1, 0), (-1, 0), (0, 1), (0, -1)]
#         while q:
#             it = q.popleft()
#             for d in dir:
#                 i_ = it[0] + d[0]
#                 j_ = it[1] + d[1]
#                 if i_ < 0 or j_ < 0 or i_ >= row or j_ >= col or grid[i_][j_] == 0:
#                     peri += 1
#                 elif grid[i_][j_] == -1:
#                     continue
#                 else:
#                     q.append((i_, j_))
#                     grid[i_][j_] = -1
#         return peri
    
#     def islandPerimeter(self, grid: List[List[int]]) -> int:
#         row, col = len(grid), len(grid[0])
#         for i in range(row):
#             for j in range(col):
#                 if grid[i][j] == 1:
#                     return self.bfs(grid, i, j, row, col)
#         return 0

# class Solution:
#     def solve(self, grid: List[List[int]], i: int, j: int, row: int, col: int):
#         if i < 0 or i >= row or j < 0 or j >= col or grid[i][j] == 0:
#             self.peri += 1
#             return
#         if grid[i][j] == -1:
#             return
#         grid[i][j] = -1
#         self.solve(grid, i+1, j, row, col)
#         self.solve(grid, i-1, j, row, col)
#         self.solve(grid, i, j+1, row, col)
#         self.solve(grid, i, j-1, row, col)

#     def islandPerimeter(self, grid: List[List[int]]) -> int:
#         row, col, self.peri = len(grid), len(grid[0]), 0
#         for i in range(row):
#             for j in range(col):
#                 if grid[i][j] == 1:
#                     self.solve(grid, i, j, row, col)
#                     return self.peri
#         return 0