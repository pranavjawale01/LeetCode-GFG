class Solution:
    def maximumLength(self, s: str) -> int:
        ans = 0
        freq = [[] for _ in range(26)]

        i = 0
        while i < len(s):
            j = i
            while j < len(s) and s[j] == s[i]:
                j += 1
            freq[ord(s[i]) - ord('a')].append(j - i)
            i = j

        for x in freq:
            if not x:
                continue
            x.sort()
            n = len(x)
            ans = max(ans, x[-1] - 2)
            if n > 1:
                ans = max(ans, min(x[n - 1] - 1, x[n - 2]))
            if n > 2:
                ans = max(ans, x[n - 3])

        if ans == 0:
            ans = -1
        return ans





# TLE
# class Solution:
#     def maximumLength(self, s: str) -> int:
#         n = len(s)
#         freq = [[0] * (n + 1) for _ in range(26)]
#         for i in range(n):
#             c = s[i]
#             if i > 0 and s[i] == s[i - 1]:
#                 sz += 1
#             else:
#                 sz = 1
#             freq[ord(c) - ord('a')][sz] += 1

#         ans = 0
#         for ch in range(26):
#             for sz in range(n, 0, -1):
#                 if sz < n:
#                     freq[ch][sz] += freq[ch][sz + 1]
#                 if freq[ch][sz] >= 3:
#                     ans = max(ans, sz)
        
#         return ans if ans > 0 else -1