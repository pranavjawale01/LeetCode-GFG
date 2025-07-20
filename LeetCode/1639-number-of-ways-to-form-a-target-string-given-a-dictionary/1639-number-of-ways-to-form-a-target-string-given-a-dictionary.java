class Solution {
    private static final int MOD = 1000000007;

    public int numWays(String[] words, String target) {
        int k = words[0].length();
        int m = target.length();
        long[][] freq = new long[26][k];
        
        for (int i = 0; i < k; i++) {
            for (String word : words) {
                freq[word.charAt(i) - 'a'][i]++;
            }
        }
        
        long[][] dp = new long[m + 1][k + 1];
        dp[0][0] = 1;

        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= k; j++) {
                if (j < k) {
                    dp[i][j + 1] = (dp[i][j + 1] + dp[i][j]) % MOD;
                    if (i < m && j < k) {
                        dp[i + 1][j + 1] = (dp[i + 1][j + 1] + freq[target.charAt(i) - 'a'][j] * dp[i][j]) % MOD;
                    }
                }
            }
        }

        return (int) dp[m][k];
    }
}








// class Solution {
//     public int[][] dp;
//     public int m, k;
//     public int MOD = 1000000000 + 7;

//     public int solve(int i, int j, long[][] freq, String target) {
//         if (i == m) return 1;
//         if (j == k) return 0;
//         if (dp[i][j] != -1) return dp[i][j];

//         long take = (freq[target.charAt(i) - 'a'][j] * solve(i+1, j+1, freq, target)) % MOD;
//         long nottake = solve(i, j+1, freq, target) % MOD;

//         return dp[i][j] = (int)((take + nottake) % MOD);
//     }

//     public int numWays(String[] words, String target) {
//         m = target.length();
//         k = words[0].length();
        
//         dp = new int[m+1][k+1];
//         for (int i = 0; i < m + 1; i++) {
//             Arrays.fill(dp[i], -1);
//         }

//         long[][] freq = new long[26][k];
//         for (int i = 0; i < k; i++) {
//             for (String x : words) {
//                 freq[x.charAt(i) - 'a'][i]++;
//             }
//         }

//         return solve(0, 0, freq, target);
//     }
// }