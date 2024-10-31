class Solution:
    def minimumTotalDistance(self, robot: List[int], factory: List[List[int]]) -> int:
        robot.sort()
        factory.sort()

        @lru_cache(None)
        def solve(ri: int, fi: int) -> int:
            if ri >= len(robot): 
                return 0
            if fi >= len(factory): 
                return float('inf')

            min_dist = float('inf')
            dist = 0
            for i in range(factory[fi][1] + 1):
                if ri + i > len(robot):
                    break
                if i > 0:
                    dist += abs(robot[ri + i - 1] - factory[fi][0])
                min_dist = min(min_dist, dist + solve(ri + i, fi + 1))
                
            return min_dist

        return solve(0, 0)