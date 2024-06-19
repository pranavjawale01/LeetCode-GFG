class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i <= m; i++) {
            dp[i][0] = i;
        }
        for (int j = 0; j <= n; j++) {
            dp[0][j] = j;
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[m][n];
    }
};




// class Solution {
// public:
//     int dp[501][501];

//     int solve(string &word1, string &word2, int i, int j) {
//         if (i == 0) {
//             return j;
//         }
//         if (j == 0) {
//             return i;
//         }
//         if (dp[i][j] != -1) {
//             return dp[i][j];
//         }
//         if (word1[i-1] == word2[j-1]) {
//             return dp[i][j] = solve(word1, word2, i-1, j-1);
//         }
//         return dp[i][j] = 1 + min(solve(word1, word2, i-1, j), solve(word1, word2, i, j-1));
//     }

//     int minDistance(string word1, string word2) {
//         int m = word1.size(), n = word2.size();
//         memset(dp, -1, sizeof(dp));
//         return solve(word1, word2, m, n);
//     }
// };