class Solution {
    public int n;
    public void dfs(int[][] stones, int idx, boolean[] vis) {
        vis[idx] = true;
        for (int i = 0; i < n; i++) {
            if (!vis[i] && ((stones[i][0] == stones[idx][0]) || stones[i][1] == stones[idx][1])) {
                dfs(stones, i, vis);
            }
        }
    }
    public int removeStones(int[][] stones) {
        n = stones.length;
        boolean[] vis = new boolean[n];
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (vis[i]) {
                continue;
            }
            dfs(stones, i, vis);
            count++;
        }
        return n - count;
    }
}