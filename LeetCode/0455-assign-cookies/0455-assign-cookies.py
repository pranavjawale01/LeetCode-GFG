class Solution:
    def findContentChildren(self, g: List[int], s: List[int]) -> int:
        i , j , count = 0 , 0 , 0
        s.sort()
        g.sort()
        while i < len(g) and j < len(s):
            if s[j] >= g[i]:
                count += 1
                i += 1
            j += 1
        return count