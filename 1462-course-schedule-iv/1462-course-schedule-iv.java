class Solution {
    public boolean solve(Map<Integer, List<Integer>> mp, int s, int e, boolean[] vis) {
        vis[s] = true;
        if (s == e) return true;
        boolean reachable = false;
        for (int x : mp.getOrDefault(s, new ArrayList<>())) {
            if (!vis[x]) {
                reachable |= solve(mp, x, e, vis);
            }
        }
        return reachable;
    }

    public List<Boolean> checkIfPrerequisite(int numCourses, int[][] prerequisites, int[][] queries) {
        Map<Integer, List<Integer>> mp = new HashMap<>();
        for (int[] pair : prerequisites) {
            mp.computeIfAbsent(pair[0], k -> new ArrayList<>()).add(pair[1]);
        }
        List<Boolean> ans = new ArrayList<>();
        for (int[] query : queries) {
            int u = query[0];
            int v = query[1];
            boolean[] vis = new boolean[numCourses];
            ans.add(solve(mp, u, v, vis));
        }
        return ans;
    }
}