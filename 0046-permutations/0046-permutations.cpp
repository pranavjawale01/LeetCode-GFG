class Solution {
public:
    void backtrack(vector<vector<int>>& result, vector<int> temp, vector<int>& nums, vector<bool>& used) {
        if (temp.size() == nums.size()) {
            result.push_back(temp);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) {
                continue;
            }
            temp.push_back(nums[i]);
            used[i] = true;
            backtrack(result, temp, nums, used);
            temp.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<bool> used(nums.size(), false);
        backtrack(result, {}, nums, used);
        return result;
    }
};