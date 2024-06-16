class Solution:
    def countCompleteDayPairs(self, hours: List[int]) -> int:
        mp = {}
        count = 0
        for hour in hours:
            mod = hour % 24
            com = (24 - hour) % 24
            if com in mp:
                count += mp[com]
            if mod in mp:
                mp[mod] += 1
            else:
                mp[mod] = 1
        return count



# class Solution:
#     def countCompleteDayPairs(self, hours: List[int]) -> int:
#         n = len(hours)
#         count = 0
#         for i in range(n-1):
#             for j in range(i+1, n):
#                 if (hours[i] + hours[j]) % 24 == 0:
#                     count += 1
#         return count