class Solution:
    def timeRequiredToBuy(self, tickets: List[int], k: int) -> int:
        i , n , time = 0, len(tickets), 0
        while tickets[k] > 0:
            if i >= n:
                i = 0
            if tickets[i] > 0:
                tickets[i] -= 1
                time += 1
            i += 1
        return time

# class Solution:
#     def timeRequiredToBuy(self, tickets: List[int], k: int) -> int:
#         maxVal , ans, n = tickets[k], 0, len(tickets)
#         for i in range(n):
#             if tickets[i] >= maxVal:
#                 if i <= k:
#                     ans += maxVal
#                 else:
#                     ans += maxVal - 1
#             else:
#                 ans += tickets[i]
#         return ans
        
# # class Solution:
# #     def timeRequiredToBuy(self, tickets: List[int], k: int) -> int:
# #         n = len(tickets)
# #         q = deque()
# #         for i in range(n):
# #             q.append(i)
# #         time = 0
# #         while True:
# #             if tickets[k] == 0:
# #                 break
# #             curr = q[0]
# #             tickets[curr] -= 1
# #             time += 1
# #             q.popleft()
# #             if tickets[curr] > 0:
# #                 q.append(curr)
# #         return time