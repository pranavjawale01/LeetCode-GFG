class Solution {
public:
    long long maximumTotalCost(vector<int>& nums) {
        int n = nums.size();
        vector<long long> dp(n+1, -LLONG_MAX);
        dp[0] = 0;
        dp[1] = nums[0];
        for (int i = 1; i < n; i++) {
            dp[i+1] = max(dp[i] + nums[i], dp[i-1] + nums[i-1] - nums[i]);
        }
        return dp[n];
    }
};




// class Solution {
// public:
//     int n;
//     long long dp[100004][2];
//     long long solve(vector<int> &nums, int i, bool pos) {
//         if (i >= n) {
//             return 0;
//         }
//         if (dp[i][pos] != -1) {
//             return dp[i][pos];
//         }
//         if (pos) {
//             dp[i][pos] = nums[i] + solve(nums, i+1, false);
//         } else {
//             long long take = solve(nums, i+1, true) - nums[i];
//             long long nottake = solve(nums, i+1, false) + nums[i];
//             dp[i][pos] = max(take, nottake);
//         }
//         return dp[i][pos];
//     }
//     long long maximumTotalCost(vector<int>& nums) {
//         n = nums.size();
//         memset(dp, -1, sizeof(dp));
//         return solve(nums, 0, true);
//     }
// };