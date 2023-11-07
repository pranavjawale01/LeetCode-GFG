class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        sIndex, pIndex = 0, 0
        starIndex, sTempIndex = -1, -1

        while sIndex < len(s):
            if pIndex < len(p) and (s[sIndex] == p[pIndex] or p[pIndex] == '?'):
                sIndex += 1
                pIndex += 1
            elif pIndex < len(p) and p[pIndex] == '*':
                starIndex = pIndex
                sTempIndex = sIndex
                pIndex += 1
            elif starIndex != -1:
                pIndex = starIndex + 1
                sTempIndex += 1
                sIndex = sTempIndex
            else:
                return False

        while pIndex < len(p) and p[pIndex] == '*':
            pIndex += 1

        return pIndex == len(p)