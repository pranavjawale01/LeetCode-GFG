class Solution {
    public boolean dfs(int[][] graph, int[] color, int node, int col) {
        if (color[node] != 0) {
            return (color[node] == col);
        }
        color[node] = col;
        for (int ne : graph[node]) {
            if (!dfs(graph, color, ne, -col)) {
                return false;
            }
        }
        return true;
    }
    public boolean isBipartite(int[][] graph) {
        int n = graph.length;
        int[] color = new int[n];
        for (int i = 0; i < n; i++) {
            if (color[i] == 0 && !dfs(graph, color, i, 1)) {
                return false;
            }
        }
        return true;
    }
}