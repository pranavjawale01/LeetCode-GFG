class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int a = INT_MAX, b = INT_MAX;
                if (j - 1 >= 0) {
                    a = matrix[i-1][j-1];
                }
                if (j + 1 < n) {
                    b = matrix[i-1][j+1];
                }
                matrix[i][j] += min(matrix[i-1][j], min({a, b}));
            }
        }
        int ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            ans = min(ans, matrix[n-1][i]);
        }
        return ans;
    }
};

// class Solution {
// public:
//     int dp[101][101];
//     int solve (vector<vector<int>>& matrix, int n, int row, int col) {
//         if (row == n - 1) {
//             return matrix[row][col];
//         }
//         if (dp[row][col] != -1) {
//             return dp[row][col];
//         }
//         int ans = INT_MAX;
//         if (row + 1 < n && col - 1 >= 0) {
//             ans = min(ans, matrix[row][col] + solve(matrix, n, row + 1, col - 1));
//         }
//         if (row + 1 < n) {
//             ans = min(ans, matrix[row][col] + solve(matrix, n, row + 1, col));
//         }
//         if (row + 1 < n && col + 1 < n) {
//             ans = min(ans, matrix[row][col] + solve(matrix, n, row + 1, col + 1));
//         }
//         return dp[row][col] = ans;
//     }
//     int minFallingPathSum(vector<vector<int>>& matrix) {
//         int n = matrix.size();
//         int ans = INT_MAX;
//         memset(dp, -1, sizeof(dp));
//         for (int i = 0; i < n; i++) {
//             ans = min(ans, solve(matrix, n, 0, i));
//         }
//         return ans;
//     }
// };