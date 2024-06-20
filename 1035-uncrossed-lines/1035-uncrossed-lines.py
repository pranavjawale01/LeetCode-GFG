class Solution:
    def __init__(self):
        self.dp = [[-1] * 501 for _ in range(501)]

    def solve(self, nums1, nums2, i, j):
        if i < 0 or j < 0:
            return 0
        if self.dp[i][j] != -1:
            return self.dp[i][j]
        if nums1[i] == nums2[j]:
            self.dp[i][j] = 1 + self.solve(nums1, nums2, i - 1, j - 1)
        else:
            self.dp[i][j] = max(self.solve(nums1, nums2, i - 1, j), self.solve(nums1, nums2, i, j - 1))
        return self.dp[i][j]

    def maxUncrossedLines(self, nums1: List[int], nums2: List[int]) -> int:
        m, n = len(nums1), len(nums2)
        return self.solve(nums1, nums2, m - 1, n - 1)