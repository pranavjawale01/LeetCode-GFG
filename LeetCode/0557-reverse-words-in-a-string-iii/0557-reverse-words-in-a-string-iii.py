class Solution:
    def reverseWords(self, s: str) -> str:
        n, start, end, i = len(s), 0, 0, 0
        result = ""
        while i < n:
            if s[i] == ' ':
                for j in range(end - 1, start - 1, -1):
                    result += s[j]
                result += " "
                start = i + 1
            i += 1
            end = i
        for j in range(end - 1, start - 1, -1):
            result += s[j]
        return result