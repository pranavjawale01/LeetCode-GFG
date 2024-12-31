class Solution {
public:
    int dp[366];
    int solve(vector<int>& days, vector<int>& costs, int &n, int i) {
        if (i >= n) return 0;
        if (dp[i] != -1) return dp[i];
        int cost1 = costs[0] + solve(days, costs, n, i+1);
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
        return dp[i] = min({cost1, cost7, cost30});
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        memset(dp, -1, sizeof(dp));
        int n = days.size();
        return solve(days, costs, n, 0);
    }
};