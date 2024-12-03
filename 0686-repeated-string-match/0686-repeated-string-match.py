class Solution:
    # KMP Algorithm
    def kmp(self, s: str, p: str) -> bool:
        m, n = len(s), len(p)
        lps = [0] * n
        length, i = 0, 1

        # Compute LPS array
        while i < n:
            if p[length] == p[i]:
                length += 1
                lps[i] = length
                i += 1
            else:
                if length != 0:
                    length = lps[length - 1]
                else:
                    lps[i] = 0
                    i += 1

        # Perform pattern matching
        i = 0
        j = 0
        while i < m:
            if s[i] == p[j]:
                i += 1
                j += 1
                if j == n:
                    return True  # Match found
            elif j != 0:
                j = lps[j - 1]
            else:
                i += 1

        return False

    def repeatedStringMatch(self, a: str, b: str) -> int:
        if a == b:
            return 1
        ans = 1
        src = a

        while len(src) < len(b):
            src += a
            ans += 1

        if src == b:
            return ans
        if self.kmp(src, b):
            return ans

        src += a
        ans += 1
        if self.kmp(src, b):
            return ans

        return -1





# class Solution:
#     MOD = int(1e9 + 7)

#     # Rabin Karp hashValue method
#     def hashValue(self, s: str, RADIX: int, m: int) -> int:
#         ans = 0
#         factor = 1
#         for i in range(m - 1, -1, -1):
#             ans = (ans + ((ord(s[i]) - ord('a')) * factor) % self.MOD) % self.MOD
#             factor = (factor * RADIX) % self.MOD
#         return ans % self.MOD

#     # Rabin Karp strStr method
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

#     def repeatedStringMatch(self, a: str, b: str) -> int:
#         if a == b:
#             return 1
#         ans = 1
#         src = a
#         while len(src) < len(b):
#             src += a
#             ans += 1
#         if src == b:
#             return ans
#         if self.strStr(src, b) != -1:
#             return ans
#         src += a
#         ans += 1
#         if self.strStr(src, b) != -1:
#             return ans
#         return -1