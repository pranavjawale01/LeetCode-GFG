class Solution:
    def findNumberOfLIS(self, nums: List[int]) -> int:
        n = len(nums)
        if n == 0:
            return 0

        dp = [1] * n
        count = [1] * n

        for i in range(n):
            for j in range(i):
                if nums[i] > nums[j]:
                    if dp[i] == dp[j] + 1:
                        count[i] += count[j]
                    elif dp[i] < dp[j] + 1:
                        dp[i] = dp[j] + 1
                        count[i] = count[j]

        max_val = max(dp)
        result = sum(count[i] for i in range(n) if dp[i] == max_val)
        return result