class Solution:
    def __init__(self):
        self.dp = None

    def solve(self, nums, i, k, op1, op2):
        if i >= len(nums):
            return 0
        if self.dp[i][op1][op2] != -1:
            return self.dp[i][op1][op2]

        ans = nums[i] + self.solve(nums, i + 1, k, op1, op2)
        if op1 > 0:
            ans = min(ans, (nums[i] + 1) // 2 + self.solve(nums, i + 1, k, op1 - 1, op2))
        if op2 > 0 and nums[i] >= k:
            ans = min(ans, nums[i] - k + self.solve(nums, i + 1, k, op1, op2 - 1))
        if op1 > 0 and op2 > 0:
            div = (nums[i] + 1) // 2
            if div >= k:
                ans = min(ans, div - k + self.solve(nums, i + 1, k, op1 - 1, op2 - 1))
        if op1 > 0 and op2 > 0 and nums[i] >= k:
            sub = nums[i] - k
            ans = min(ans, (sub + 1) // 2 + self.solve(nums, i + 1, k, op1 - 1, op2 - 1))

        self.dp[i][op1][op2] = ans
        return ans

    def minArraySum(self, nums: List[int], k: int, op1: int, op2: int) -> int:
        n = len(nums)
        self.dp = [[[-1 for _ in range(op2 + 1)] for _ in range(op1 + 1)] for _ in range(n + 1)]
        return self.solve(nums, 0, k, op1, op2)        