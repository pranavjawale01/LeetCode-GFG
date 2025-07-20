class Solution:
    def scoreOfString(self, s: str) -> int:
        diff = 0
        n = len(s)
        for i in range(n - 1):
            diff += abs((ord(s[i]) - ord('a')) - (ord(s[i + 1]) - ord('a')))
        return diff