class Solution {
public:
    int dp[201][201];
    int solve(vector<vector<int>>& triangle, int n, int index, int level) {
        if (level >= n) {
            return 0;
        }
        if (dp[level][index] != -1) {
            return dp[level][index];
        }
        int left = solve(triangle, n, index, level + 1);
        int right = solve(triangle, n, index + 1, level + 1);
        return dp[level][index] = triangle[level][index] + min(left, right);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        memset(dp, -1, sizeof(dp));
        return solve(triangle, n, 0, 0);
    }
};