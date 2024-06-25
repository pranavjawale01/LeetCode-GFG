class Solution {
public:
    int n;
    long long dp[100004][2];
    long long solve(vector<int> &nums, int i, bool pos) {
        if (i >= n) {
            return 0;
        }
        if (dp[i][pos] != -1) {
            return dp[i][pos];
        }
        if (pos) {
            dp[i][pos] = nums[i] + solve(nums, i+1, false);
        } else {
            long long take = solve(nums, i+1, true) - nums[i];
            long long nottake = solve(nums, i+1, false) + nums[i];
            dp[i][pos] = max(take, nottake);
        }
        return dp[i][pos];
    }
    long long maximumTotalCost(vector<int>& nums) {
        n = nums.size();
        memset(dp, -1, sizeof(dp));
        return solve(nums, 0, true);
    }
};