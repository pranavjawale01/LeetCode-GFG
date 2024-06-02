class Solution:
    def __init__(self):
        self.dp = [[-1 for _ in range(1000)] for _ in range(1000)]

    def solve(self, s: str, start: int, end: int) -> int:
        if start == end:
            return 1
        if start > end:
            return 0
        if self.dp[start][end] != -1:
            return self.dp[start][end]
        if s[start] == s[end]:
            self.dp[start][end] = 2 + self.solve(s, start+1, end-1)
        else:
            self.dp[start][end] = max(self.solve(s, start+1, end), self.solve(s, start, end-1))
        return self.dp[start][end]

    def longestPalindromeSubseq(self, s: str) -> int:
        return self.solve(s, 0, len(s)-1)