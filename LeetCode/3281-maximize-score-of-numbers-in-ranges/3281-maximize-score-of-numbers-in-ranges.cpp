using ll = long long;

class Solution {
public:
    bool pranavjawale01(vector<int>& start, int d, int n, int mid) {
        ll ans = start[0];
        for (int i = 1; i <= n; i++) {
            if (ans + mid <= (ll)start[i] + d) {
                ans = max(ans + mid, (ll)start[i]);
            } else {
                return false;
            }
        }
        return true;
    }
    int maxPossibleScore(vector<int>& start, int d) {
        sort(start.begin(), start.end());
        int n = start.size() - 1;
        int low = 0, high = start[n] + d - start[0];
        int ans = 0;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (pranavjawale01(start, d, n, mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};