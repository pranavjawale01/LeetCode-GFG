class Solution:
    def minLength(self, s: str) -> int:
        n = len(s)
        s = list(s)
        i, j = 0, 1
        
        while j < n:
            if i < 0:
                i += 1
                s[i] = s[j]
            elif (s[i] == 'A' and s[j] == 'B') or (s[i] == 'C' and s[j] == 'D'):
                i -= 1
            else:
                i += 1
                s[i] = s[j]
            j += 1
        
        return i + 1 







# class Solution:
#     def minLength(self, s: str) -> int:
#         stack = []
        
#         for c in s:
#             if not stack:
#                 stack.append(c)
#             else:
#                 if c == 'B' and stack[-1] == 'A':
#                     stack.pop()
#                 elif c == 'D' and stack[-1] == 'C':
#                     stack.pop()
#                 else:
#                     stack.append(c)
        
#         return len(stack)





# class Solution:
#     def minLength(self, s: str) -> int:
#         while "AB" in s or "CD" in s:
#             if "AB" in s:
#                 s = s.replace("AB", "", 1)
#             elif "CD" in s:
#                 s = s.replace("CD", "", 1)
#         return len(s)