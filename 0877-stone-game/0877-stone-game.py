class Solution:
    def stoneGame(self, piles: List[int]) -> bool:
        n = len(piles)
        dp = piles[:]
        for i in range(1, n):
            for j in range(0, n - i):
                dp[j] = max(piles[j] - dp[j+1], piles[j+i] - dp[j])
        return dp[0] > 0


# class Solution:
#     def stoneGame(self, piles: List[int]) -> bool:
#         return True