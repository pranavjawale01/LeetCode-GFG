class Solution {
    private List<List<Integer>> bridges = new ArrayList<>();
    private int timer = 0;

    private void dfs(int node, int parent, int[] visited, int[] timein, int[] lowtime, List<List<Integer>> adj) {
        visited[node] = 1;
        timein[node] = timer;
        lowtime[node] = timer;
        timer++;
        for (int it : adj.get(node)) {
            if (it == parent) {
                continue;
            }
            if (visited[it] == 0) {
                dfs(it, node, visited, timein, lowtime, adj);
                lowtime[node] = Math.min(lowtime[node], lowtime[it]);
                if (lowtime[it] > timein[node]) {
                    bridges.add(Arrays.asList(node, it));
                }
            } else {
                lowtime[node] = Math.min(lowtime[node], timein[it]);
            }
        }
    }

    public List<List<Integer>> criticalConnections(int n, List<List<Integer>> connections) {
        List<List<Integer>> adj = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            adj.add(new ArrayList<>());
        }
        for (List<Integer> connection : connections) {
            int u = connection.get(0);
            int v = connection.get(1);
            adj.get(u).add(v);
            adj.get(v).add(u);
        }
        int[] visited = new int[n];
        int[] timein = new int[n];
        int[] lowtime = new int[n];
        dfs(0, -1, visited, timein, lowtime, adj);
        return bridges;
    }
}