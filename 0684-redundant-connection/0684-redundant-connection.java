class Solution {
    public boolean dfs(Map<Integer, List<Integer>> mp, int u, int v, boolean[] vis) {
        vis[u] = true;
        if (u == v) return true;
        for (int x : mp.get(u)) {
            if (vis[x]) continue;
            if (dfs(mp, x, v, vis)) return true;
        }
        return false;
    }

    public int[] findRedundantConnection(int[][] edges) {
        int n = edges.length;
        Map<Integer, List<Integer>> mp = new HashMap<>();
        for (int[] edge : edges) {
            int u = edge[0], v = edge[1];
            boolean[] vis = new boolean[n + 1];
            if (mp.containsKey(u) && mp.containsKey(v) && dfs(mp, u, v, vis)) {
                return edge;
            }
            mp.putIfAbsent(u, new ArrayList<>());
            mp.putIfAbsent(v, new ArrayList<>());
            mp.get(u).add(v);
            mp.get(v).add(u);
        }
        return new int[0];
    }
}