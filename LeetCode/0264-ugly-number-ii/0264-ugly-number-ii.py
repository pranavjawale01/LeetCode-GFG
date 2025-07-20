class Solution:
    def nthUglyNumber(self, n: int) -> int:
        dp = [0] * (n + 1)
        i2, i3, i5 = 1, 1, 1
        dp[1] = 1
        for i in range(2, n+1):
            i2_temp = dp[i2] * 2
            i3_temp = dp[i3] * 3
            i5_temp = dp[i5] * 5
            dp[i] = min(i2_temp, i3_temp, i5_temp)
            if dp[i] == i2_temp:
                i2 += 1
            if dp[i] == i3_temp:
                i3 += 1
            if dp[i] == i5_temp:
                i5 += 1
        return dp[n]