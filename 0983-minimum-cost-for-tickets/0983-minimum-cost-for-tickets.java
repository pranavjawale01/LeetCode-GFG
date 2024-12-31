class Solution {
    public int mincostTickets(int[] days, int[] costs) {
        Set<Integer> travelDays = new HashSet<>();
        for (int day : days) {
            travelDays.add(day);
        }

        int lastDay = days[days.length - 1];
        int[] dp = new int[lastDay + 1];
        dp[0] = 0;

        for (int i = 1; i <= lastDay; i++) {
            if (!travelDays.contains(i)) {
                dp[i] = dp[i - 1];
                continue;
            }

            int day1 = dp[Math.max(0, i - 1)] + costs[0];
            int day7 = dp[Math.max(0, i - 7)] + costs[1];
            int day30 = dp[Math.max(0, i - 30)] + costs[2];

            dp[i] = Math.min(day1, Math.min(day7, day30));
        }

        return dp[lastDay];
    }
}







// class Solution {
//     int[] dp;

//     private int solve(int[] days, int[] costs, int n, int i) {
//         if (i >= n) return 0;
//         if (dp[i] != -1) return dp[i];

//         int cost1 = costs[0] + solve(days, costs, n, i + 1);

//         int idx = i;
//         while (idx < n && days[idx] < days[i] + 7) {
//             idx++;
//         }
//         int cost7 = costs[1] + solve(days, costs, n, idx);

//         int jdx = i;
//         while (jdx < n && days[jdx] < days[i] + 30) {
//             jdx++;
//         }
//         int cost30 = costs[2] + solve(days, costs, n, jdx);

//         return dp[i] = Math.min(cost1, Math.min(cost7, cost30));
//     }

//     public int mincostTickets(int[] days, int[] costs) {
//         int n = days.length;
//         dp = new int[n];
//         Arrays.fill(dp, -1);
//         return solve(days, costs, n, 0);
//     }
// }