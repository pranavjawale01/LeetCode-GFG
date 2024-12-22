class Solution {
    private static final int MOD = 1000000007;
    private int[][][] dp;

    private int solve(int[][] grid, int i, int j, int x, int k) {
        int n = grid.length, m = grid[0].length;
        if (i >= n || j >= m) return 0;
        x ^= grid[i][j];
        if (dp[i][j][x] != -1) return dp[i][j][x];

        int ans = 0;
        if (i == n - 1 && j == m - 1 && x == k) {
            ans = 1;
        }
        ans = (ans + solve(grid, i + 1, j, x, k)) % MOD;
        ans = (ans + solve(grid, i, j + 1, x, k)) % MOD;

        return dp[i][j][x] = ans;
    }

    public int countPathsWithXorValue(int[][] grid, int k) {
        int n = grid.length, m = grid[0].length;
        dp = new int[n][m][16];
        for (int[][] layer : dp) {
            for (int[] row : layer) {
                Arrays.fill(row, -1);
            }
        }
        return solve(grid, 0, 0, 0, k);
    }
}