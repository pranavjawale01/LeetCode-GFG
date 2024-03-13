class Solution {
    public int pivotInteger(int n) {
        int lSum = 0, rSum = 0;
        for (int i = 1; i <= n; i++) {
            lSum += i;
            for (int j = i; j <= n; j++) {
                rSum += j;
            }
            if (rSum == lSum) {
                return i;
            }
            rSum = 0;
        }
        return -1;
    }
}