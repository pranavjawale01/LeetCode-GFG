class Solution:
    def longestObstacleCourseAtEachPosition(self, obstacles: List[int]) -> List[int]:
        n = len(obstacles)
        lis = []
        result = []

        for obstacle in obstacles:
            if not lis or obstacle >= lis[-1]:
                lis.append(obstacle)
                result.append(len(lis))
            else:
                idx = bisect_right(lis, obstacle)
                lis[idx] = obstacle
                result.append(idx + 1)

        return result