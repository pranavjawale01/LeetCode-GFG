class Solution:
    def losingPlayer(self, x: int, y: int) -> str:
        ans = min(x, y // 4)
        return "Alice" if ans % 2 == 1 else "Bob"



# class Solution:
#     def losingPlayer(self, x: int, y: int) -> str:
#         cnt = 0
#         while x > 0 and y > 3:
#             x -= 1
#             y -= 4
#             cnt += 1
#         return "Alice" if cnt % 2 == 1 else "Bob"




# class Solution:
#     def helper(self, x: int, y: int, curr: str) -> str:
#         if x <= 0 or y <= 3:
#             return curr
#         if curr == "Alice":
#             return self.helper(x - 1, y - 4, "Bob")
#         return self.helper(x - 1, y - 4, "Alice")

#     def losingPlayer(self, x: int, y: int) -> str:
#         return self.helper(x, y, "Bob")