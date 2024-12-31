class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        unordered_set<int> st(days.begin(), days.end());
        int last_day = days.back();
        vector<int> dp(last_day + 1, 0);
        dp[0] = 0;
        for (int i = 1; i <= last_day; i++) {
            if (st.find(i) == st.end()) {
                dp[i] = dp[i-1];
                continue;
            }
            dp[i] = INT_MAX;
            int day1 = dp[max(0, i-1)] + costs[0];
            int day7 = dp[max(0, i-7)] + costs[1];
            int day30 = dp[max(0, i-30)] + costs[2];
            dp[i] = min({day1, day7, day30});
        }
        return dp[last_day];
    }
};








// class Solution {
// public:
//     int dp[366];
//     int solve(vector<int>& days, vector<int>& costs, int &n, int i) {
//         if (i >= n) return 0;
//         if (dp[i] != -1) return dp[i];
//         int cost1 = costs[0] + solve(days, costs, n, i+1);
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
//         return dp[i] = min({cost1, cost7, cost30});
//     }
//     int mincostTickets(vector<int>& days, vector<int>& costs) {
//         memset(dp, -1, sizeof(dp));
//         int n = days.size();
//         return solve(days, costs, n, 0);
//     }
// };