class Solution:
    def rob(self, nums: List[int]) -> int:
        n = len(nums)
        if n == 1:
            return nums[0]
        if n == 2:
            return max(nums[0], nums[1])
        
        def solve(nums):
            memo = [-1] * len(nums)
            def dp(i):
                if i >= len(nums):
                    return 0
                if memo[i] != -1:
                    return memo[i]
                take = nums[i] + dp(i + 2)
                skip = dp(i + 1)
                memo[i] = max(take, skip)
                return memo[i]
            return dp(0)
        
        zero = solve(nums[:-1])
        one = solve(nums[1:])
        
        return max(zero, one)