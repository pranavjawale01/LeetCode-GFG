class Solution:
    def maxFreeTime(self, eventTime: int, k: int, startTime: List[int], endTime: List[int]) -> int:
        n = len(startTime)
        diff = [0] * (n + 1)
        diff[0] = startTime[0]
        diff[n] = eventTime - endTime[n - 1]
        
        for i in range(1, n):
            diff[i] = startTime[i] - endTime[i - 1]
        
        ans = 0
        for i in range(k + 1):
            ans += diff[i]
        
        temp = ans
        for i in range(k + 1, n + 1):
            temp += diff[i] - diff[i - k - 1]
            ans = max(ans, temp)
        
        return ans