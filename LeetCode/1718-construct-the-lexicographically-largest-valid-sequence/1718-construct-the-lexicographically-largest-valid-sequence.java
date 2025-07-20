class Solution {
    private int[] ans;
    private boolean[] vis;

    private boolean solve(int i, int n) {
        if (i >= ans.length) return true;
        if (ans[i] != -1) return solve(i + 1, n);

        for (int num = n; num >= 1; num--) {
            if (vis[num]) continue;
            vis[num] = true;
            ans[i] = num;

            if (num == 1) {
                if (solve(i + 1, n)) return true;
            } else {
                int j = i + num;
                if (j < ans.length && ans[j] == -1) {
                    ans[j] = num;
                    if (solve(i + 1, n)) return true;
                    ans[j] = -1;
                }
            }

            vis[num] = false;
            ans[i] = -1;
        }
        return false;
    }

    public int[] constructDistancedSequence(int n) {
        ans = new int[2 * n - 1];
        Arrays.fill(ans, -1);
        vis = new boolean[n + 1];
        solve(0, n);
        return ans;
    }
}