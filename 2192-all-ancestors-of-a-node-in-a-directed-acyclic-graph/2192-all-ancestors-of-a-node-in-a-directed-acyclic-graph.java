class Solution {
    public void solve(Map<Integer, List<Integer>> mp, int node, List<Integer> temp, boolean[] vis) {
        if (vis[node]) {
            return;
        }
        vis[node] = true;
        if (mp.containsKey(node)) {
            for (int x : mp.get(node)) {
                if (!vis[x]) {
                    temp.add(x);
                    solve(mp, x, temp, vis);
                }
            }
        }
    }

    public List<List<Integer>> getAncestors(int n, int[][] edges) {
        List<List<Integer>> ans = new ArrayList<>(n);
        Map<Integer, List<Integer>> mp = new HashMap<>();

        for (int i = 0; i < n; i++) {
            ans.add(new ArrayList<>());
        }

        for (int[] edge : edges) {
            mp.computeIfAbsent(edge[1], k -> new ArrayList<>()).add(edge[0]);
        }

        for (int i = 0; i < n; i++) {
            List<Integer> temp = new ArrayList<>();
            boolean[] vis = new boolean[n];
            solve(mp, i, temp, vis);
            Collections.sort(temp);
            ans.set(i, temp);
        }

        return ans;
    }
}