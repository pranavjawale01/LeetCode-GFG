class Solution {
public:
    vector<vector<long long>> dp;

    long long solve(vector<int>& robot, vector<vector<int>>& factory, int ri, int fi) {
        if (ri >= robot.size()) return 0;
        if (fi >= factory.size()) return LLONG_MAX;
        if (dp[ri][fi] != -1) {
            return dp[ri][fi];
        }
        long long minDist = LLONG_MAX, dist = 0;
        for (int i = 0; i <= factory[fi][1] && ri + i <= robot.size(); i++) {
            if (i > 0) {
                dist += abs(robot[ri + i - 1] - factory[fi][0]);
            }
            long long nxtDist = solve(robot, factory, ri + i, fi + 1);
            if (nxtDist != LLONG_MAX) {
                minDist = min(minDist, dist + nxtDist);
            }
        }
        return dp[ri][fi] = minDist;
    }

    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());
        dp.resize(robot.size(), vector<long long>(factory.size(), -1));
        return solve(robot, factory, 0, 0);
    }
};