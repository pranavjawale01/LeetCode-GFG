class Solution {
    private int[][][] dp;
    private int n;

    public int solve(int[] piles, int person, int i, int M) {
        if (i >= n) {
            return 0;
        }
        if (dp[person][i][M] != -1) {
            return dp[person][i][M];
        }
        
        int result = (person == 1) ? -1 : Integer.MAX_VALUE;
        int stones = 0;

        for (int x = 1; x <= Math.min(2 * M, n - i); x++) {
            stones += piles[i + x - 1];
            if (person == 1) {
                result = Math.max(result, stones + solve(piles, 0, i + x, Math.max(M, x)));
            } else {
                result = Math.min(result, solve(piles, 1, i + x, Math.max(M, x)));
            }
        }
        dp[person][i][M] = result;
        return result;
    }

    public int stoneGameII(int[] piles) {
        n = piles.length;
        dp = new int[2][n][n+1];

        for (int[][] layer : dp) {
            for (int[] row : layer) {
                Arrays.fill(row, -1);
            }
        }

        return solve(piles, 1, 0, 1);
    }
}