class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<vector<int>> vertical, horizontal;
        for (auto &x : rectangles) {
            vertical.push_back({x[1], x[3]});
            horizontal.push_back({x[0], x[2]});
        }
        function<vector<vector<int>>(vector<vector<int>>)> solve = [&] (vector<vector<int>> intervals) {
            if (intervals.size() <= 1) return intervals;
            sort(intervals.begin(), intervals.end());
            vector<vector<int>> merged;
            merged.push_back(intervals[0]);
            for (int i = 0; i < intervals.size(); i++) {
                if (intervals[i][0] < merged.back()[1]) {
                    merged.back()[1] = max(merged.back()[1], intervals[i][1]);
                } else {
                    merged.push_back(intervals[i]);
                }
            }
            return merged;
        };
        vector<vector<int>> arr = solve(vertical);
        vector<vector<int>> brr = solve(horizontal);
        return arr.size() >= 3 || brr.size() >= 3;
    }
};