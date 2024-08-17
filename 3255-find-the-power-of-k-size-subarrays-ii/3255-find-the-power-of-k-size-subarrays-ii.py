class Solution:
    def resultsArray(self, nums: List[int], k: int) -> List[int]:
        n = len(nums)
        dp = [1] * n
        ans = [-1] * (n - k + 1)
        for i in range(1, n):
            if nums[i] == nums[i-1] + 1:
                dp[i] = dp[i-1] + 1
        i , j = k - 1, 0
        while i < n:
            if dp[i] >= k:
                ans[j] = nums[i]
            i += 1
            j += 1
        return ans