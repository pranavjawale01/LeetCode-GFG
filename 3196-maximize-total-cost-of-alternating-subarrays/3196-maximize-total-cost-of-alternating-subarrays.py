class Solution:
    def maximumTotalCost(self, nums: List[int]) -> int:
        n = len(nums)
        dp = [-float('inf')] * (n+1)
        dp[0] = 0
        dp[1] = nums[0]
        for i in range(1, n):
            dp[i+1] = max(dp[i]+nums[i], dp[i-1] + nums[i-1] - nums[i])
        return dp[n]




# class Solution:
#     def maximumTotalCost(self, nums: List[int]) -> int:
#         n = len(nums)
#         dp = [[-1, -1] for _ in range(n)]

#         def solve(idx: int, pos: bool) -> int:
#             if idx >= n:
#                 return 0

#             if dp[idx][pos] != -1:
#                 return dp[idx][pos]

#             if pos:
#                 dp[idx][pos] = nums[idx] + solve(idx + 1, False)
#             else:
#                 take = solve(idx + 1, True) - nums[idx]
#                 not_take = solve(idx + 1, False) + nums[idx]
#                 dp[idx][pos] = max(take, not_take)

#             return dp[idx][pos]

#         return solve(0, True)