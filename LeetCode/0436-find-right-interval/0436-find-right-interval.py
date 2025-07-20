class Solution:
    def binarySearch(self, vec: List[tuple], end: int) -> int:
        low, high = 0, len(vec) - 1
        ans = -1
        while low <= high:
            mid = low + (high - low) // 2
            if vec[mid][0] >= end:
                ans = vec[mid][1]
                high = mid - 1
            else:
                low = mid + 1
        return ans

    def findRightInterval(self, intervals: List[List[int]]) -> List[int]:
        n = len(intervals)
        vec = [(intervals[i][0], i) for i in range(n)]
        vec.sort()
        ans = [-1] * n
        for i in range(n):
            end = intervals[i][1]
            ans[i] = self.binarySearch(vec, end)
        return ans



# class Solution:
#     def findRightInterval(self, intervals: List[List[int]]) -> List[int]:
#         n = len(intervals)
#         ans = [-1] * n
#         lis = sorted((interval[0], i) for i, interval in enumerate(intervals))
#         starts = [interval[0] for interval in lis]
        
#         for i, interval in enumerate(intervals):
#             idx = bisect.bisect_left(starts, interval[1])
#             if idx < n:
#                 ans[i] = lis[idx][1]
        
#         return ans