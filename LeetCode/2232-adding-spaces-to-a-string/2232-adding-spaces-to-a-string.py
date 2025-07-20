class Solution:
    def addSpaces(self, s: str, spaces: List[int]) -> str:
        m = len(s)
        n = len(spaces)
        ans = []
        j = 0
        for i in range(m):
            if j < n and i == spaces[j]:
                ans.append(" ")
                j += 1
            ans.append(s[i])
        return "".join(ans)