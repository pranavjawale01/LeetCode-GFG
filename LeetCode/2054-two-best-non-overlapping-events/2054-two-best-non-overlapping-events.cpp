class Solution {
public:
    int n;
    int dp[100001][3];
    int binarySearch(vector<vector<int>> &events, int endTime) {
        int l = 0, r = n - 1, ans = n;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (events[mid][0] > endTime) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
    int solve(vector<vector<int>> &events, int i, int count) {
        if (count == 2 || i >= n) {
            return 0;
        }
        if (dp[i][count] != -1) {
            return dp[i][count];
        }
        int nextValidEventIndex = binarySearch(events, events[i][1]);
        int take = events[i][2] + solve(events, nextValidEventIndex, count + 1);
        int notTake = solve(events, i+1, count);
        return dp[i][count] = max(take, notTake);
    }
    int maxTwoEvents(vector<vector<int>>& events) {
        n = events.size();
        sort(events.begin(), events.end());
        memset(dp, -1, sizeof(dp));
        int count = 0;
        return solve(events, 0, count);
    }
};