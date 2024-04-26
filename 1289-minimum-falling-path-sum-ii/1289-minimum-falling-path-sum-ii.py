class Solution:
    def minFallingPathSum(self, grid: List[List[int]]) -> int:
        n = len(grid)
        dp = [[0] * n for _ in range(n)]
        
        nextMinCol1, nextMinCol2 = -1, -1
        
        for i in range(n):
            dp[n-1][i] = grid[n-1][i]

            if nextMinCol1 == -1 or dp[n-1][i] <= dp[n-1][nextMinCol1]:
                nextMinCol2 = nextMinCol1
                nextMinCol1 = i
            elif nextMinCol2 == -1 or dp[n-1][i] <= dp[n-1][nextMinCol2]:
                nextMinCol2 = i
        
        for row in range(n - 2, -1, -1):
            minCol1, minCol2 = -1, -1
            for col in range(n):
                if col != nextMinCol1:
                    dp[row][col] = grid[row][col] + dp[row+1][nextMinCol1]
                else:
                    dp[row][col] = grid[row][col] + dp[row+1][nextMinCol2]

                if minCol1 == -1 or dp[row][col] <= dp[row][minCol1]:
                    minCol2 = minCol1
                    minCol1 = col
                elif minCol2 == -1 or dp[row][col] <= dp[row][minCol2]:
                    minCol2 = col
            nextMinCol1, nextMinCol2 = minCol1, minCol2
        
        return min(dp[0])

        

# class Solution:
#     def minFallingPathSum(self, grid: List[List[int]]) -> int:
#         n = len(grid)
#         dp = [[0] * (n+1) for _ in range (n+1)]
#         for i in range(n):
#             dp[n-1][i] = grid[n-1][i]
#         for row in range(n-2, -1, -1):
#             for col in range(0, n):
#                 ans = float(inf)
#                 for nextCol in range(0, n):
#                     if nextCol != col:
#                         ans = min(ans, dp[row+1][nextCol])
#                 dp[row][col] = ans + grid[row][col]
#         ans = float(inf)
#         for i in range(n):
#             ans = min(ans, dp[0][i])
#         return ans



# class Solution:
#     def __init__(self):
#         self.dp = [[-1] * 201 for _ in range(201)]

#     def solve(self, grid, n, level, col):
#         if level == n - 1:
#             self.dp[level][col] = grid[level][col]
#             return self.dp[level][col]
        
#         if self.dp[level][col] != -1:
#             return self.dp[level][col]
        
#         ans = float('inf')
#         for j in range(n):
#             if col == j:
#                 continue
#             ans = min(ans, grid[level][col] + self.solve(grid, n, level + 1, j))
        
#         self.dp[level][col] = ans
#         return self.dp[level][col]

#     def minFallingPathSum(self, grid: List[List[int]]) -> int:
#         n = len(grid)
#         ans = float('inf')
#         for j in range(n):
#             ans = min(ans, self.solve(grid, n, 0, j))
#         return ans