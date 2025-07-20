class Solution:
    def getSmallestString(self, s: str) -> str:
        n = len(s)
        s = list(s)
        for i in range(1, n):
            if (ord(s[i-1]) - ord('0')) % 2 == (ord(s[i]) - ord('0')) % 2:
                if s[i-1] > s[i]:
                    s[i], s[i-1] = s[i-1], s[i]
                    break
        return ''.join(s)