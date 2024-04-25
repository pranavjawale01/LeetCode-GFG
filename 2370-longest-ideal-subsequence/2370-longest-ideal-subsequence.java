class Solution {
    public int longestIdealString(String s, int k) {
        int[] dp = new int[26];
        Arrays.fill(dp, 0);
        int n = s.length();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int idx = s.charAt(i) - 'a';
            int left = Math.max(0, idx - k);
            int right = Math.min(25, idx + k);
            int longest = 0;
            for (int j = left; j <= right; j++) {
                longest = Math.max(longest, dp[j]);
            }
            dp[idx] = Math.max(dp[idx], longest + 1);
            ans = Math.max(ans, dp[idx]);
        }
        return ans;
    }
}

// class Solution {
//     public int longestIdealString(String s, int k) {
//         int ans = Integer.MIN_VALUE;
//         int n = s.length();
//         int[] dp = new int[n];
//         Arrays.fill(dp, 1);
//         for (int i = 0; i < n; i++) {
//             for (int j = i - 1; j >= 0; j--) {
//                 if (Math.abs(s.charAt(i) - s.charAt(j)) <= k) {
//                     dp[i] = Math.max(dp[i], dp[j] + 1);
//                 }
//             }
//             ans = Math.max(dp[i], ans);
//         }
//         return ans;
//     }
// }