class Solution:
    def maxSatisfied(self, customers: List[int], grumpy: List[int], minutes: int) -> int:
        maxUnSat = 0
        curUnSat = 0
        n = len(grumpy)
        for i in range(minutes):
            curUnSat += customers[i] * grumpy[i]
        maxUnSat = curUnSat
        i = 0
        j = minutes
        while j < n:
            curUnSat += customers[j] * grumpy[j]
            curUnSat -= customers[i] * grumpy[i]
            maxUnSat = max(maxUnSat, curUnSat)
            i += 1
            j += 1
        totalSat = maxUnSat
        for k in range(n):
            totalSat += customers[k] * (1 - grumpy[k])
        return totalSat



# class Solution:
#     def maxSatisfied(self, customers: List[int], grumpy: List[int], minutes: int) -> int:
#         n = len(grumpy)
#         ans = 0
#         for i in range(n):
#             if grumpy[i] == 0:
#                 ans += customers[i]
#         temp1 = ans
#         for i in range(n-minutes+1):
#             temp = temp1
#             for j in range(i, i+minutes):
#                 if grumpy[j] == 1:
#                     temp += customers[j]
#             ans = max(ans, temp)
#         return ans