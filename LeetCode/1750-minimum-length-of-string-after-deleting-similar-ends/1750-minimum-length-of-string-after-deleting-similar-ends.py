class Solution:
    def minimumLength(self, s: str) -> int:
        n = len(s)
        i , j = 0 , n - 1
        while i < j and s[i] == s[j]:
            ch = s[i]
            while i < j and s[i] == ch:
                i += 1
            while j >= i and s[j] == ch:
                j -= 1
        return j - i + 1