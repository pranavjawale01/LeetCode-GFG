class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end());
        int len = 1;
        int n = pairs.size();
        vector<int> dp(n, 1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (pairs[i][0] > pairs[j][1]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                    len = max(len, dp[i]);
                }
            }
        }
        return len;
    }
};



// class Solution {
// public:
//     int n;
//     int dp[1001][1001];
//     int solve(vector<vector<int>>& pairs, int prev, int i) {
//         if (i == n) {
//             return 0;
//         }
//         if (prev != -1 && dp[prev][i] != -1) {
//             return dp[prev][i];
//         }
//         int taken = 0;
//         if (prev == -1 || pairs[i][0] > pairs[prev][1]) {
//             taken = 1 + solve(pairs, i, i+1);
//         }
//         int notTaken = solve(pairs, prev, i+1);
//         if (prev != -1) {
//             dp[prev][i] = max(taken, notTaken);
//         }
//         return max(taken, notTaken);
//     }
//     int findLongestChain(vector<vector<int>>& pairs) {
//         memset(dp, -1, sizeof(dp));
//         n = pairs.size();
//         sort(pairs.begin(), pairs.end());
//         return solve(pairs, -1, 0);
//     }
// };