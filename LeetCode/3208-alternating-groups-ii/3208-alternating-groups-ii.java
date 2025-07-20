class Solution {
    public int numberOfAlternatingGroups(int[] colors, int k) {
        int last = colors[0];
        int ans = 0, count = 1;
        int n = colors.length;
        for (int i = 1; i < n; i++) {
            count = colors[i] != last ? count + 1 : 1;
            if (count >= k) {
                ans++;
            }
            last = colors[i];
        }
        for (int i = 0; i < k - 1; i++) {
            count = colors[i] != last ? count + 1 : 1;
            if (count >= k) {
                ans++;
            }
            last = colors[i];
        }
        return ans;
    }
}