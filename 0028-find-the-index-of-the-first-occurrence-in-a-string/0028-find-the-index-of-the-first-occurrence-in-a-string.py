class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        h, n = len(haystack), len(needle)
        hash_n = hash(needle)
        for i in range(h-n+1):
            if hash(haystack[i:i+n]) == hash_n:
                return i
        return -1