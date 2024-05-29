class Solution:
    def numSteps(self, s: str) -> int:
        n = len(s)
        op = 0
        carry = 0
        for i in range(n-1, 0, -1):
            if (int(s[i]) + carry) % 2 == 1:
                op += 2
                carry = 1
            else:
                op += 1
        return op + carry


# class Solution:
#     def numSteps(self, s: str) -> int:
#         count = 0
#         while s != "1":
#             if s[-1] == '0':
#                 s = s[:-1]
#             else:
#                 i = len(s) - 1
#                 while i >= 0 and s[i] == '1':
#                     i -= 1
#                 if i >= 0:
#                     s = s[:i] + '1' + '0' * (len(s) - i - 1)
#                 else:
#                     s = '1' + '0' * len(s)
#             count += 1
#         return count