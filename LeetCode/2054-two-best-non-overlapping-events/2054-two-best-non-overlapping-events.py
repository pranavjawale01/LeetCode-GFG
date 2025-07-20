class Solution:
    def __init__(self):
        self.n = 0
        self.dp = [[-1] * 3 for _ in range(100001)]

    def binarySearch(self, events, endTime):
        l, r, ans = 0, self.n - 1, self.n
        while l <= r:
            mid = l + (r - l) // 2
            if events[mid][0] > endTime:
                ans = mid
                r = mid - 1
            else:
                l = mid + 1
        return ans

    def solve(self, events, i, count):
        if count == 2 or i >= self.n:
            return 0
        if self.dp[i][count] != -1:
            return self.dp[i][count]

        nextValidEventIndex = self.binarySearch(events, events[i][1])
        take = events[i][2] + self.solve(events, nextValidEventIndex, count + 1)
        notTake = self.solve(events, i + 1, count)
        self.dp[i][count] = max(take, notTake)
        return self.dp[i][count]

    def maxTwoEvents(self, events: List[List[int]]) -> int:
        self.n = len(events)
        events.sort()
        self.dp = [[-1] * 3 for _ in range(self.n)]
        return self.solve(events, 0, 0)