class Solution:
    def prefixCount(self, words: List[str], pref: str) -> int:
        n = len(pref)
        count = 0
        for x in words:
            if len(x) >= n and x[0:n] == pref:
                count += 1
        return count