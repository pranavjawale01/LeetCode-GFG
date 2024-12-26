class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<string, int> mp;
        function<int(int, int)> solve = [&](int i, int sum) {
            if (i == n) {
                return sum == target ? 1 : 0;
            }
            string key = to_string(i) + "_" + to_string(sum);
            if (mp.count(key)) {
                return mp[key];
            }
            int plus = solve(i+1, sum + nums[i]);
            int minus = solve(i+1, sum - nums[i]);
            return mp[key] = plus + minus;
        };
        return solve(0, 0);
    }
};