class Solution:
    MOD = 1000000007

    def numWays(self, words: List[str], target: str) -> int:
        k = len(words[0])
        m = len(target)
        
        freq = [[0] * k for _ in range(26)]
        
        for i in range(k):
            for word in words:
                freq[ord(word[i]) - ord('a')][i] += 1
        
        dp = [[0] * (k + 1) for _ in range(m + 1)]
        dp[0][0] = 1

        for i in range(m + 1):
            for j in range(k + 1):
                if j < k:
                    dp[i][j + 1] = (dp[i][j + 1] + dp[i][j]) % self.MOD
                    if i < m and j < k:
                        dp[i + 1][j + 1] = (dp[i + 1][j + 1] + freq[ord(target[i]) - ord('a')][j] * dp[i][j]) % self.MOD

        return dp[m][k]







# class Solution:
#     def numWays(self, words: List[str], target: str) -> int:
#         MOD = 1000000007
#         m = len(target)
#         k = len(words[0])
#         dp = [[-1] * (k + 1) for _ in range(m + 1)]
#         freq = [[0] * k for _ in range(26)]
        
#         for word in words:
#             for j in range(k):
#                 freq[ord(word[j]) - ord('a')][j] += 1
        
#         def solve(i, j):
#             if i == m:
#                 return 1
#             if j == k:
#                 return 0
#             if dp[i][j] != -1:
#                 return dp[i][j]
#             take = (freq[ord(target[i]) - ord('a')][j] * solve(i + 1, j + 1)) % MOD
#             nottake = solve(i, j + 1) % MOD
#             dp[i][j] = (take + nottake) % MOD
#             return dp[i][j]
        
#         return solve(0, 0)