class Solution {
    public boolean check(Map<Integer, ArrayList<Integer>> mp, int s, int d, boolean[] visited) {
        if (s == d) {
            return true;
        }
        if (visited[s]) {
            return false;
        }
        visited[s] = true;
        for (int node : mp.get(s)) {
            if (check(mp, node, d, visited)) {
                return true;
            }
        }
        return false;
    }
    
    public boolean validPath(int n, int[][] edges, int source, int destination) {
        Map<Integer, ArrayList<Integer>> mp = new HashMap<>();
        for (int i = 0; i < n; i++) {
            mp.put(i, new ArrayList<>());
        }
        for (int[] edge : edges) {
            int u = edge[0];
            int v = edge[1];
            mp.get(u).add(v);
            mp.get(v).add(u);
        }
        boolean[] visited = new boolean[n];
        return check(mp, source, destination, visited);
    }
}