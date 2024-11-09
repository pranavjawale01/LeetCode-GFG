class Solution:
    def smallestNumber(self, n: int, t: int) -> int:
        while True:
            prod = 1
            temp = n
            while temp > 0:
                prod *= temp % 10
                temp //= 10
            if prod % t == 0:
                return n
            n += 1