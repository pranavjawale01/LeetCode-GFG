class Solution:
    def maxWidthOfVerticalArea(self, points: List[List[int]]) -> int:
        points.sort()
        wide = 0
        for i in range(len(points) - 1):
            if points[i+1][0] - points[i][0] > wide:
                wide = points[i+1][0] - points[i][0]
        return wide