class Solution:
    def minLength(self, s: str) -> int:
        stack = []
        
        for c in s:
            if not stack:
                stack.append(c)
            else:
                if c == 'B' and stack[-1] == 'A':
                    stack.pop()
                elif c == 'D' and stack[-1] == 'C':
                    stack.pop()
                else:
                    stack.append(c)
        
        return len(stack)





# class Solution:
#     def minLength(self, s: str) -> int:
#         while "AB" in s or "CD" in s:
#             if "AB" in s:
#                 s = s.replace("AB", "", 1)
#             elif "CD" in s:
#                 s = s.replace("CD", "", 1)
#         return len(s)