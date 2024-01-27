class Solution:
    M = 10**9 + 7

    def kInversePairs(self, n: int, k: int) -> int:
        t = [[0] * (k + 1) for _ in range(n + 1)]
        
        for i in range(n + 1):
            t[i][0] = 1

        for i in range(1, n + 1):
            cum_sum = 1
            for j in range(1, k + 1):

                cum_sum += t[i - 1][j]
                if j >= i:
                    cum_sum -= t[i - 1][j - i]

                t[i][j] = cum_sum % self.M

        return t[n][k]