class Solution:
    # KMP Algorithm to find substring
    def strStr(self, haystack: str, needle: str) -> int:
        n, m = len(haystack), len(needle)
        if m == 0:
            return 0
        if n < m:
            return -1

        lps = [0] * m
        length, i = 0, 1

        # Build the LPS array
        while i < m:
            if needle[i] == needle[length]:
                length += 1
                lps[i] = length
                i += 1
            else:
                if length != 0:
                    length = lps[length - 1]
                else:
                    lps[i] = 0
                    i += 1

        i = 0 
        j = 0 
        while i < n:
            if haystack[i] == needle[j]:
                i += 1
                j += 1
                if j == m:
                    return i - m
            elif j != 0:
                j = lps[j - 1]
            else:
                i += 1
        return -1










# class Solution:
#     MOD = int(1e9 + 7)

#     def hashValue(self, s: str, RADIX: int, m: int) -> int:
#         ans = 0
#         factor = 1
#         for i in range(m - 1, -1, -1):
#             ans = (ans + ((ord(s[i]) - ord('a')) * factor) % self.MOD) % self.MOD
#             factor = (factor * RADIX) % self.MOD
#         return ans % self.MOD

#     def strStr(self, haystack: str, needle: str) -> int:
#         n, m = len(haystack), len(needle)
#         if n < m:
#             return -1

#         RADIX = 26
#         MAX_WEIGHT = 1
#         for _ in range(m):
#             MAX_WEIGHT = (MAX_WEIGHT * RADIX) % self.MOD

#         hashNeedle = self.hashValue(needle, RADIX, m)
#         hashHay = 0

#         for i in range(n - m + 1):
#             if i == 0:
#                 hashHay = self.hashValue(haystack, RADIX, m)
#             else:
#                 hashHay = ((hashHay * RADIX) % self.MOD - ((ord(haystack[i - 1]) - ord('a')) * MAX_WEIGHT) % self.MOD + (ord(haystack[i + m - 1]) - ord('a')) + self.MOD) % self.MOD
            
#             if hashNeedle == hashHay:
#                 if haystack[i:i + m] == needle:
#                     return i
#         return -1