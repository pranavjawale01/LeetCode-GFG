class Solution {
public:
    int minInsertions(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int len = 2; len <= n; ++len) {
            for (int i = 0; i <= n - len; ++i) {
                int j = i + len - 1;
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1];
                } else {
                    dp[i][j] = 1 + min(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[0][n - 1];
    }
};




// class Solution {
// public:
//     int n;
//     int solve(string &s, int i, int j, vector<vector<int>> &dp) {
//         if (i > j) {
//             return 0;
//         }
//         if (i >= n) {
//             return j;
//         }
//         if (j < 0) {
//             return i;
//         }
//         if (dp[i][j] != -1) {
//             return dp[i][j];
//         }
//         if (s[i] == s[j]) {
//             return dp[i][j] = solve(s, i+1, j-1, dp);
//         }
//         return dp[i][j] = 1 + min(solve(s, i+1, j, dp), solve(s, i, j-1, dp));
//     }
//     int minInsertions(string s) {
//         n = s.length();
//         vector<vector<int>> dp(n, vector<int>(n, -1));
//         return solve(s, 0, n-1, dp);
//     }
// };