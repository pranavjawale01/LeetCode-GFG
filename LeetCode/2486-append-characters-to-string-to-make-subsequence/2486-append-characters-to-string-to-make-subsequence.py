class Solution:
    def appendCharacters(self, s: str, t: str) -> int:
        i, j = 0, 0
        sn, tn = len(s), len(t)
        while i < sn and j < tn:
            if s[i] == t[j]:
                j += 1
            i += 1
        return tn - j