class Solution:
    def canMakeSubsequence(self, str1: str, str2: str) -> bool:
        m, n = len(str1), len(str2)
        j = 0
        for i in range(m):
            if j < n and (str1[i] == str2[j] or (ord(str1[i]) - ord('a') + 1) % 26 == (ord(str2[j]) - ord('a'))):
                j += 1
            if j == n:
                return True
        return False