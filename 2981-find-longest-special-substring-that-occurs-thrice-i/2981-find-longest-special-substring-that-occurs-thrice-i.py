class Solution:
    def maximumLength(self, s: str) -> int:
        n = len(s)
        freq = [[0] * (n + 1) for _ in range(26)]
        for i in range(n):
            c = s[i]
            if i > 0 and s[i] == s[i - 1]:
                sz += 1
            else:
                sz = 1
            freq[ord(c) - ord('a')][sz] += 1

        ans = 0
        for ch in range(26):
            for sz in range(n, 0, -1):
                if sz < n:
                    freq[ch][sz] += freq[ch][sz + 1]
                if freq[ch][sz] >= 3:
                    ans = max(ans, sz)
        
        return ans if ans > 0 else -1








# class Solution:
#     def maximumLength(self, s: str) -> int:
#         n = len(s)
#         mp = {}
#         maxlen = -1
#         for i in range(n):
#             length = 0
#             curr = s[i]
#             for j in range(i, n):
#                 if s[j] != curr:
#                     break
#                 length += 1
#                 key = (curr, length)
#                 mp[key] = mp.get(key, 0) + 1
#         for key, count in mp.items():
#             if count >= 3:
#                 maxlen = max(maxlen, key[1])
#         return -1 if maxlen == 0 else maxlen