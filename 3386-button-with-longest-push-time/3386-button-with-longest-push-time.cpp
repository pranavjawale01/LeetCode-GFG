class Solution {
public:
    int buttonWithLongestTime(vector<vector<int>>& events) {
        int ans = events[0][0];
        int maxTime = events[0][1];
        int n = events.size();
        for (int i = 1; i < n; i++) {
            int curr = events[i][1] - events[i-1][1];
            if (curr > maxTime || (curr == maxTime && events[i][0] < ans)) {
                maxTime = curr;
                ans = events[i][0];
            }
        }
        return ans;
    }
};