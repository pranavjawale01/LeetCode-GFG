class Solution {
public:
    int memo[101];
    int solve(int i, int j, vector<int> &nums) {
        if (i >= j) {
            return 0;
        }
        if (memo[i] != -1) {
            return memo[i];
        }
        int take = nums[i] + solve(i+2, j, nums);
        int nottake = solve(i+1, j, nums);
        return memo[i] = max(take, nottake);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        }
        if (n == 2) {
            return max(nums[0], nums[1]);
        }
        memset(memo, -1, sizeof(memo));
        int take0 = solve(0, n-1, nums);
        memset(memo, -1, sizeof(memo));
        int take1 = solve(1, n, nums);
        return max(take0, take1);
    }
};