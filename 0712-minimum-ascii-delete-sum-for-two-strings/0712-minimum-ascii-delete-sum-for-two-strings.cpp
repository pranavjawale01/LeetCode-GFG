class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int m = s1.length();
        int n = s2.length();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for (int i = 1; i <= m; i++) {
            dp[i][0] = dp[i-1][0] + s1[i-1];
        }
        for (int j = 1; j <= n; j++) {
            dp[0][j] = dp[0][j-1] + s2[j-1];
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s1[i-1] == s2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    dp[i][j] = min(dp[i-1][j] + s1[i-1], dp[i][j-1] + s2[j-1]);
                }
            }
        }
        return dp[m][n];
    }
};



// class Solution {
// public:
//     int m, n;
//     int dp[1001][1001];
//     int solve(string &s1, string &s2, int i, int j) {
//         if (i >= m && j >= n) {
//             return 0;
//         }
//         if (dp[i][j] != -1) {
//             return dp[i][j];
//         }
//         if (i >= m) {
//             return dp[i][j] = s2[j] + solve(s1, s2, i, j+1);
//         }
//         if (j >= n) {
//             return dp[i][j] = s1[i] + solve(s1, s2, i+1, j);
//         }
//         if (s1[i] == s2[j]) {
//             return dp[i][j] = solve(s1, s2, i + 1, j + 1);
//         }
//         int take_i = s1[i] + solve(s1, s2, i+1, j);
//         int take_j = s2[j] + solve(s1, s2, i, j+1);

//         return dp[i][j] = min(take_i, take_j);
//     }
//     int minimumDeleteSum(string s1, string s2) { 
//         m = s1.length();
//         n = s2.length();
//         memset(dp, -1, sizeof(dp));
//         return solve(s1, s2, 0, 0);
//     }
// };