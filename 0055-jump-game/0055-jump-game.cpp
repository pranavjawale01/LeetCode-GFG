class Solution {
public:
    bool solve(vector<int>& nums, int index, vector<int> &dp) {
        if (index >= nums.size() - 1) {
            return true;
        }
        if (dp[index] != -1) {
            return dp[index];
        }
        int curr = nums[index];
        while (curr > 0) {
            if (solve(nums, index + curr, dp)) {
                return dp[index] = true;
            }
            curr--;
        }
        return dp[index] = false;
    }
    
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return solve(nums, 0, dp);
    }
};