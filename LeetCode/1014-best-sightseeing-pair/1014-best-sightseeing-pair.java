class Solution {
    public int maxScoreSightseeingPair(int[] values) {
        int n = values.length;
        int ans = 0;
        int maxval = values[0] + 0;
        for (int j = 1; j < n; j++) {
            int x = values[j] - j;
            int y = maxval;
            ans = Math.max(ans, x + y);
            maxval = Math.max(maxval, values[j] + j);
        }
        return ans;
    }
}