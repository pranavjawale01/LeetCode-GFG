class Solution:
    def customSortString(self, order: str, s: str) -> str:
        arr = [-1] * 26
        for i, ch in enumerate(order):
            arr[ord(ch) - ord('a')] = i
        s = sorted(s, key = lambda x : arr[ord(x) - ord('a')])
        return ''.join(s)

# class Solution:
#     def customSortString(self, order: str, s: str) -> str:
#         mp = defaultdict(int)
#         for ch in s:
#             mp[ch] += 1
#         ans = ""
#         for ch in order:
#             if mp[ch] > 0:
#                 ans += ch * mp[ch]
#                 del mp[ch]
#         for ch, count in mp.items():
#             ans += ch * count
#         return ans