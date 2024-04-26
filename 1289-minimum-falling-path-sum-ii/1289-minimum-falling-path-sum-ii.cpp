class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int dp[n+1][n+1];
        for (int i = 0; i < n; i++) {
            dp[n-1][i] = grid[n-1][i];
        }
        for (int row = n - 2; row >= 0; row--) {
            for (int col = 0; col < n; col++) {
                int ans = INT_MAX;
                for (int nextCol = 0; nextCol < n; nextCol++) {
                    if (nextCol != col) {
                        ans = min(ans, dp[row+1][nextCol]);
                    }
                }
                dp[row][col] = ans + grid[row][col];
            }
        }
        int ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            ans = min(ans, dp[0][i]);
        }
        return ans;
    }
};

// class Solution {
// public:
//     int dp[201][201];
//     int solve(vector<vector<int>>& grid, int n, int level, int col) {
//         if (level == n - 1) {
//             return dp[level][col] = grid[level][col];
//         }
//         if (dp[level][col] != -1) {
//             return dp[level][col];
//         }
//         int ans = INT_MAX;
//         for (int j = 0; j < n; j++) {
//             if (col == j) {
//                 continue;
//             }
//             ans = min(ans, grid[level][col] + solve(grid, n, level+1, j));
//         }
//         return dp[level][col] = ans;
//     }
//     int minFallingPathSum(vector<vector<int>>& grid) {
//         int n = grid.size();
//         int ans = INT_MAX;
//         memset(dp, -1, sizeof(dp));
//         for (int j = 0; j < n; j++) {
//             ans = min(ans, solve(grid, n, 0, j));
//         }
//         return ans;
//     }
// };