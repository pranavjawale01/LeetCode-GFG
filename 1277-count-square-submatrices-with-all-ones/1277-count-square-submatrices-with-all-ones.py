class Solution:
    def solve(self, i, j, mat, dp):
        if i >= self.m or j >= self.n:
            return 0
        if mat[i][j] == 0:
            return 0
        if dp[i][j] != -1:
            return dp[i][j]
        right = self.solve(i, j + 1, mat, dp)
        diagonal = self.solve(i + 1, j + 1, mat, dp)
        below = self.solve(i + 1, j, mat, dp)
        dp[i][j] = 1 + min(right, diagonal, below)
        return dp[i][j]
    
    def countSquares(self, matrix: List[List[int]]) -> int:
        self.m = len(matrix)
        self.n = len(matrix[0])
        dp = [[-1] * self.n for _ in range(self.m)]
        ans = 0
        for i in range(self.m):
            for j in range(self.n):
                ans += self.solve(i, j, matrix, dp)
        return ans