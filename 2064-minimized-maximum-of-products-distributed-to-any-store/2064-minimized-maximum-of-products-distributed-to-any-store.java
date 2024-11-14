class Solution {
    public boolean possible(int x, int[] quantities, int n) {
        for (int a : quantities) {
            // Compute the ceiling of a / x
            n -= (a + x - 1) / x;
            if (n < 0) {
                return false;
            }
        }
        return true;
    }
    public int minimizedMaximum(int n, int[] quantities) {
        int l = 1, r = Arrays.stream(quantities).max().getAsInt();
        int ans = 0;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (possible(mid, quantities, n)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
}