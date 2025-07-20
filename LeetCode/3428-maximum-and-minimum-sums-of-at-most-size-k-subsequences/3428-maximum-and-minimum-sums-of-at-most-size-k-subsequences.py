MOD = 10**9 + 7

def modpow(b, e):
    ans = 1
    while e > 0:
        if e & 1:
            ans = (ans * b) % MOD
        b = (b * b) % MOD
        e >>= 1
    return ans

class Solution:
    def minMaxSums(self, nums: List[int], k: int) -> int:
        nums.sort()
        n = len(nums)
        
        fact = [1] * (n + 1)
        invFact = [1] * (n + 1)
        
        for i in range(1, n + 1):
            fact[i] = (fact[i - 1] * i) % MOD
        
        invFact[n] = modpow(fact[n], MOD - 2)
        for i in range(n - 1, -1, -1):
            invFact[i] = (invFact[i + 1] * (i + 1)) % MOD

        def counter(n, r):
            if r > n or r < 0:
                return 0
            return (fact[n] * invFact[r] % MOD) * invFact[n - r] % MOD

        ans = 0

        for i in range(n):
            for j in range(1, k + 1):
                cnt = counter(n - i - 1, j - 1)
                ans = (ans + nums[i] * cnt) % MOD
            for j in range(1, k + 1):
                cnt = counter(i, j - 1)
                ans = (ans + nums[i] * cnt) % MOD

        return ans