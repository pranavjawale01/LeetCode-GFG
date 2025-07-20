class Solution:
    def maxDotProduct(self, nums1: List[int], nums2: List[int]) -> int:
        n, m = len(nums1), len(nums2)
        dp = [[0]*(m) for i in range(n)]
        for i in range(n):
            for j in range(m):
                dp[i][j] = nums1[i] * nums2[j]
                if i > 0 and j > 0 :
                    dp[i][j] += max(dp[i-1][j-1],0)
                if i > 0:
                    dp[i][j] = max(dp[i][j],dp[i-1][j])
                if j > 0:
                    dp[i][j] = max(dp[i][j],dp[i][j-1])
        return dp[-1][-1]