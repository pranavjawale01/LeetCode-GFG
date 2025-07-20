class Solution {
    public long maximumTotalSum(int[] maximumHeight) {
        int n = maximumHeight.length;
        long ans = 0L;
        Arrays.sort(maximumHeight);
        long currHt = (long) maximumHeight[n - 1];
        
        for (int i = n - 1; i >= 0; i--) {
            if (currHt > maximumHeight[i]) {
                currHt = (long) maximumHeight[i];
            }
            if (currHt < 1) {
                return -1;
            }
            ans += currHt;
            currHt--;
        }
        return ans;
    }
}