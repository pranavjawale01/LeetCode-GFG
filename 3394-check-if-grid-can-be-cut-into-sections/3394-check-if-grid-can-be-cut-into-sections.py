class Solution:
    def checkValidCuts(self, n: int, rectangles: List[List[int]]) -> bool:
        vertical = []
        horizontal = []

        for rect in rectangles:
            vertical.append([rect[1], rect[3]])
            horizontal.append([rect[0], rect[2]])

        def solve(intervals):
            if len(intervals) <= 1:
                return intervals
            intervals.sort()
            merged = [intervals[0]]
            for i in range(1, len(intervals)):
                if intervals[i][0] < merged[-1][1]:
                    merged[-1][1] = max(merged[-1][1], intervals[i][1])
                else:
                    merged.append(intervals[i])
            return merged

        arr = solve(vertical)
        brr = solve(horizontal)

        return len(arr) >= 3 or len(brr) >= 3