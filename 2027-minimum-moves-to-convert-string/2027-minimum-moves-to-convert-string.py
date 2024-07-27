class Solution:
    def minimumMoves(self, s: str) -> int:
        count = 0
        n = len(s)
        i = 0
        while i < n:
            if s[i] == 'X':
                count += 1
                i += 3
            else:
                i += 1
        return count