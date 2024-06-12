class Solution:
    def findLongestChain(self, pairs: List[List[int]]) -> int:
        n = len(pairs)
        dp = [1 for _ in range(n)]
        pairs.sort()
        maxLen = 1
        for i in range(n):
            for j in range(0, i):
                if pairs[i][0] > pairs[j][1]:
                    dp[i] = max(dp[i], dp[j] + 1)
                    maxLen = max(maxLen, dp[i])
        return maxLen



# class Solution:
#     def __init__(self):
#         self.n = 0
#         self.dp = [[-1 for _ in range(1001)] for _ in range(1001)]

#     def solve(self, pairs: List[List[int]], prev: int, i: int) -> int:
#         if i == self.n:
#             return 0
#         if prev != -1 and self.dp[prev][i] != -1:
#             return self.dp[prev][i]
#         taken = 0
#         if prev == -1 or pairs[i][0] > pairs[prev][1]:
#             taken = 1 + self.solve(pairs, i, i+1)
#         notTaken = self.solve(pairs, prev, i+1)
#         if prev != -1:
#             self.dp[prev][i] = max(notTaken, taken)
#         return max(taken, notTaken)

#     def findLongestChain(self, pairs: List[List[int]]) -> int:
#         self.n = len(pairs)
#         pairs.sort()
#         return self.solve(pairs, -1, 0)