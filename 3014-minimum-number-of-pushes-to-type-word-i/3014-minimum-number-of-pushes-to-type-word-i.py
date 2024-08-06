class Solution:
    def minimumPushes(self, word: str) -> int:
        freq = [0] * 26
        for c in word:
            freq[ord(c) - ord('a')] += 1
        freq.sort(reverse=True)
        ans = 0
        for i in range(26):
            ans += ((i // 8) + 1) * freq[i]
        return ans






# class Solution:
#     def minimumPushes(self, word: str) -> int:
#         mp = {}
#         key = 2
#         ans = 0
#         for c in word:
#             if key > 9:
#                 key = 2
#             if key not in mp:
#                 mp[key] = 0
#             mp[key] += 1
#             ans += mp[key]
#             key += 1
#         return ans




# class Solution:
#     def minimumPushes(self, word: str) -> int:
#         mp = {}
#         for c in word:
#             mp[c] = mp.get(c, 0) + 1
#         size = len(mp)
#         if size <= 8:
#             return len(word)
#         if size > 8 and size < 17:
#             return 8 + (size - 8) * 2
#         if size > 16 and size < 25:
#             return 8 + 16 + (size - 16) * 3
#         return 8 + 16 + 24 + (size - 24) * 4