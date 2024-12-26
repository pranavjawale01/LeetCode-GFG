class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        total_sum = sum(nums)
        dp = [[-1 for _ in range(2 * total_sum + 1)] for _ in range(len(nums) + 1)]
        return self.solve(nums, target, 0, 0, dp, total_sum)

    def solve(self, nums, target, i, curr_sum, dp, offset):
        if i == len(nums):
            return 1 if curr_sum == target else 0
        if dp[i][curr_sum + offset] != -1:
            return dp[i][curr_sum + offset]
        plus = self.solve(nums, target, i + 1, curr_sum + nums[i], dp, offset)
        minus = self.solve(nums, target, i + 1, curr_sum - nums[i], dp, offset)
        dp[i][curr_sum + offset] = plus + minus
        return dp[i][curr_sum + offset]