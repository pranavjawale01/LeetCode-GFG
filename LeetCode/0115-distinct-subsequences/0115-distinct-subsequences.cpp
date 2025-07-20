class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.length();
        int n = t.length();
        vector<vector<double>> dp(m+1, vector<double>(n+1, 0));
        for (int i = 0; i <= m; i++) {
            dp[i][0] = 1;
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s[i-1] == t[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                } else {
                    dp[i][j] = dp[i-1][j];
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

//     int solve(string &s, string &t, int i, int j) {
//         if (j == n) {
//             return 1;
//         }
//         if (i == m) { 
//             return 0;
//         }
//         if (dp[i][j] != -1) {
//             return dp[i][j];
//         }
//         if (s[i] == t[j]) {
//             dp[i][j] = solve(s, t, i+1, j+1) + solve(s, t, i+1, j);
//         } else {
//             dp[i][j] = solve(s, t, i+1, j);
//         }
//         return dp[i][j];
//     }

//     int numDistinct(string s, string t) {
//         m = s.length();
//         n = t.length();
//         memset(dp, -1, sizeof(dp)); 
//         return solve(s, t, 0, 0);
//     }
// };