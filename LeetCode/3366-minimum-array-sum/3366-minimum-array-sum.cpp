class Solution {
public:
    long long dp[101][101][101];
    int solve(vector<int> &nums, int i, int k, int op1, int op2) {
        if (i >= nums.size()) return 0;
        if (dp[i][op1][op2] != -1) return dp[i][op1][op2];
        int ans = nums[i] + solve(nums, i+1, k, op1, op2);
        if (op1) {
            ans = min(ans, (nums[i] + 1) / 2 + solve(nums, i+1, k, op1 - 1, op2));
        }
        if (op2 && nums[i] >= k) {
            ans = min(ans, nums[i] - k + solve(nums, i+1, k, op1, op2 - 1));
        }
        if (op1 && op2) {
            int div = (nums[i] + 1) / 2;
            if (div >= k) {
                ans = min(ans, div - k + solve(nums, i+1, k, op1 - 1, op2 - 1));
            }
        }
        if (op1 && op2 && nums[i] >= k) {
            int sub = nums[i] - k;
            ans = min(ans, (sub + 1) / 2 + solve(nums, i+1, k, op1 - 1, op2 - 1));
        }
        return dp[i][op1][op2] = ans;
    }
    int minArraySum(vector<int>& nums, int k, int op1, int op2) {
        memset(dp, -1, sizeof(dp));
        return solve(nums, 0, k, op1, op2);
    }
};