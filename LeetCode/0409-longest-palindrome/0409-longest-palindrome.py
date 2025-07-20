class Solution:
    def longestPalindrome(self, s: str) -> int:
        mp = {}
        for c in s:
            if c in mp:
                mp[c] += 1
            else:
                mp[c] = 1
        
        result = 0
        odd = False
        for count in mp.values():
            if count % 2 == 0:
                result += count
            else:
                result += count - 1
                odd = True
        
        if odd:
            result += 1
        
        return result




# class Solution:
#     def longestPalindrome(self, s: str) -> int:
#         mp = {}
#         result = 0
#         odd = 0
#         n = len(s)
#         for c in s:
#             if c in mp:
#                 mp[c] += 1
#             else:
#                 mp[c] = 1
#             if mp[c] % 2 == 0:
#                 odd -= 1
#             else:
#                 odd += 1
#         if odd > 0:
#             return n - odd + 1
#         return n



# class Solution:
#     def longestPalindrome(self, s: str) -> int:
#         st = set()
#         result = 0
#         for c in s:
#             if c in st:
#                 result += 2
#                 st.remove(c)
#             else:
#                 st.add(c)
#         if st:
#             result += 1
#         return result