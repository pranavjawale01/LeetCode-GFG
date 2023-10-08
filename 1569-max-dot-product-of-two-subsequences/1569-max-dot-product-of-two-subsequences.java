class Solution {
    public int maxDotProduct(int[] nums1, int[] nums2) {
        int n = nums1.length, m = nums2.length;
        int[][] dp = new int[n][m];
        int i=0,j=0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                dp[i][j] = nums1[i]*nums2[j];
                if(i>0 && j>0)
                {
                    dp[i][j] += Math.max(dp[i-1][j-1],0);
                }
                if(i>0)
                {
                    dp[i][j] = Math.max(dp[i][j],dp[i-1][j]);
                }
                if(j>0)
                {
                    dp[i][j] = Math.max(dp[i][j],dp[i][j-1]);
                }
            }
        }
        return dp[i-1][j-1];
    }
}