class Solution:
    def __init__(self):
        self.t = [[-1] * 1001 for _ in range(1001)]
    
    def isPalindrome(self, s: str, start: int, end: int) -> bool:
        if start > end:
            return True
        if self.t[start][end] != -1:
            return self.t[start][end] == 1
        if s[start] == s[end]:
            self.t[start][end] = self.isPalindrome(s, start + 1, end - 1)
            return self.t[start][end] == 1
        self.t[start][end] = 0
        return False
    
    def countSubstrings(self, s: str) -> int:
        n = len(s)
        count = 0
        for i in range(n):
            for j in range(i, n):
                if self.isPalindrome(s, i, j):
                    count += 1
        return count


# class Solution:
#     def isPalindrome(self, s: str, start: int, end: int) -> bool:
#         while start < end:
#             if s[start] != s[end]:
#                 return False
#             start += 1
#             end -= 1
#         return True
    
#     def countSubstrings(self, s: str) -> int:
#         n = len(s)
#         count = 0
#         for i in range(n):
#             for j in range(i, n):
#                 t = s[i:j + 1]
#                 if self.isPalindrome(s, i, j):
#                     count += 1
#         return count