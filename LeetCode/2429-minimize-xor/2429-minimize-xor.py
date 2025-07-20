class Solution:
    def minimizeXor(self, num1: int, num2: int) -> int:
        count = bin(num2).count('1')
        ans = 0
        for i in range(31, -1, -1):
            if count > 0 and (num1 & (1 << i)):
                ans |= (1 << i)
                count -= 1
        for i in range(32):
            if count > 0 and (ans & (1 << i)) == 0:
                ans |= (1 << i)
                count -= 1
        return ans