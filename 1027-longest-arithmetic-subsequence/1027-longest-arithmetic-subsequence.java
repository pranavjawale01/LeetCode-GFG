class Solution {
    public int longestArithSeqLength(int[] nums) {
        int n = nums.length;
        if (n <= 2) {
            return n;
        }
        int[][] dp = new int[n][1001];
        int ans = 0;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                int diff = nums[i] - nums[j] + 500;
                dp[i][diff] = dp[j][diff] > 0 ? dp[j][diff] + 1 : 2;
                ans = Math.max(ans, dp[i][diff]);
            }
        }
        return ans;
    }
}



// class Solution {
//     private int[][] dp;

//     public int longestArithSeqLength(int[] nums) {
//         int n = nums.length;
//         if (n <= 2) {
//             return n;
//         }

//         int maxDiff = 500;
//         dp = new int[n][2 * maxDiff + 1];

//         for (int i = 0; i < n; i++) {
//             Arrays.fill(dp[i], 1);
//         }

//         int ans = 2;

//         for (int i = 1; i < n; i++) {
//             for (int j = 0; j < i; j++) {
//                 int diff = nums[i] - nums[j] + maxDiff;
//                 dp[i][diff] = dp[j][diff] + 1;
//                 ans = Math.max(ans, dp[i][diff]);
//             }
//         }

//         return ans;
//     }
// }