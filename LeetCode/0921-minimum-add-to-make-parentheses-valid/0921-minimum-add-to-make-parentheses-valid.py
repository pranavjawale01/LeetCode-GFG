class Solution:
    def minAddToMakeValid(self, s: str) -> int:
        open, close = 0, 0
        for c in s:
            if c is '(':
                open += 1
            else:
                if open == 0:
                    close += 1
                else:
                    open -= 1
        return open + close






# class Solution:
#     def minAddToMakeValid(self, s: str) -> int:
#         st = []
#         count = 0
#         for c in s:
#             if c is '(':
#                 st.append(c)
#             else:
#                 if not st:
#                     count += 1
#                 else:
#                     st.pop()
#         return len(st) + count