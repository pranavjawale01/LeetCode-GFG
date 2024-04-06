class Solution:
    def minRemoveToMakeValid(self, s: str) -> str:
        open_count = 0
        temp = ""

        for c in s:
            if c == '(':
                open_count += 1
            elif c == ')':
                if open_count == 0:
                    continue
                open_count -= 1

            temp += c

        n = len(temp)
        result = ""
        for i in range(n - 1, -1, -1):
            if temp[i] == '(' and open_count > 0:
                open_count -= 1
                continue
            result += temp[i]

        return result[::-1]
        
# class Solution:
#     def minRemoveToMakeValid(self, s: str) -> str:
#         st = []
#         n = len(s)
#         idx = set()
#         for i in range(n):
#             if s[i] == '(':
#                 st.append(i)
#             elif s[i] == ')':
#                 if st and s[st[-1]] == '(':
#                     st.pop()
#                 else:
#                     idx.add(i)
#         idx.update(st)
#         ans = ""
#         for i in range(n):
#             if i not in idx:
#                 ans += s[i]
#         return ans