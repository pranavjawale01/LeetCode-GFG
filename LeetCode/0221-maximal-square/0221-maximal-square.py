class Solution:
    def maximalSquare(self, matrix: List[List[str]]) -> int:
        row, col = len(matrix), len(matrix[0])
        ans = 0
        dp = [[0 for _ in range(col+1)] for _ in range(row+1)]
        for i in range(1, row+1):
            for j in range(1, col+1):
                if matrix[i-1][j-1] == '1':
                    dp[i][j] = 1 + min(dp[i-1][j-1],dp[i-1][j], dp[i][j-1])
                    ans = max(ans, dp[i][j])
        return ans * ans