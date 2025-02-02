class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        vector<int> diff;
        int n = startTime.size();
        diff.push_back(startTime[0]);
        for (int i = 1; i < n; i++) {
            diff.push_back(startTime[i] - endTime[i-1]);
        }
        diff.push_back(eventTime - endTime[n-1]);
        int m = diff.size();
        vector<int> suffix(m, 0), prefix(m, 0);
        for (int i = m - 2; i >= 0; i--) {
            suffix[i] = max(suffix[i+1], diff[i+1]);
        }
        for (int i = 2; i < m; i++) {
            prefix[i] = max(prefix[i-1], diff[i-2]);
        }
        int ans = 0;
        for (int i = 1; i < m; i++) {
            int meetingTime = endTime[i-1] - startTime[i-1];
            if (meetingTime <= max(prefix[i], suffix[i])) {
                ans = max(ans, diff[i-1] + diff[i] + meetingTime);
            }
            ans = max(ans, diff[i-1] + diff[i]);
        }
        return ans;
    }
};