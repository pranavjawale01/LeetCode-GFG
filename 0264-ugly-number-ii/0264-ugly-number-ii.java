class Solution {
    public int nthUglyNumber(int n) {
        int[] dp = new int[n+1];
        int i2, i3, i5;
        i2 = i3 = i5 = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            int i2_temp = dp[i2]* 2;
            int i3_temp = dp[i3]*3;
            int i5_temp = dp[i5]*5;
            dp[i] = Math.min(i2_temp, Math.min(i3_temp, i5_temp));
            if (dp[i] == i2_temp) {
                i2++;
            }
            if (dp[i] == i3_temp) {
                i3++;
            }
            if (dp[i] == i5_temp) {
                i5++;
            }
        }
        return dp[n];
    }
}