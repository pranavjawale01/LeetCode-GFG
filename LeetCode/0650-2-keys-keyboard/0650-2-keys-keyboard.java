class Solution {
    public int minSteps(int n) {
        if (n == 1) {
            return 0;
        }
        if (n == 2) {
            return 2;
        }
        int[] dp = new int[n+1];
        dp[0] = 0;
        dp[1] = 0;
        dp[2] = 2;
        for (int i = 3; i <= n; i++) {
            int factor = i / 2;
            while (factor >= 1) {
                if (i % factor == 0) {
                    int stepsToPrintFactorAs = dp[factor];
                    int copy = 1;
                    int paste = (i / factor) - 1;
                    dp[i] = stepsToPrintFactorAs + copy + paste;
                    break;
                } else {
                    factor--;
                }
            }
        }
        return dp[n];
    }
}



// class Solution {
//     public int[][] dp = new int[1001][1001];
//     public int solve(int currA, int pasteA, int n) {
//         if (currA == n) {
//             return 0;
//         }
//         if (currA > n) {
//             return 1000;
//         }
//         if (dp[currA][pasteA] != -1) {
//             return dp[currA][pasteA];
//         }
//         int copyPaste = 2 + solve(currA + currA, currA, n);
//         int paste = 1 + solve(currA + pasteA, pasteA, n);
//         return dp[currA][pasteA] = Math.min(copyPaste, paste);
//     }
//     public int minSteps(int n) {
//         if (n == 1) {
//             return 0;
//         }
//         for (int i = 0; i < n; i++) {
//             Arrays.fill(dp[i], -1);
//         }
//         return 1 + solve(1, 1, n);
//     }
// }