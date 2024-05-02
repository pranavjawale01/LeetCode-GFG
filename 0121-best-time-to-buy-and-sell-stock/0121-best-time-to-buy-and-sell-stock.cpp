class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int currMax = 0, finalMax = 0;
        int n = prices.size();
        for (int i = 1; i < n; i++) {
            currMax = max(currMax += prices[i] - prices[i-1], 0);
            finalMax = max(finalMax, currMax);
        }
        return finalMax;
    }
};