class Solution:
    def judgeSquareSum(self, c: int) -> bool:
        a = 0
        b = int(math.sqrt(c))

        while a <= b:
            k = a * a + b * b

            if k < c:
                a += 1
            elif k > c:
                b -= 1
            else:
                return True

        return False



# class Solution:
#     def judgeSquareSum(self, c: int) -> bool:
#         for a in range(int(c**0.5) + 1):
#             x = c - a * a
#             if self.binarySearch(0, x, x):
#                 return True
#         return False

#     def binarySearch(self, b_start: int, b_end: int, x: int) -> bool:
#         while b_start <= b_end:
#             mid = b_start + (b_end - b_start) // 2
#             if mid * mid == x:
#                 return True
#             elif mid * mid < x:
#                 b_start = mid + 1
#             else:
#                 b_end = mid - 1
#         return False



# class Solution:
#     def judgeSquareSum(self, c: int) -> bool:
#         a = 0
#         while a * a <= c:
#             b = sqrt(c - a * a)
#             if b == int(b):
#                 return True
#             a += 1
#         return False