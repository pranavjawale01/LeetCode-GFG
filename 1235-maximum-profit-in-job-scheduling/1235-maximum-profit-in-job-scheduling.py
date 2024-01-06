class Solution:
    def jobScheduling(self, startTime: List[int], endTime: List[int], profit: List[int]) -> int:
        jobs = sorted(zip(startTime, endTime, profit), key=lambda x: x[1])
        dp = [(0, 0)]

        for start, end, p in jobs:
            idx = bisect.bisect(dp, (start + 1, 0)) - 1
            max_profit = max(dp[idx][1] + p, dp[-1][1])
            dp.append((end, max_profit))

        return dp[-1][1]