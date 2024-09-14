class Solution {
public:
    vector<vector<int>> dp;
    int solve(int i, int j, int m, int n) {
        if (i == m - 1 && j == n - 1) {
            return 1;
        }
        if (i >= m || j >= n) {
            return 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        return dp[i][j] = solve(i+1, j, m, n) + solve(i, j+1, m, n);
    }
    int uniquePaths(int m, int n) {
        dp.resize(m+1, vector<int>(n+1, -1));
        return solve(0, 0, m, n);
    }
};