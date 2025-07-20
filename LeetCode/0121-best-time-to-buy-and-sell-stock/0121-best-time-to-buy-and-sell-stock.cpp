class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int minEl = INT_MAX;
        int n = prices.size();
        for (int i = 0; i < n; i++) {
            minEl = min(minEl, prices[i]);
            ans = max(ans, prices[i] - minEl);
        }
        return ans;
    }
};