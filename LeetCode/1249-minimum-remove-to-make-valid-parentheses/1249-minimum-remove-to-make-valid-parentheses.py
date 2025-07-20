class Solution:
    def minRemoveToMakeValid(self, s: str) -> str:
        result = []
        n = len(s)

        last_open = 0
        for i in range(n):
            c = s[i]
            if c.islower():
                result.append(c)
            elif c == '(':
                result.append(c)
                last_open += 1
            elif last_open > 0:
                last_open -= 1
                result.append(c)

        if not result:
            return ""

        s = ''.join(result)
        result = []
        last_close = 0
        n = len(s)

        for i in range(n - 1, -1, -1):
            c = s[i]
            if c.islower():
                result.append(c)
            elif c == ')':
                result.append(c)
                last_close += 1
            elif last_close > 0:
                last_close -= 1
                result.append(c)

        return ''.join(result[::-1])


# class Solution:
#     def minRemoveToMakeValid(self, s: str) -> str:
#         open_count = 0
#         temp = ""

#         for c in s:
#             if c == '(':
#                 open_count += 1
#             elif c == ')':
#                 if open_count == 0:
#                     continue
#                 open_count -= 1

#             temp += c

#         n = len(temp)
#         result = ""
#         for i in range(n - 1, -1, -1):
#             if temp[i] == '(' and open_count > 0:
#                 open_count -= 1
#                 continue
#             result += temp[i]

#         return result[::-1]
        
# # class Solution:
# #     def minRemoveToMakeValid(self, s: str) -> str:
# #         st = []
# #         n = len(s)
# #         idx = set()
# #         for i in range(n):
# #             if s[i] == '(':
# #                 st.append(i)
# #             elif s[i] == ')':
# #                 if st and s[st[-1]] == '(':
# #                     st.pop()
# #                 else:
# #                     idx.add(i)
# #         idx.update(st)
# #         ans = ""
# #         for i in range(n):
# #             if i not in idx:
# #                 ans += s[i]
# #         return ans