class Solution:
    def valueAfterKSeconds(self, n: int, k: int) -> int:
        MOD = 1000000007
        ans = [1] * n
        for j in range(0, k):
            dp = [0] * n
            dp[0] = ans[0]
            for i in range(1, n):
                dp[i] = (dp[i-1] + ans[i]) % MOD
            ans = dp
        return ans[n-1]