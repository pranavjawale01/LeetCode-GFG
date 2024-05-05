class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size(), n = triangle[m-1].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            dp[m-1][i] = triangle[m-1][i];
        }
        for (int i = m - 2; i >= 0; i--) {
            for (int j = 0; j < triangle[i].size(); j++) {
                dp[i][j] = triangle[i][j] + min(dp[i+1][j], dp[i+1][j+1]);
            }
        }
        return dp[0][0];
    }
};


// class Solution {
// public:
//     int dp[201][201];
//     int solve(vector<vector<int>>& triangle, int n, int index, int level) {
//         if (level >= n) {
//             return 0;
//         }
//         if (dp[level][index] != -1) {
//             return dp[level][index];
//         }
//         int left = solve(triangle, n, index, level + 1);
//         int right = solve(triangle, n, index + 1, level + 1);
//         return dp[level][index] = triangle[level][index] + min(left, right);
//     }
//     int minimumTotal(vector<vector<int>>& triangle) {
//         int n = triangle.size();
//         memset(dp, -1, sizeof(dp));
//         return solve(triangle, n, 0, 0);
//     }
// };