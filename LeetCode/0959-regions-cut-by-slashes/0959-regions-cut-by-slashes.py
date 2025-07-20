class Solution:
    def __init__(self):
        self.x = [-1, 0, 0, 1]
        self.y = [0, -1, 1, 0]

    def isValid(self, i, j, m, n, grid):
        return 0 <= i < m and 0 <= j < n and grid[i][j] == 0

    def dfs(self, i, j, m, n, visited, grid):
        visited[i][j] = True
        for k in range(4):
            newX = i + self.x[k]
            newY = j + self.y[k]
            if self.isValid(newX, newY, m, n, grid):
                if not visited[newX][newY]:
                    self.dfs(newX, newY, m, n, visited, grid)

    def regionsBySlashes(self, grid: list[str]) -> int:
        m = len(grid) * 3
        n = len(grid[0]) * 3
        newGrid = [[0] * n for _ in range(m)]
        visited = [[False] * n for _ in range(m)]

        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == '/':
                    newGrid[i * 3][j * 3 + 2] = 1
                    newGrid[i * 3 + 1][j * 3 + 1] = 1
                    newGrid[i * 3 + 2][j * 3] = 1
                elif grid[i][j] == '\\':
                    newGrid[i * 3][j * 3] = 1
                    newGrid[i * 3 + 1][j * 3 + 1] = 1
                    newGrid[i * 3 + 2][j * 3 + 2] = 1

        count = 0
        for i in range(m):
            for j in range(n):
                if newGrid[i][j] == 0 and not visited[i][j]:
                    self.dfs(i, j, m, n, visited, newGrid)
                    count += 1

        return count