class Solution:
    def solve(self, s: str) -> str:
        temp = ""
        for c in s:
            temp += chr(ord(c) + 1)
        return s + temp

    def kthCharacter(self, k: int) -> str:
        s = "a"
        while len(s) < k:
            s = self.solve(s)
        return s[k - 1]