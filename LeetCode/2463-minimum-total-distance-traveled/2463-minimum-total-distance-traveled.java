class Solution {
    public long minimumTotalDistance(List<Integer> robot, int[][] factory) {
        robot.sort(Integer::compareTo);
        Arrays.sort(factory, (a, b) -> Integer.compare(a[0], b[0]));

        int n = robot.size();
        int m = factory.length;
        
        long[][] dp = new long[m + 1][n + 1];
        for (int i = 0; i <= m; i++) {
            Arrays.fill(dp[i], Long.MAX_VALUE);
        }
        dp[0][0] = 0;

        for (int i = 1; i <= m; i++) {
            int factoryPos = factory[i - 1][0];
            int limit = factory[i - 1][1];
            for (int j = 0; j <= n; j++) {
                dp[i][j] = dp[i - 1][j];
                long distance = 0;
                for (int k = 1; k <= limit && j - k >= 0; k++) {
                    distance += Math.abs(robot.get(j - k) - factoryPos);
                    if (dp[i - 1][j - k] != Long.MAX_VALUE) {
                        dp[i][j] = Math.min(dp[i][j], dp[i - 1][j - k] + distance);
                    }
                }
            }
        }
        
        return dp[m][n];
    }
}







// class Solution {
//     private Long[][] dp;

//     private long solve(List<Integer> robot, int[][] factory, int ri, int fi) {
//         if (ri >= robot.size()) return 0;
//         if (fi >= factory.length) return Long.MAX_VALUE;
//         if (dp[ri][fi] != null) return dp[ri][fi];
        
//         long minDist = Long.MAX_VALUE, dist = 0;
//         for (int i = 0; i <= factory[fi][1] && ri + i <= robot.size(); i++) {
//             if (i > 0) {
//                 dist += Math.abs(robot.get(ri + i - 1) - factory[fi][0]);
//             }
//             long nxtDist = solve(robot, factory, ri + i, fi + 1);
//             if (nxtDist != Long.MAX_VALUE) {
//                 minDist = Math.min(minDist, dist + nxtDist);
//             }
//         }
//         return dp[ri][fi] = minDist;
//     }

//     public long minimumTotalDistance(List<Integer> robot, int[][] factory) {
//         Arrays.sort(factory, (a, b) -> Integer.compare(a[0], b[0]));
//         robot.sort(Integer::compareTo);
//         dp = new Long[robot.size()][factory.length];
//         return solve(robot, factory, 0, 0);
//     }
// }