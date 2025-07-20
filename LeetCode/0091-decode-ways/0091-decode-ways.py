class Solution:
    def numDecodings(self, s: str) -> int:
        n = len(s)
        if n == 0 or s[0] == '0':
            return 0 

        dp = [0] * (n + 1)
        dp[0] = 1 

        for i in range(1, n + 1):
            if s[i - 1] != '0':
                dp[i] += dp[i - 1]

            if i > 1 and self.is_valid_mapping(s[i - 2], s[i - 1]):
                dp[i] += dp[i - 2]

        return dp[n]

    def is_valid_mapping(self, a: str, b: str) -> bool:
        num = int(a + b)
        return 10 <= num <= 26