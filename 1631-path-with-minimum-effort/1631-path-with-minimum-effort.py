class Solution:
    def __init__(self):
        self.effort = [[float('inf')] * 105 for _ in range(105)]
        self.dx = [0, 1, -1, 0]
        self.dy = [1, 0, 0, -1]

    def dijkstra(self, heights) -> int:
        rows = len(heights)
        cols = len(heights[0])

        pq = [(0, 0, 0)]
        self.effort[0][0] = 0

        while pq:
            cost, x, y = heapq.heappop(pq)

            if cost > self.effort[x][y]:
                continue

            if x == rows - 1 and y == cols - 1:
                return cost

            for i in range(4):
                new_x = x + self.dx[i]
                new_y = y + self.dy[i]

                if not (0 <= new_x < rows and 0 <= new_y < cols):
                    continue

                new_effort = max(self.effort[x][y], abs(heights[x][y] - heights[new_x][new_y]))

                if new_effort < self.effort[new_x][new_y]:
                    self.effort[new_x][new_y] = new_effort
                    heapq.heappush(pq, (new_effort, new_x, new_y))

        return self.effort[rows - 1][cols - 1]

    def minimumEffortPath(self, heights) -> int:
        rows = len(heights)
        cols = len(heights[0])

        for i in range(rows):
            for j in range(cols):
                self.effort[i][j] = float('inf')

        return self.dijkstra(heights)