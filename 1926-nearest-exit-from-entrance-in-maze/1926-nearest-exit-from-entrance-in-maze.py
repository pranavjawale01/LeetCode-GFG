class Solution:
    def nearestExit(self, maze: List[List[str]], entrance: List[int]) -> int:
        row, col = len(maze), len(maze[0])
        q = deque()
        q.append((entrance[0], entrance[1]))
        maze[entrance[0]][entrance[1]] = '+'
        directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]
        steps = 0
        
        while q:
            n = len(q)
            steps += 1
            for _ in range(n):
                curr = q.popleft()
                for direction in directions:
                    x = curr[0] + direction[0]
                    y = curr[1] + direction[1]
                    if x < 0 or y < 0 or x >= row or y >= col or maze[x][y] == '+':
                        continue
                    if x == 0 or y == 0 or x == row - 1 or y == col - 1:
                        return steps
                    maze[x][y] = '+'
                    q.append((x,y))
        return -1