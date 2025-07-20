class Solution:
    def passThePillow(self, n: int, time: int) -> int:
        totalCycle = time // (n-1)
        timeLeft = time % (n-1)
        if totalCycle % 2 == 0:
            return timeLeft + 1
        return n - timeLeft





# class Solution:
#     def passThePillow(self, n: int, time: int) -> int:
#         idx, dir = 1, 1
#         while time > 0:
#             if idx + dir >= 1 and idx + dir <= n:
#                 idx += dir
#                 time -= 1
#             else:
#                 dir *= -1
#         return idx



# class Solution:
#     def passThePillow(self, n: int, time: int) -> int:
#         cycleLength = (n - 1) * 2
#         positionInCycle = time % cycleLength
#         if positionInCycle < n:
#             return positionInCycle + 1
#         return 2 * n - positionInCycle - 1