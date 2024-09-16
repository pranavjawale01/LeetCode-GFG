class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int n = timePoints.size();
        int ans = INT_MAX;

        sort(timePoints.begin(), timePoints.end());

        auto toMinutes = [](const string& time) {
            int hours = stoi(time.substr(0, 2));
            int minutes = stoi(time.substr(3, 2));
            return hours * 60 + minutes;
        };

        for (int i = 0; i < n - 1; i++) {
            int time1 = toMinutes(timePoints[i]);
            int time2 = toMinutes(timePoints[i + 1]);

            ans = min(ans, time2 - time1);
        }

        int firstTime = toMinutes(timePoints[0]);
        int lastTime = toMinutes(timePoints[n - 1]);

        ans = min(ans, firstTime + 1440 - lastTime);

        return ans;
    }
};