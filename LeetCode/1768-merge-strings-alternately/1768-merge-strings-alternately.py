class Solution:
    def mergeAlternately(self, word1: str, word2: str) -> str:
        ans = ""
        n, m = len(word1), len(word2)
        i, j = 0, 0
        while i < n  or j < m:
            if i < n:
                ans += (word1[i])
                i += 1
            if j < m:
                ans += (word2[j])
                j += 1
        return ans