class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>> jobs(n, vector<int>(3));

        for (int i = 0; i < n; i++) {
            jobs[i] = {startTime[i], endTime[i], profit[i]};
        }

        sort(jobs.begin(), jobs.end(), [](const auto& a, const auto& b) {
            return a[1] < b[1];
        });

        map<int, int> dp;
        dp[0] = 0;

        for (const auto& job : jobs) {
            int val = job[2] + prev(dp.upper_bound(job[0]))->second;
            if (val > dp.rbegin()->second) {
                dp[job[1]] = val;
            }
        }

        return dp.rbegin()->second;
    }
};


// class Solution {
// public:
//     int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
//         int n = startTime.size();
//         int maxEndTime = *max_element(endTime.begin(), endTime.end());
//         vector<vector<int>> dp(n+1 , vector<int>(maxEndTime+1 , 0));
//         for (int i = 1; i <= n; i++) {
//             for (int j = 1; j <= maxEndTime; j++) {
//                 dp[i][j] = dp[i - 1][j];
//                 if (endTime[i - 1] <= j) {
//                     dp[i][j] = max(dp[i][j], profit[i - 1] + dp[i - 1][j - endTime[i - 1]]);
//                 }
//             }
//         }
//         int totalProfit = 0;
//         int i = n, j = maxEndTime;
//         while (i > 0 && j > 0) {
//             if (dp[i][j] != dp[i-1][j]) {
//                 totalProfit += profit[i - 1];
//                 j = startTime[i - 1];
//             }
//             i--;
//         }
//         return totalProfit;
//     }
// };