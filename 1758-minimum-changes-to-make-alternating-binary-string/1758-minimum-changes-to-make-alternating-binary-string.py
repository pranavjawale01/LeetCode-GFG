class Solution:
    def minOperations(self, s: str) -> int:
        n = len(s)
        count0 = 0
        count1 = 0

        for i in range(n):
            if s[i] != chr(ord('0') + i % 2):
                count0 += 1
            else:
                count1 += 1
        return min(count0, count1)