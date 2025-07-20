class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (nums1[i-1] == nums2[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                } else {
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                }
            }
        }
        return dp[n][m];
    }
};



// class Solution {
// public:
//     int dp[501][501];

//     int solve(vector<int>& nums1, vector<int>& nums2, int i, int j) {
//         if (i < 0 || j < 0) {
//             return 0;
//         }
//         if (dp[i][j] != -1) {
//             return dp[i][j];
//         }
//         if (nums1[i] == nums2[j]) {
//             return dp[i][j] = 1 + solve(nums1, nums2, i - 1, j - 1);
//         }
//         return dp[i][j] = max(solve(nums1, nums2, i - 1, j), solve(nums1, nums2, i, j - 1));
//     }

//     int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
//         int m = nums1.size(), n = nums2.size();
//         memset(dp, -1, sizeof(dp));
//         return solve(nums1, nums2, m - 1, n - 1);
//     }
// };