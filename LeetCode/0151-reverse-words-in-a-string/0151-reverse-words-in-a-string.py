class Solution:
    def reverseWords(self, s: str) -> str:
        s = s[::-1]
        n, i = len(s), 0
        while i < n and s[i] == ' ':
            i += 1
        ans = []
        temp = []
        for j in range(i, n):
            if s[j] == ' ':
                if temp:
                    ans.append("".join(temp[::-1]))
                    temp = []
            else:
                temp.append(s[j])
        if temp:
            ans.append("".join(temp[::-1]))
        return " ".join(ans)