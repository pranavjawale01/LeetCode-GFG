class Solution:
    def countAsterisks(self, s: str) -> int:
        count, ast = 0, 0
        for c in s:
            if c == '*' and ast == 0:
                count += 1
            if c == '|':
                ast ^= 1
        return count