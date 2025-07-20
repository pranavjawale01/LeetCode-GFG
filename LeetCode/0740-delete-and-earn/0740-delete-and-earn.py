class Solution:
    def deleteAndEarn(self, nums: List[int]) -> int:
        n = 10001
        count = [0] * n
        for num in nums:
            count[num] += num
        dp = [0] * n
        dp[1] = count[1]
        for i in range(2, n):
            dp[i] = max(count[i] + dp[i-2], dp[i-1])
        return dp[n-1]