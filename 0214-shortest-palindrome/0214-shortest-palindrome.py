class Solution:
    def computeLPS(self, pattern: str) -> list[int]:
        M = len(pattern)
        lps = [0] * M
        length = 0
        i = 1

        while i < M:
            if pattern[i] == pattern[length]:
                length += 1
                lps[i] = length
                i += 1
            else:
                if length != 0:
                    length = lps[length - 1]
                else:
                    lps[i] = 0
                    i += 1
        return lps

    def shortestPalindrome(self, s: str) -> str:
        rev = s[::-1]
        temp = s + "#" + rev

        lps = self.computeLPS(temp)

        longest_palindrome_prefix_len = lps[-1]

        ans = rev[:len(s) - longest_palindrome_prefix_len] + s
        return ans





# class Solution:
#     def shortestPalindrome(self, s: str) -> str:
#         rev = s[::-1]
#         n = len(s)
#         for i in range(n):
#             if s[:n - i] == rev[i:]:
#                 return rev[:i] + s
#         return rev + s