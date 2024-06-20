class Solution:
    def findRightInterval(self, intervals: List[List[int]]) -> List[int]:
        n = len(intervals)
        ans = [-1] * n
        lis = sorted((interval[0], i) for i, interval in enumerate(intervals))
        starts = [interval[0] for interval in lis]
        
        for i, interval in enumerate(intervals):
            idx = bisect.bisect_left(starts, interval[1])
            if idx < n:
                ans[i] = lis[idx][1]
        
        return ans