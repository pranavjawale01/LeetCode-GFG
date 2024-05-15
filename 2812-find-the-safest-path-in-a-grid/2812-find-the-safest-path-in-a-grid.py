class Solution:
    def __init__(self):
        self.n = 0
        self.directions = [[1, 0], [-1, 0], [0, -1], [0, 1]]

    def check(self, distNearestThief, sf):
        que = deque()
        visited = [[False] * self.n for _ in range(self.n)]
        que.append((0, 0))
        visited[0][0] = True

        if distNearestThief[0][0] < sf:
            return False

        while que:
            curr_i, curr_j = que.popleft()

            if curr_i == self.n - 1 and curr_j == self.n - 1:
                return True

            for dir in self.directions:
                new_i = curr_i + dir[0]
                new_j = curr_j + dir[1]

                if 0 <= new_i < self.n and 0 <= new_j < self.n and not visited[new_i][new_j]:
                    if distNearestThief[new_i][new_j] < sf:
                        continue
                    que.append((new_i, new_j))
                    visited[new_i][new_j] = True

        return False

    def maximumSafenessFactor(self, grid: List[List[int]]) -> int:
        self.n = len(grid)
        distNearestThief = [[-1] * self.n for _ in range(self.n)]
        que = deque()
        visited = [[False] * self.n for _ in range(self.n)]

        for i in range(self.n):
            for j in range(self.n):
                if grid[i][j] == 1:
                    que.append((i, j))
                    visited[i][j] = True

        level = 0
        while que:
            size = len(que)

            while size > 0:
                curr_i, curr_j = que.popleft()
                distNearestThief[curr_i][curr_j] = level

                for dir in self.directions:
                    new_i = curr_i + dir[0]
                    new_j = curr_j + dir[1]

                    if 0 <= new_i < self.n and 0 <= new_j < self.n and not visited[new_i][new_j]:
                        que.append((new_i, new_j))
                        visited[new_i][new_j] = True

                size -= 1
            level += 1

        l = 0
        r = 400
        result = 0

        while l <= r:
            mid_sf = l + (r - l) // 2

            if self.check(distNearestThief, mid_sf):
                result = mid_sf
                l = mid_sf + 1
            else:
                r = mid_sf - 1

        return result