class Solution:
    def findComplement(self, num: int) -> int:
        i = 31
        while i >= 0 and (num & (1 << i)) == 0:
            i -= 1
        for j in range(i, -1, -1):
            num = num ^ (1 << j)
        return num