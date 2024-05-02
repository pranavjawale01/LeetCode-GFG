class Solution {
    public int maxProfit(int[] prices) {
        int currMax = 0, finalMax = 0;
        int n = prices.length;
        for (int i = 1; i < n; i++) {
            currMax = Math.max(0, currMax += prices[i] - prices[i-1]);
            finalMax = Math.max(finalMax, currMax);
        }
        return finalMax;
    }
}