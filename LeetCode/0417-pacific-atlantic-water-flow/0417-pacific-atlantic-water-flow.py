class Solution:
    def bfs(self, heights: List[List[int]], queue: deque, reach: List[List[bool]]):
        directions = [(1, 0), (-1, 0), (0, 1), (0, -1)]
        while queue:
            i, j = queue.popleft()
            for dir in directions:
                x, y = i + dir[0], j + dir[1]
                if 0 <= x < self.m and 0 <= y < self.n and not reach[x][y] and heights[x][y] >= heights[i][j]:
                    reach[x][y] = True
                    queue.append((x, y))

    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        self.m, self.n = len(heights), len(heights[0])
        pacific = [[False] * self.n for _ in range(self.m)]
        atlantic = [[False] * self.n for _ in range(self.m)]
        pacific_queue = deque()
        atlantic_queue = deque()

        for i in range(self.m):
            pacific_queue.append((i, 0))
            atlantic_queue.append((i, self.n - 1))
            pacific[i][0] = True
            atlantic[i][self.n - 1] = True

        for j in range(self.n):
            pacific_queue.append((0, j))
            atlantic_queue.append((self.m - 1, j))
            pacific[0][j] = True
            atlantic[self.m - 1][j] = True

        self.bfs(heights, pacific_queue, pacific)
        self.bfs(heights, atlantic_queue, atlantic)

        result = []
        for i in range(self.m):
            for j in range(self.n):
                if pacific[i][j] and atlantic[i][j]:
                    result.append([i, j])

        return result




# class Solution:
#     def dfs(self, heights: List[List[int]], reach: List[List[bool]], i: int, j: int) -> None:
#         reach[i][j] = True
#         directions = [(1, 0), (-1, 0), (0, 1), (0, -1)]
#         for dir in directions:
#             x, y = i + dir[0], j + dir[1]
#             if 0 <= x < self.m and 0 <= y < self.n and not reach[x][y] and heights[x][y] >= heights[i][j]:
#                 self.dfs(heights, reach, x, y)

#     def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
#         self.m, self.n = len(heights), len(heights[0])
#         pacific = [[False] * self.n for _ in range(self.m)]
#         atlantic = [[False] * self.n for _ in range(self.m)]

#         for i in range(self.m):
#             self.dfs(heights, pacific, i, 0)
#             self.dfs(heights, atlantic, i, self.n - 1)

#         for j in range(self.n):
#             self.dfs(heights, pacific, 0, j)
#             self.dfs(heights, atlantic, self.m - 1, j)

#         result = []
#         for i in range(self.m):
#             for j in range(self.n):
#                 if pacific[i][j] and atlantic[i][j]:
#                     result.append([i, j])

#         return result