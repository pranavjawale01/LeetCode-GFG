class Solution {
public:
    static const int MOD = 1e9 + 7;
    vector<vector<vector<int>>> dp;

    int solve(vector<vector<int>> &grid, int i, int j, int x, int k) {
        int n = grid.size(), m = grid[0].size();
        if (i >= n || j >= m) return 0;
        x ^= grid[i][j];
        if (dp[i][j][x] != -1) return dp[i][j][x];

        int ans = 0;
        if (i == n - 1 && j == m - 1 && x == k) {
            ans = 1;
        }
        ans = (ans + solve(grid, i + 1, j, x, k)) % MOD;
        ans = (ans + solve(grid, i, j + 1, x, k)) % MOD;

        return dp[i][j][x] = ans;
    }

    int countPathsWithXorValue(vector<vector<int>> &grid, int k) {
        int n = grid.size(), m = grid[0].size();
        dp.resize(n, vector<vector<int>>(m, vector<int>(16, -1)));
        return solve(grid, 0, 0, 0, k);
    }
};










// class Solution {
// public:
//     int countPathsWithXorValue(vector<vector<int>>& grid, int k) {
//         int MOD = 1e9 + 7;
//         int m = grid.size(), n = grid[0].size();
//         vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(16, 0)));
//         int start = grid[0][0];
//         dp[0][0][start] = 1;
//         for (int i = 0; i < m; i++) {
//             for (int j = 0; j < n; j++) {
//                 for (int x = 0; x < 16; x++) {
//                     if (j + 1 < n) {
//                         int down = grid[i][j+1];
//                         dp[i][j+1][x^down] = (dp[i][j+1][x^down] + dp[i][j][x]) % MOD;
//                     }
//                     if (i + 1 < m) {
//                         int right = grid[i+1][j];
//                         dp[i+1][j][x^right] = (dp[i+1][j][x^right] + dp[i][j][x]) % MOD;
//                     }
//                 }
//             }
//         }
//         return dp[m-1][n-1][k];
//     }
// };