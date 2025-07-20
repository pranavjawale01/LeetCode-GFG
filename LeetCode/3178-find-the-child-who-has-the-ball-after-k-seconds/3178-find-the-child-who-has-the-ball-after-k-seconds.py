class Solution:
    def numberOfChild(self, n: int, k: int) -> int:
        n -= 1
        rounds = k // n
        rem = k % n
        if rounds % 2 == 0:
            return rem
        else:
            return n - rem

# class Solution:
#     def numberOfChild(self, n: int, k: int) -> int:
#         i = 0
#         flag = True
#         while k > 0:
#             if i == n - 1:
#                 flag = False
#             elif i == 0:
#                 flag = True
#             if flag:
#                 i += 1
#             else:
#                 i -= 1
#             k -= 1
#         return i