class Solution:
    def isBalanced(self, num: str) -> bool:
        a, b, n = 0, 0, len(num)
        for i in range(n):
            if i % 2:
                a += ord(num[i]) - ord('0')
            else:
                b += ord(num[i]) - ord('0')
        return a == b