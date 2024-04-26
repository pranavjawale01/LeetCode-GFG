class Solution:
    def fib(self, n: int) -> int:
        if n <= 1:
            return n
        first = 1
        second = 0
        for i in range(2, n+1):
            temp = first + second
            second = first
            first = temp
        return first