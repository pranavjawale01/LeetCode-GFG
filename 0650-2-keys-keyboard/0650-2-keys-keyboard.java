class Solution {
    public int[][] dp = new int[1001][1001];
    public int solve(int currA, int pasteA, int n) {
        if (currA == n) {
            return 0;
        }
        if (currA > n) {
            return 1000;
        }
        if (dp[currA][pasteA] != -1) {
            return dp[currA][pasteA];
        }
        int copyPaste = 2 + solve(currA + currA, currA, n);
        int paste = 1 + solve(currA + pasteA, pasteA, n);
        return dp[currA][pasteA] = Math.min(copyPaste, paste);
    }
    public int minSteps(int n) {
        if (n == 1) {
            return 0;
        }
        for (int i = 0; i < n; i++) {
            Arrays.fill(dp[i], -1);
        }
        return 1 + solve(1, 1, n);
    }
}