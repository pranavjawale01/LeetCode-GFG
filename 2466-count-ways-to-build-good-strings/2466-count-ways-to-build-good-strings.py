class Solution:
    def countGoodStrings(self, low: int, high: int, zero: int, one: int) -> int:
        dp = [0] * (high + 1)
        dp[0] = 1
        mod = 10**9 + 7

        for i in range(1, high + 1):
            if i - zero >= 0:
                dp[i] = (dp[i] + dp[i - zero]) % mod
            if i - one >= 0:
                dp[i] = (dp[i] + dp[i - one]) % mod

        ans = 0
        for i in range(low, high + 1):
            ans = (ans + dp[i]) % mod

        return ans





# class Solution:
#     def __init__(self):
#         self.m = int(1e9 + 7)
#         self.dp = []

#     def solve(self, L):
#         if L > self.h:
#             return 0
#         if self.dp[L] != -1:
#             return self.dp[L]
#         add_one = 1 if self.l <= L <= self.h else 0
#         take_zero = self.solve(L + self.z)
#         take_one = self.solve(L + self.o)
#         self.dp[L] = (add_one + take_zero + take_one) % self.m
#         return self.dp[L]

#     def countGoodStrings(self, low: int, high: int, zero: int, one: int) -> int:
#         self.l = low
#         self.h = high
#         self.z = zero
#         self.o = one
#         self.dp = [-1] * (high + 1)
#         return self.solve(0)