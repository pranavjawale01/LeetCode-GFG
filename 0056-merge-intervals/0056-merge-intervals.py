class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        if not intervals:
            return []
        intervals.sort()
        
        result = [intervals[0]]
        
        for interval in intervals[1:]:
            if result[-1][1] >= interval[0]:
                result[-1][1] = max(result[-1][1], interval[1])
            else:
                result.append(interval)
        
        return result