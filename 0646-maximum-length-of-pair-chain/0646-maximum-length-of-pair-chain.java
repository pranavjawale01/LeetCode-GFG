class Solution {
    public int findLongestChain(int[][] pairs) {
        int n = pairs.length;
        Arrays.sort(pairs, (a, b) -> Integer.compare(a[1], b[1]));
        int[] dp = new int[n];
        Arrays.fill(dp, 1);
        int len = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (pairs[i][0] > pairs[j][1]) {
                    dp[i] = Math.max(dp[i], dp[j] + 1);
                    len = Math.max(len, dp[i]);
                }
            }
        }
        return len;
    }
}



// class Solution {
//     private int n;
//     private int[][] dp;
    
//     private int solve(int[][] pairs, int prev, int i) {
//         if (i == n) {
//             return 0;
//         }
//         if (prev != -1 && dp[prev][i] != -1) {
//             return dp[prev][i];
//         }
//         int taken = 0;
//         if (prev == -1 || pairs[i][0] > pairs[prev][1]) {
//             taken = 1 + solve(pairs, i, i + 1);
//         }
//         int notTaken = solve(pairs, prev, i + 1);
//         if (prev != -1) {
//             dp[prev][i] = Math.max(notTaken, taken);
//         }
//         return Math.max(taken, notTaken);
//     }

//     public int findLongestChain(int[][] pairs) {
//         n = pairs.length;
//         dp = new int[n][n];
        
//         for (int i = 0; i < n; i++) {
//             Arrays.fill(dp[i], -1);
//         }

//         Arrays.sort(pairs, (a, b) -> Integer.compare(a[1], b[1]));
        
//         return solve(pairs, -1, 0);
//     }
// }