class Solution:
    def countUnguarded(self, m: int, n: int, guards: List[List[int]], walls: List[List[int]]) -> int:
        grid = [[0] * n for _ in range(m)]
        directions = [(-1, 0), (0, 1), (1, 0), (0, -1)]

        for wall in walls:
            grid[wall[0]][wall[1]] = 1

        for guard in guards:
            grid[guard[0]][guard[1]] = 2

        for guard in guards:
            x, y = guard

            for dx, dy in directions:
                nx, ny = x + dx, y + dy

                while 0 <= nx < m and 0 <= ny < n and grid[nx][ny] != 1 and grid[nx][ny] != 2:
                    if grid[nx][ny] == 0:
                        grid[nx][ny] = 3
                    nx += dx
                    ny += dy

        count = 0
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 0:
                    count += 1

        return count