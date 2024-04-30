class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);
        ans[0] = nums[0];
        ans[1] = nums[1];
        for (int i = 2; i < n; i++) {
            ans[i] = max(nums[i] + ans[i-2], ans[i-1]);
        }
        return ans[n-1];
    }
};

// class Solution {
// public:
//     int memo[101];
//     int solve(vector<int> &nums, int house) {
//         if (house >= nums.size()) {
//             return 0;
//         }
//         if (memo[house] != -1) {
//             return memo[house];
//         }
//         int select = nums[house] + solve(nums, house+2);
//         int notSelect = solve(nums, house+1);
//         return memo[house] = max(select, notSelect);
//     }
//     int rob(vector<int>& nums) {
//         memset(memo, -1, sizeof(memo));
//         return solve(nums, 0);
//     }
// };