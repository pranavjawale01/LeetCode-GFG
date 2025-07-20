class Solution:
    def minimumDeletions(self, s: str) -> int:
        n = len(s)
        counta = 0
        for i in range(n - 1, -1, -1):
            if s[i] == 'a':
                counta += 1
        
        count = float('inf')
        countb = 0
        for i in range(n):
            if s[i] == 'a':
                counta -= 1
            count = min(count, countb + counta)
            if s[i] == 'b':
                countb += 1
        
        return count





# class Solution:
#     def minimumDeletions(self, s: str) -> int:
#         n = len(s)
#         right_a = [0] * n
#         counta = 0
        
#         for i in range(n - 1, -1, -1):
#             right_a[i] = counta
#             if s[i] == 'a':
#                 counta += 1
        
#         count = float('inf')
#         countb = 0
        
#         for i in range(n):
#             count = min(count, countb + right_a[i])
#             if s[i] == 'b':
#                 countb += 1
        
#         return count







# class Solution:
#     def minimumDeletions(self, s: str) -> int:
#         n = len(s)
#         left_b = [0] * n
#         right_a = [0] * n
        
#         countb = 0
#         for i in range(n):
#             left_b[i] = countb
#             if s[i] == 'b':
#                 countb += 1
        
#         counta = 0
#         for i in range(n - 1, -1, -1):
#             right_a[i] = counta
#             if s[i] == 'a':
#                 counta += 1
        
#         count = float('inf')
#         for i in range(n):
#             count = min(count, left_b[i] + right_a[i])
        
#         return count







# class Solution:
#     def minimumDeletions(self, s: str) -> int:
#         n = len(s)
#         count = 0
#         stack = []
        
#         for i in range(n):
#             if stack and s[i] == 'a' and stack[-1] == 'b':
#                 stack.pop()
#                 count += 1
#             else:
#                 stack.append(s[i])
        
#         return count