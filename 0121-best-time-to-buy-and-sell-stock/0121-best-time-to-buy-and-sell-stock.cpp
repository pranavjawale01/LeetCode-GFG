class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxVal = 0;
        int minVal = INT_MAX;
        int n = prices.size();
        for (int i = 0; i < n; i++) {
            minVal = min(minVal, prices[i]);
            maxVal = max(maxVal, prices[i] - minVal);
        }
        return maxVal;
    }
};