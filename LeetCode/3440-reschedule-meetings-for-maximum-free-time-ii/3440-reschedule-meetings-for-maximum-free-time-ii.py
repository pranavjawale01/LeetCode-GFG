class Solution:
    def maxFreeTime(self, eventTime: int, startTime: List[int], endTime: List[int]) -> int:
        n = len(startTime)
        diff = [0] * (n + 1)
        
        diff[0] = startTime[0]
        for i in range(1, n):
            diff[i] = startTime[i] - endTime[i - 1]
        diff[n] = eventTime - endTime[n - 1]
        
        m = len(diff)
        suffix = [0] * m
        prefix = [0] * m
        
        for i in range(m - 2, -1, -1):
            suffix[i] = max(suffix[i + 1], diff[i + 1])
        
        for i in range(2, m):
            prefix[i] = max(prefix[i - 1], diff[i - 2])
        
        ans = 0
        for i in range(1, m):
            meetingTime = endTime[i - 1] - startTime[i - 1]
            if meetingTime <= max(prefix[i], suffix[i]):
                ans = max(ans, diff[i - 1] + diff[i] + meetingTime)
            ans = max(ans, diff[i - 1] + diff[i])
        
        return ans