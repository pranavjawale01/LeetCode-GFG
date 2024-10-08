class Solution:
    def minSwaps(self, s: str) -> int:
        size = 0
        for c in s:
            if c == '[':
                size += 1
            elif size:
                size -= 1
        return (size + 1) // 2









# class Solution:
#     def minSwaps(self, s: str) -> int:
#         st = []
#         for c in s:
#             if c == '[':
#                 st.append(c)
#             elif st:
#                 st.pop()
#         return (len(st) + 1) // 2