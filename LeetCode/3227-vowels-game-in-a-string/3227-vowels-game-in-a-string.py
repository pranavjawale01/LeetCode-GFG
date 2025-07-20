class Solution:
    def doesAliceWin(self, s: str) -> bool:
        for c in "aeiou":
            if c in s:
                return True
        return False