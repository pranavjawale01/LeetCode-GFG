class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) {
            return n;
        }
        vector<vector<int>> dp(n, vector<int>(1001, 0));
        int ans = 0;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                int diff = nums[i] - nums[j] + 500;
                dp[i][diff] = dp[j][diff] > 0 ? dp[j][diff] + 1: 2;
                ans = max(ans, dp[i][diff]);
            }
        }
        return ans;
    }
};



// class Solution {
// public:
//     int n;
//     int dp[1001][1003];
//     int solve(vector<int> &nums, int i, int diff) {
//         if (i < 0) {
//             return 0;
//         }
//         if (dp[i][diff+501] != -1) {
//             return dp[i][diff + 501];
//         }
//         int ans = 0;
//         for (int k = i - 1; k >= 0; k--) {
//             if (nums[i] - nums[k] == diff) {
//                 ans = max(ans, 1 + solve(nums, k, diff));
//             }
//         }
//         return dp[i][diff + 501] = ans;
//     }
//     int longestArithSeqLength(vector<int>& nums) {
//         n = nums.size();
//         if (n <= 2) {
//             return n;
//         }
//         memset(dp, -1, sizeof(dp));
//         int ans = 0;
//         for (int i = 0; i < n; i++) {
//             for (int j = i+1; j < n; j++) {
//                 ans = max(ans, 2 + solve(nums, i, nums[j]-nums[i]));
//             }
//         }
//         return ans;
//     }
// };