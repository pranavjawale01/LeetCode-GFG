class Solution {
    private int[][] dp = new int[501][501];
    private int solve(int[] nums1, int[] nums2, int i, int j) {
        if (i < 0 || j < 0) {
            return 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        if (nums1[i] == nums2[j]) {
            return dp[i][j] = 1 + solve(nums1, nums2, i-1, j-1);
        }
        return dp[i][j] = Math.max(solve(nums1, nums2, i-1, j), solve(nums1, nums2, i, j-1));
    }
    public int maxUncrossedLines(int[] nums1, int[] nums2) {
        int m = nums1.length, n = nums2.length;
        for (int i = 0; i < m; i++) {
            Arrays.fill(dp[i], -1);
        }
        return solve(nums1, nums2, m-1, n-1);
    }
}