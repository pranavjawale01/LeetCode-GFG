class Solution {
public:
    int dp[101][101];
    int solve(vector<vector<int>>& arr, int i, int j) {
        if (i < 0 || j < 0 || i >= arr.size() || j >= arr[0].size() || arr[i][j]) {
            return 0;
        }
        if (i == arr.size() - 1 && j == arr[0].size() - 1) {
            return 1;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        return dp[i][j] = solve(arr, i+1, j) + solve(arr, i, j+1);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        memset(dp, -1, sizeof(dp));
        return solve(obstacleGrid, 0, 0);
    }
};