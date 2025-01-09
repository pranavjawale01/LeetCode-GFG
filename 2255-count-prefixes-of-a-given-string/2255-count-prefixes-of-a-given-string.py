class Solution:
    def countPrefixes(self, words: List[str], s: str) -> int:
        count = 0
        for x in words:
            if len(x) <= len(s) and s[0:len(x)] == x:
                count += 1
        return count