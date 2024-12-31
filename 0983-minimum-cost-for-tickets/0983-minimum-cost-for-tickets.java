class Solution {
    int[] dp;

    private int solve(int[] days, int[] costs, int n, int i) {
        if (i >= n) return 0;
        if (dp[i] != -1) return dp[i];

        int cost1 = costs[0] + solve(days, costs, n, i + 1);

        int idx = i;
        while (idx < n && days[idx] < days[i] + 7) {
            idx++;
        }
        int cost7 = costs[1] + solve(days, costs, n, idx);

        int jdx = i;
        while (jdx < n && days[jdx] < days[i] + 30) {
            jdx++;
        }
        int cost30 = costs[2] + solve(days, costs, n, jdx);

        return dp[i] = Math.min(cost1, Math.min(cost7, cost30));
    }

    public int mincostTickets(int[] days, int[] costs) {
        int n = days.length;
        dp = new int[n];
        Arrays.fill(dp, -1);
        return solve(days, costs, n, 0);
    }
}