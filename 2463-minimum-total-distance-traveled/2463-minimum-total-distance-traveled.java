class Solution {
    private Long[][] dp;

    private long solve(List<Integer> robot, int[][] factory, int ri, int fi) {
        if (ri >= robot.size()) return 0;
        if (fi >= factory.length) return Long.MAX_VALUE;
        if (dp[ri][fi] != null) return dp[ri][fi];
        
        long minDist = Long.MAX_VALUE, dist = 0;
        for (int i = 0; i <= factory[fi][1] && ri + i <= robot.size(); i++) {
            if (i > 0) {
                dist += Math.abs(robot.get(ri + i - 1) - factory[fi][0]);
            }
            long nxtDist = solve(robot, factory, ri + i, fi + 1);
            if (nxtDist != Long.MAX_VALUE) {
                minDist = Math.min(minDist, dist + nxtDist);
            }
        }
        return dp[ri][fi] = minDist;
    }

    public long minimumTotalDistance(List<Integer> robot, int[][] factory) {
        Arrays.sort(factory, (a, b) -> Integer.compare(a[0], b[0]));
        robot.sort(Integer::compareTo);
        dp = new Long[robot.size()][factory.length];
        return solve(robot, factory, 0, 0);
    }
}