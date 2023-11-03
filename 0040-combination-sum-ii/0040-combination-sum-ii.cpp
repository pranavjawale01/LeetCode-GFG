class Solution {
public:
    void findSums(vector<int>& candidates, int target, int start, vector<vector<int>>& result, vector<int>& current) {
        if (target == 0) {
            result.push_back(current);
            return;
        }
        for (int i = start; i < candidates.size(); i++) {
            if (i > start && candidates[i] == candidates[i - 1]) {
                continue;
            }
            if (candidates[i] <= target) {
                current.push_back(candidates[i]);
                findSums(candidates, target - candidates[i], i + 1, result, current);
                current.pop_back();
            }
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> current;
        findSums(candidates, target, 0, result, current);
        return result;
    }
};