class Solution:
    def minBitFlips(self, start: int, goal: int) -> int:
        ans = start ^ goal
        count = 0
        while ans:
            count += ans & 1
            ans >>= 1
        return count





# class Solution:
#     def minBitFlips(self, start: int, goal: int) -> int:
#         return bin(start ^ goal).count('1')




# class Solution:
#     def minBitFlips(self, start: int, goal: int) -> int:
#         count = 0
#         for _ in range(32):
#             if (start & 1) != (goal & 1):
#                 count += 1
#             start >>= 1
#             goal >>= 1
#         return count