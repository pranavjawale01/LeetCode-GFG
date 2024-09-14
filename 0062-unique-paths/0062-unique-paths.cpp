class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 || j == 0) {
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }
        return dp[m-1][n-1];
    }
};









// class Solution {
// public:
//     vector<vector<int>> dp;
//     int solve(int i, int j, int m, int n) {
//         if (i == m - 1 && j == n - 1) {
//             return 1;
//         }
//         if (i >= m || j >= n) {
//             return 0;
//         }
//         if (dp[i][j] != -1) {
//             return dp[i][j];
//         }
//         return dp[i][j] = solve(i+1, j, m, n) + solve(i, j+1, m, n);
//     }
//     int uniquePaths(int m, int n) {
//         dp.resize(m+1, vector<int>(n+1, -1));
//         return solve(0, 0, m, n);
//     }
// };