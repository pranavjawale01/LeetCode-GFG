class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        vector<int> diff(n+1);
        diff[0] = startTime[0];
        diff[n] = eventTime - endTime[n-1];
        for (int i = 1; i < n; i++) {
            diff[i] = startTime[i] - endTime[i-1];
        }
        int ans = 0;
        for (int i = 0; i <= k; i++) {
            ans += diff[i];
        }
        int temp = ans;
        for (int i = k + 1; i <= n; i++) {
            temp += diff[i] - diff[i-k-1];
            ans = max(ans, temp);
        }
        return ans;
    }
};