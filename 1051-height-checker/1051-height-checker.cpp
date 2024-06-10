class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> sorted(heights.begin(), heights.end());
        sort(sorted.begin(), sorted.end());
        int n = heights.size();
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (heights[i] != sorted[i]) {
                count++;
            }
        }
        return count;
    }
};