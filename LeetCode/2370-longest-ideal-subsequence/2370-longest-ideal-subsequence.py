class Solution:
    def longestIdealString(self, s: str, k: int) -> int:
        n = len(s)
        dp = [0] * 26
        ans = 0
        for i in range(n):
            idx = ord(s[i]) - ord('a')
            left = max(0, idx - k)
            right = min(25, idx + k)
            longest = 0
            for j in range(left, right+1, 1):
                longest = max(longest, dp[j])
            dp[idx] = max(dp[idx], longest + 1)
            ans = max(ans, dp[idx])
        return ans

# class Solution:
#     def longestIdealString(self, s: str, k: int) -> int:
#         ans = float('-inf')
#         n = len(s)
#         dp = [1] * n
#         for i in range(n):
#             for j in range(i-1, -1, -1):
#                 if abs(ord(s[i]) - ord(s[j])) <= k:
#                     dp[i] = max(dp[i], dp[j] + 1)
#             ans = max(dp[i], ans)
#         return ans