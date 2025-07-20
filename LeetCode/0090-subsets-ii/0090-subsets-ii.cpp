class Solution {
public:
    vector<vector<int>> ans;
    void solve(int idx, vector<int> &nums, vector<int> &res) {
        ans.push_back(res);
        
        for (int i = idx; i < nums.size(); i++) {
            if (i > idx && nums[i] == nums[i-1]) {
                continue;
            }
            res.push_back(nums[i]);
            solve(i + 1, nums, res);
            res.pop_back();
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> res;
        sort(nums.begin(), nums.end());
        solve(0, nums, res);
        return ans;
    }
};