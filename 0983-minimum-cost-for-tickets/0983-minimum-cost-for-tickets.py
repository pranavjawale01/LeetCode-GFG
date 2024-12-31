class Solution:
    def mincostTickets(self, days: List[int], costs: List[int]) -> int:
        travel_days = set(days)
        last_day = days[-1]
        dp = [0] * (last_day + 1)

        for i in range(1, last_day + 1):
            if i not in travel_days:
                dp[i] = dp[i - 1]
                continue

            day1 = dp[max(0, i - 1)] + costs[0]
            day7 = dp[max(0, i - 7)] + costs[1]
            day30 = dp[max(0, i - 30)] + costs[2]

            dp[i] = min(day1, day7, day30)

        return dp[last_day]





# class Solution:
#     def solve(self, days, costs, n, i, dp):
#         if i >= n:
#             return 0
#         if dp[i] != -1:
#             return dp[i]

#         cost1 = costs[0] + self.solve(days, costs, n, i + 1, dp)

#         idx = i
#         while idx < n and days[idx] < days[i] + 7:
#             idx += 1
#         cost7 = costs[1] + self.solve(days, costs, n, idx, dp)

#         jdx = i
#         while jdx < n and days[jdx] < days[i] + 30:
#             jdx += 1
#         cost30 = costs[2] + self.solve(days, costs, n, jdx, dp)

#         dp[i] = min(cost1, cost7, cost30)
#         return dp[i]

#     def mincostTickets(self, days: List[int], costs: List[int]) -> int:
#         n = len(days)
#         dp = [-1] * n
#         return self.solve(days, costs, n, 0, dp)