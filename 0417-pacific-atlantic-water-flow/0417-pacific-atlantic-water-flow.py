class Solution:
    def dfs(self, heights: List[List[int]], reach: List[List[bool]], i: int, j: int) -> None:
        reach[i][j] = True
        directions = [(1, 0), (-1, 0), (0, 1), (0, -1)]
        for dir in directions:
            x, y = i + dir[0], j + dir[1]
            if 0 <= x < self.m and 0 <= y < self.n and not reach[x][y] and heights[x][y] >= heights[i][j]:
                self.dfs(heights, reach, x, y)
                
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        self.m, self.n = len(heights), len(heights[0])
        pacific = [[False] * self.n for _ in range(self.m)]
        atlantic = [[False] * self.n for _ in range(self.m)]

        for i in range(self.m):
            self.dfs(heights, pacific, i, 0)
            self.dfs(heights, atlantic, i, self.n - 1)

        for j in range(self.n):
            self.dfs(heights, pacific, 0, j)
            self.dfs(heights, atlantic, self.m - 1, j)

        result = []
        for i in range(self.m):
            for j in range(self.n):
                if pacific[i][j] and atlantic[i][j]:
                    result.append([i, j])

        return result