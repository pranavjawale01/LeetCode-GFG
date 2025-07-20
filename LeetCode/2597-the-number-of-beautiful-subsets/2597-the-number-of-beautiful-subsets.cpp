class Solution {
public:
    int ans = 0, K;
    void dfs(vector<int> &nums, int i, unordered_map<int, int> &mp) {
        if (i == nums.size()) {
            ans++;
            return;
        }
        dfs(nums, i+1, mp);
        if (!mp[nums[i] - K] && !mp[nums[i]+K]) {
            mp[nums[i]]++;
            dfs(nums, i+1, mp);
            mp[nums[i]]--;
        }
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        K = k;
        unordered_map<int, int> mp;
        dfs(nums, 0, mp);
        return ans - 1;
    }
};