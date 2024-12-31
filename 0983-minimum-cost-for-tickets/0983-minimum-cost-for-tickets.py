class Solution:
    def solve(self, days, costs, n, i, dp):
        if i >= n:
            return 0
        if dp[i] != -1:
            return dp[i]

        cost1 = costs[0] + self.solve(days, costs, n, i + 1, dp)

        idx = i
        while idx < n and days[idx] < days[i] + 7:
            idx += 1
        cost7 = costs[1] + self.solve(days, costs, n, idx, dp)

        jdx = i
        while jdx < n and days[jdx] < days[i] + 30:
            jdx += 1
        cost30 = costs[2] + self.solve(days, costs, n, jdx, dp)

        dp[i] = min(cost1, cost7, cost30)
        return dp[i]

    def mincostTickets(self, days: List[int], costs: List[int]) -> int:
        n = len(days)
        dp = [-1] * n
        return self.solve(days, costs, n, 0, dp)