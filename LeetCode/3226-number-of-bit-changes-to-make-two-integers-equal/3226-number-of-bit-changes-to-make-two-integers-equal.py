class Solution:
    def minChanges(self, n: int, k: int) -> int:
        if (n | k) != n:
            return -1
        count = 0
        for i in range(32):
            if (n & (1 << i)) != 0 and (k & (1 << i)) == 0:
                count += 1
        return count