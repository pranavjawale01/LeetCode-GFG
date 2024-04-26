class Solution {
public:
    int dp[201][201];
    int solve(vector<vector<int>>& grid, int n, int level, int col) {
        if (level == n - 1) {
            return dp[level][col] = grid[level][col];
        }
        if (dp[level][col] != -1) {
            return dp[level][col];
        }
        int ans = INT_MAX;
        for (int j = 0; j < n; j++) {
            if (col == j) {
                continue;
            }
            ans = min(ans, grid[level][col] + solve(grid, n, level+1, j));
        }
        return dp[level][col] = ans;
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int ans = INT_MAX;
        memset(dp, -1, sizeof(dp));
        for (int j = 0; j < n; j++) {
            ans = min(ans, solve(grid, n, 0, j));
        }
        return ans;
    }
};