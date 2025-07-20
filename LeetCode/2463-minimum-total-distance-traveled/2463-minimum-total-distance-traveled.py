class Solution:
    def minimumTotalDistance(self, robot: List[int], factory: List[List[int]]) -> int:
        robot.sort()
        factory.sort()
        n = len(robot)
        m = len(factory)
        
        dp = [[float('inf')] * (n + 1) for _ in range(m + 1)]
        dp[0][0] = 0

        for i in range(1, m + 1):
            factory_pos = factory[i - 1][0]
            limit = factory[i - 1][1]
            for j in range(n + 1):
                dp[i][j] = dp[i - 1][j]
                distance = 0
                for k in range(1, limit + 1):
                    if j - k >= 0:
                        distance += abs(robot[j - k] - factory_pos)
                        if dp[i - 1][j - k] != float('inf'):
                            dp[i][j] = min(dp[i][j], dp[i - 1][j - k] + distance)
        
        return dp[m][n]








# class Solution:
#     def minimumTotalDistance(self, robot: List[int], factory: List[List[int]]) -> int:
#         robot.sort()
#         factory.sort()

#         @lru_cache(None)
#         def solve(ri: int, fi: int) -> int:
#             if ri >= len(robot): 
#                 return 0
#             if fi >= len(factory): 
#                 return float('inf')

#             min_dist = float('inf')
#             dist = 0
#             for i in range(factory[fi][1] + 1):
#                 if ri + i > len(robot):
#                     break
#                 if i > 0:
#                     dist += abs(robot[ri + i - 1] - factory[fi][0])
#                 min_dist = min(min_dist, dist + solve(ri + i, fi + 1))
                
#             return min_dist

#         return solve(0, 0)