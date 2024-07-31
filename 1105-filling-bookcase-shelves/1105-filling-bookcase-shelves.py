class Solution:
    def minHeightShelves(self, books: List[List[int]], shelfWidth: int) -> int:
        n = len(books)
        dp = [float('inf')] * (n + 1)
        dp[n] = 0

        for i in range(n - 1, -1, -1):
            availWidth = shelfWidth
            maxHeight = 0
            for j in range(i, n):
                width, height = books[j]
                if availWidth < width:
                    break
                availWidth -= width
                maxHeight = max(maxHeight, height)
                dp[i] = min(dp[i], dp[j + 1] + maxHeight)
        
        return dp[0]




# class Solution:
#     def __init__(self):
#         self.n = 0
#         self.WIDTH = 0
#         self.dp = [[-1] * 1001 for _ in range(1001)]
        
#     def solve(self, books, i, remain, maxHt):
#         if i >= self.n:
#             return maxHt
#         if self.dp[i][remain] != -1:
#             return self.dp[i][remain]
        
#         bookW, bookH = books[i]
#         keep = float('inf')
#         skip = float('inf')
        
#         if bookW <= remain:
#             keep = self.solve(books, i + 1, remain - bookW, max(maxHt, bookH))
#         skip = maxHt + self.solve(books, i + 1, self.WIDTH - bookW, bookH)
        
#         self.dp[i][remain] = min(keep, skip)
#         return self.dp[i][remain]
    
#     def minHeightShelves(self, books: List[List[int]], shelfWidth: int) -> int:
#         self.n = len(books)
#         self.WIDTH = shelfWidth
#         for i in range(self.n + 1):
#             for j in range(1001):
#                 self.dp[i][j] = -1
#         return self.solve(books, 0, shelfWidth, 0)