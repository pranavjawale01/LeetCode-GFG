class Solution {
    public long maxScore(int[] a, int[] b) {
        int row = a.length, col = b.length;
        long[][] dp = new long[row][col];
        
        for (int i = 0; i < row; i++) {
            Arrays.fill(dp[i], Long.MIN_VALUE);
        }

        for (int j = 0; j < col; j++) {
            dp[0][j] = (long) a[0] * b[j];
        }
        
        for (int i = 1; i < row; i++) {
            long maxAns = Long.MIN_VALUE;
            for (int j = i; j < col; j++) {
                maxAns = Math.max(maxAns, dp[i - 1][j - 1]);
                dp[i][j] = maxAns + (long) a[i] * b[j];
            }
        }
        
        long ans = Long.MIN_VALUE;
        for (int j = 0; j < col; j++) {
            ans = Math.max(ans, dp[row - 1][j]);
        }
        
        return ans;
    }
}