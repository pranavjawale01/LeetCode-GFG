class Solution:
    def numberOfMatches(self, n: int) -> int:
        count = 0
        while n != 1:
            if n % 2 != 0:
                count +=1
                n -= 1
            n = n // 2
            count += n
        return count