class Solution {
    int n;
    long[][] dp;

    public long solve(int i, int j, int[] a, int[] b) {
        if (i >= n) {
            return 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        long ans = (j == 0) ? a[i] : b[i];
        ans += Math.max(solve(i + 1, j, a, b), solve(i + 2, 1 - j, a, b));
        return dp[i][j] = ans;
    }

    public long maxEnergyBoost(int[] energyDrinkA, int[] energyDrinkB) {
        n = energyDrinkA.length;
        dp = new long[n][2];
        for (long[] row : dp) {
            Arrays.fill(row, -1);
        }
        return Math.max(solve(0, 0, energyDrinkA, energyDrinkB), solve(0, 1, energyDrinkA, energyDrinkB));
    }
}