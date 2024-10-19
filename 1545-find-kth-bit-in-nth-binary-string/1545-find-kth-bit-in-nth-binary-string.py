class Solution:
    def findKthBit(self, n: int, k: int) -> str:
        if n == 1:
            return '0'
        
        len = (1 << n) - 1
        
        if k < (len + 1) // 2:
            return self.findKthBit(n - 1, k)
        elif k == (len + 1) // 2:
            return '1'
        else:
            ch = self.findKthBit(n - 1, len - k + 1)
            return '1' if ch == '0' else '0'






# class Solution:
#     def findKthBit(self, n: int, k: int) -> str:
#         s = "0"
        
#         for i in range(2, n + 1):
#             inverted = ''.join('1' if c == '0' else '0' for c in s)
#             s = s + "1" + inverted[::-1]
        
#         return s[k - 1]