class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        int n = obstacles.size();
        vector<int> dp;
        vector<int> ans(n, 0);
        
        for (int i = 0; i < n; i++) {
            int temp = obstacles[i];
            if (dp.empty() || temp >= dp.back()) {
                dp.push_back(temp);
                ans[i] = dp.size();
            } else {
                auto it = upper_bound(dp.begin(), dp.end(), temp);
                *it = temp;
                ans[i] = distance(dp.begin(), it) + 1;
            }
        }
        
        return ans;
    }
};