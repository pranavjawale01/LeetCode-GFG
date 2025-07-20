using ll = long long;
class Solution {
public:
    ll solve(int workerTime, ll availTime, int mtHeight) {
        ll low = 0, high = mtHeight, maxHeight = 0;
        while (low <= high) {
            ll mid = low + (high - low) / 2;
            ll reqTime = workerTime * (mid * (mid + 1)) / 2;
            if (reqTime <= availTime) {
                maxHeight = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return maxHeight;
    }
    bool pranavjawale01(int mtHeight, vector<int> &workerTimes, ll time) {
        ll temp = 0;
        for (int &x : workerTimes) {
            temp += solve(x, time, mtHeight);
            if (temp >= mtHeight) {
                return true;
            }
        }
        return temp >= mtHeight;
    }
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        ll low = 0, high = 1e18;
        while (low < high) {
            ll mid = low + (high - low) / 2;
            if (pranavjawale01(mountainHeight, workerTimes, mid)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};