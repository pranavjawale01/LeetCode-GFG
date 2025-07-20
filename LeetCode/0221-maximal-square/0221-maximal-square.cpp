class Solution {
public:
    int row , col;
    int dp[301][301];
    
    int solve(vector<vector<char>>& matrix, int i, int j) {
        if (i < 0 || j < 0 || i >= row || j >= col || matrix[i][j] == '0') {
            return 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        int ans = 1;
        ans += min({solve(matrix, i-1, j-1), solve(matrix, i-1, j), solve(matrix, i, j-1)});
        return dp[i][j] = ans;
    }
    
    int maximalSquare(vector<vector<char>>& matrix) {
        memset(dp, -1, sizeof(dp));
        row = matrix.size();
        col = matrix[0].size();
        int ans = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                ans = max(ans, solve(matrix, i, j));
            }
        }
        return ans * ans;
    }
};


// class Solution {
// public:
//     int maximalSquare(vector<vector<char>>& matrix) {
//         int row = matrix.size(), col = matrix[0].size();
//         vector<vector<int>> dp(row+1, vector<int>(col+1, 0));
//         int ans = 0;
//         for (int i = 1; i <= row; i++) {
//             for (int j = 1; j <= col; j++) {
//                 if (matrix[i-1][j-1] == '1') {
//                     dp[i][j] = 1 + min({dp[i-1][j-1], dp[i-1][j], dp[i][j-1]});
//                     ans = max(ans, dp[i][j]);
//                 }
//             }
//         }
//         return ans*ans;
//     }
// };