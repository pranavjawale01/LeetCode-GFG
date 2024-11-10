class Solution:
    def maxIncreasingSubarrays(self, nums: List[int]) -> int:
        n = len(nums)
        dp = [1] * n

        for i in range(n - 2, -1, -1):
            if nums[i] < nums[i + 1]:
                dp[i] = dp[i + 1] + 1

        ans = 0
        low, high = 1, n // 2

        while low <= high:
            flag = False
            mid = low + (high - low) // 2
            for i in range(n - 2 * mid + 1):
                if dp[i] >= mid and dp[i + mid] >= mid:
                    flag = True
                    break
            if flag:
                low = mid + 1
                ans = max(ans, mid)
            else:
                high = mid - 1

        return ans