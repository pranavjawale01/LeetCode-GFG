class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        sort(candidates.begin(), candidates.end());
        findCombinations(candidates, target, 0, {}, result);
        return result;
    }
    
    void findCombinations(vector<int>& candidates, int target, int start, vector<int> current, vector<vector<int>>& result) {
        if (target == 0) {
            result.push_back(current);
            return;
        }        
        for (int i = start; i < candidates.size() && candidates[i] <= target; ++i) {
            current.push_back(candidates[i]);
            findCombinations(candidates, target - candidates[i], i, current, result);
            current.pop_back();
        }
    }
};