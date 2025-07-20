class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int wide = 0;
        for (int i = 0; i < points.size() - 1; i++) {
            if (points[i+1][0] - points[i][0] > wide) {
                wide = points[i+1][0] - points[i][0];
            }
        }
        return wide;
    }
};