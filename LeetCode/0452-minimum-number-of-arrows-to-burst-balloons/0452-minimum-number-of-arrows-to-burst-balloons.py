class Solution:
    def findMinArrowShots(self, points: List[List[int]]) -> int:
        n = len(points)
        points.sort()
        count = 1
        prevEnd = points[0][1]
        for i in range(1, n):
            if points[i][0] > prevEnd:
                count += 1
                prevEnd = points[i][1]
            else:
                prevEnd = min(prevEnd, points[i][1])
        return count