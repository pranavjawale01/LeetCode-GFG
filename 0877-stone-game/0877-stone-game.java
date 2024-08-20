class Solution {
    public boolean stoneGame(int[] piles) {
        int n = piles.length;
        int[] dp = new int[n];
        for (int i = 0; i < n; i++) {
            dp[i] = piles[i];
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n - i; j++) {
                dp[j] = Math.max(piles[j] - dp[j+1], piles[j+i] - dp[j]);
            }
        }
        return dp[0] > 0;
    }
}




// class Solution {
//     public boolean stoneGame(int[] piles) {
//         return true;
//     }
// }