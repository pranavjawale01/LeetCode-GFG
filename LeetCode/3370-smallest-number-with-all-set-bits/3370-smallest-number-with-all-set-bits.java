class Solution {
    public int smallestNumber(int n) {
        int ans = Integer.MAX_VALUE;
        for (int i = 0; i < 31; i++) {
            int val = (1 << i) - 1;
            if (val >= n) {
                ans = Math.min(ans, val);
            }
        }
        return ans;
    }
}