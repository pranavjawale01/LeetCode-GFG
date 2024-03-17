class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(begin(intervals), end(intervals), [](const auto& a, const auto& b) {
            return a[0] < b[0];
        });
        vector<vector<int>> result;
        if (intervals.empty()) {
            return result;
        }
        int n = intervals.size();
        result.push_back(intervals[0]);
        for (int i = 1; i < n; i++) {
            if (result.back()[1] >= intervals[i][0]) {
                result.back()[1] = max(intervals[i][1], result.back()[1]);
            } else {
                result.push_back(intervals[i]);
            }
        }
        return result;
    }
};