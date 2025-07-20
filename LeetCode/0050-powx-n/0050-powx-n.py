class Solution:
    def myPow(self, x: float, n: int) -> float:
        res = 1
        if n < 0 :
            n *= -1
            x = 1 / x
        while n > 0:
            if (n & 1) == 1:
                res *= x
            n = n >> 1
            x *= x
        return res