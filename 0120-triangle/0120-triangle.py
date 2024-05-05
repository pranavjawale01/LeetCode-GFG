class Solution:
    def __init__(self):
        self.dp = [[-1 for _ in range(201)] for _ in range(201)]

    def solve(self, triangle: List[List[int]], n: int, index: int, level: int) -> int:
        if level >= n:
            return 0
        if self.dp[level][index] != -1:
            return self.dp[level][index]
        self.dp[level][index] = triangle[level][index] + min(self.solve(triangle, n, index, level+1), self.solve(triangle, n, index+1, level+1))
        return self.dp[level][index]
    
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        n = len(triangle)
        return self.solve(triangle, n, 0, 0)