class Solution:
    def maxScore(self, a: List[int], b: List[int]) -> int:
        row, col = len(a), len(b)
        dp = [[float('-inf') for _ in range(col)] for _ in range(row)]
        for i in range(col):
            dp[0][i] = a[0] * b[i]
        for i in range(1, row):
            maxAns = float('-inf')
            for j in range(i, col):
                maxAns = max(maxAns, dp[i-1][j-1])
                dp[i][j] = maxAns + a[i] * b[j]
        return max(dp[3])