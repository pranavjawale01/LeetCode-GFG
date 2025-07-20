class Solution:
    def minTimeToVisitAllPoints(self, points: List[List[int]]) -> int:
        total_time = 0

        for i in range(1, len(points)):
            x_diff = abs(points[i][0] - points[i - 1][0])
            y_diff = abs(points[i][1] - points[i - 1][1])

            diagonal_moves = max(x_diff, y_diff)
            total_time += diagonal_moves

        return total_time