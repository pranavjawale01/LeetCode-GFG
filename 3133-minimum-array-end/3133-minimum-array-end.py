class Solution:
    def minEnd(self, n: int, x: int) -> int:
        n -= 1
        ans = 0
        j = 0
        for i in range(64):
            if (x >> i) & 1:
                ans |= (1 << i)
            else:
                if (n >> j) & 1:
                    ans |= (1 << i)
                j += 1
        return ans





# TLE
# class Solution:
#     def minEnd(self, n: int, x: int) -> int:
#         num = x
#         for i in range(1, n):
#             num = (num + 1) | x
#         return num