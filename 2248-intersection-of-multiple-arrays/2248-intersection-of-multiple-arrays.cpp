class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for (auto num : nums) {
            for (int x : num) {
                mp[x]++;
            }
        }
        vector<int> ans;
        for (auto x : mp) {
            if (x.second == n) {
                ans.push_back(x.first);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};