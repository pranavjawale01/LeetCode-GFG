class Solution:
    def countGoodNumbers(self, n: int) -> int:
        odd = n // 2
        even = (n + 1) // 2
        mod = 10**9 + 7
        
        def binpow(x, y):
            ans = 1
            while y:
                if y & 1:
                    ans = (ans * x) % mod
                x = (x * x) % mod
                y >>= 1
            return ans
        
        f = binpow(5, even) % mod
        s = binpow(4, odd) % mod
        return int((f * s) % mod)