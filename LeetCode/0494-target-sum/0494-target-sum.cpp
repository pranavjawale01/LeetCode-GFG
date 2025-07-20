class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        vector<vector<int>> dp(n + 1, vector<int>(2 * sum + 1, -1));
        return solve(nums, target, 0, 0, dp, sum);
    }

private:
    int solve(vector<int>& nums, int target, int i, int curr_sum, vector<vector<int>>& dp, int offset) {
        if (i == nums.size()) {
            return curr_sum == target ? 1 : 0;
        }
        if (dp[i][curr_sum + offset] != -1) return dp[i][curr_sum + offset];
        int plus = solve(nums, target, i + 1, curr_sum + nums[i], dp, offset);
        int minus = solve(nums, target, i + 1, curr_sum - nums[i], dp, offset);
        return dp[i][curr_sum + offset] = plus + minus;
    }
};





// class Solution {
// public:
//     int findTargetSumWays(vector<int>& nums, int target) {
//         int n = nums.size();
//         unordered_map<string, int> mp;
//         function<int(int, int)> solve = [&](int i, int sum) {
//             if (i == n) {
//                 return sum == target ? 1 : 0;
//             }
//             string key = to_string(i) + "_" + to_string(sum);
//             if (mp.count(key)) {
//                 return mp[key];
//             }
//             int plus = solve(i+1, sum + nums[i]);
//             int minus = solve(i+1, sum - nums[i]);
//             return mp[key] = plus + minus;
//         };
//         return solve(0, 0);
//     }
// };