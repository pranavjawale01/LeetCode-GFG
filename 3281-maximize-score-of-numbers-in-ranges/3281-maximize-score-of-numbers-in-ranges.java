class Solution {
    public boolean pranavjawale01(int[] start, int d, int n, int mid) {
        long ans = start[0];
        for (int i = 1; i < n; i++) {
            if (ans + mid <= start[i] + d) {
                ans = Math.max(ans + mid, (long)start[i]);
            } else {
                return false;
            }
        }
        return true;
    }
    public int maxPossibleScore(int[] start, int d) {
        Arrays.sort(start);
        int n = start.length;
        int low = 0, high = start[n-1] + d - start[0];
        int ans = 0;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (pranavjawale01(start, d, n, mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
}