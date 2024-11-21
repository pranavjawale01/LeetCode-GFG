class Solution:
    def dfs(self, grid, row, col, rows, cols, direction):
        if row < 0 or col < 0 or row >= rows or col >= cols or grid[row][col] == 1 or grid[row][col] == 2:
            return
        grid[row][col] = 3
        if direction == 1:
            self.dfs(grid, row - 1, col, rows, cols, direction)
        elif direction == 2:
            self.dfs(grid, row + 1, col, rows, cols, direction)
        elif direction == 3:
            self.dfs(grid, row, col - 1, rows, cols, direction)
        else:
            self.dfs(grid, row, col + 1, rows, cols, direction)

    def countUnguarded(self, rows: int, cols: int, guards: List[List[int]], walls: List[List[int]]) -> int:
        grid = [[0] * cols for _ in range(rows)]
        for guard in guards:
            grid[guard[0]][guard[1]] = 2
        for wall in walls:
            grid[wall[0]][wall[1]] = 1
        for guard in guards:
            guardRow = guard[0]
            guardCol = guard[1]
            self.dfs(grid, guardRow - 1, guardCol, rows, cols, 1)
            self.dfs(grid, guardRow + 1, guardCol, rows, cols, 2)
            self.dfs(grid, guardRow, guardCol - 1, rows, cols, 3)
            self.dfs(grid, guardRow, guardCol + 1, rows, cols, 4)
        unguardedCount = 0
        for row in range(rows):
            for col in range(cols):
                if grid[row][col] == 0:
                    unguardedCount += 1
        return unguardedCount




# class Solution:
#     def countUnguarded(self, m: int, n: int, guards: List[List[int]], walls: List[List[int]]) -> int:
#         grid = [[0] * n for _ in range(m)]
#         directions = [(-1, 0), (0, 1), (1, 0), (0, -1)]

#         for wall in walls:
#             grid[wall[0]][wall[1]] = 1

#         for guard in guards:
#             grid[guard[0]][guard[1]] = 2

#         for guard in guards:
#             x, y = guard

#             for dx, dy in directions:
#                 nx, ny = x + dx, y + dy

#                 while 0 <= nx < m and 0 <= ny < n and grid[nx][ny] != 1 and grid[nx][ny] != 2:
#                     if grid[nx][ny] == 0:
#                         grid[nx][ny] = 3
#                     nx += dx
#                     ny += dy

#         count = 0
#         for i in range(m):
#             for j in range(n):
#                 if grid[i][j] == 0:
#                     count += 1

#         return count