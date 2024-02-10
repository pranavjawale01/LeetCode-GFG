class Solution:
    def __init__(self):
        self.count = 0
    
    def check(self, s: str, i: int, j: int, n: int) -> None:
        while i >= 0 and j < n and s[i] == s[j]:
            self.count += 1
            i -= 1
            j += 1
    
    def countSubstrings(self, s: str) -> int:
        n = len(s)
        self.count = 0
        for i in range(n):
            self.check(s, i, i, n)
            self.check(s, i, i + 1, n)
        return self.count

        
# class Solution:
#     def countSubstrings(self, s: str) -> int:
#         n = len(s)
#         t = [[False] * n for _ in range(n)]
#         count = 0
        
#         for L in range(1, n + 1):
#             for i in range(n - L + 1):
#                 j = i + L - 1
#                 if i == j:
#                     t[i][j] = True
#                 elif i + 1 == j:
#                     t[i][j] = (s[i] == s[j])
#                 else:
#                     t[i][j] = (s[i] == s[j] and t[i + 1][j - 1])
#                 if t[i][j]:
#                     count += 1
        
#         return count
        
# # class Solution:
# #     def __init__(self):
# #         self.t = [[-1] * 1001 for _ in range(1001)]
    
# #     def isPalindrome(self, s: str, start: int, end: int) -> bool:
# #         if start > end:
# #             return True
# #         if self.t[start][end] != -1:
# #             return self.t[start][end] == 1
# #         if s[start] == s[end]:
# #             self.t[start][end] = self.isPalindrome(s, start + 1, end - 1)
# #             return self.t[start][end] == 1
# #         self.t[start][end] = 0
# #         return False
    
# #     def countSubstrings(self, s: str) -> int:
# #         n = len(s)
# #         count = 0
# #         for i in range(n):
# #             for j in range(i, n):
# #                 if self.isPalindrome(s, i, j):
# #                     count += 1
# #         return count


# # # class Solution:
# # #     def isPalindrome(self, s: str, start: int, end: int) -> bool:
# # #         while start < end:
# # #             if s[start] != s[end]:
# # #                 return False
# # #             start += 1
# # #             end -= 1
# # #         return True
    
# # #     def countSubstrings(self, s: str) -> int:
# # #         n = len(s)
# # #         count = 0
# # #         for i in range(n):
# # #             for j in range(i, n):
# # #                 t = s[i:j + 1]
# # #                 if self.isPalindrome(s, i, j):
# # #                     count += 1
# # #         return count