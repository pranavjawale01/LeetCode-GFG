class Solution:
    def countPalindromicSubsequence(self, s: str) -> int:
        n = len(s)
        first = [-1] * 26
        last = [-1] * 26

        for i, char in enumerate(s):
            idx = ord(char) - ord('a')
            if first[idx] == -1:
                first[idx] = i
            last[idx] = i

        result = 0

        for c in range(26):
            if first[c] != -1 and last[c] > first[c]:
                middle = set()
                for i in range(first[c] + 1, last[c]):
                    middle.add(s[i])
                result += len(middle)

        return result