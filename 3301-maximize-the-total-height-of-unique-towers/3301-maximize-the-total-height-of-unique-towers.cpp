class Solution {
public:
    long long maximumTotalSum(vector<int>& maximumHeight) {
        int n = maximumHeight.size();
        long long ans = 0ll;
        sort(maximumHeight.begin(), maximumHeight.end());
        long long currHt = (long long) maximumHeight[n-1];
        for (int i = n - 1; i >= 0; i--) {
            if (currHt > maximumHeight[i]) {
                currHt = (long long) maximumHeight[i];
            }
            if (currHt < 1) {
                return -1;
            }
            ans += currHt;
            currHt--;
        }
        return ans;
    }
};