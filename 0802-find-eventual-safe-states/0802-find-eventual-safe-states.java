class Solution {
    public boolean isCycleDFS(int[][] graph, int u, boolean[] visited, boolean[] inRecursion) {
        visited[u] = true;
        inRecursion[u] = true;
        for (int v : graph[u]) {
            if (visited[v] == false && isCycleDFS(graph, v, visited, inRecursion)) {
                return true;
            } else if (inRecursion[v] == true) {
                return true;
            }
        }
        inRecursion[u] = false;
        return false;
    }
    public List<Integer> eventualSafeNodes(int[][] graph) {
        int n = graph.length;
        boolean[] visited = new boolean[n];
        boolean[] inRecursion = new boolean[n];
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                isCycleDFS(graph, i, visited, inRecursion);
            }
        }
        List<Integer> ans = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            if (!inRecursion[i]) {
                ans.add(i);
            }
        }
        return ans;
    }
}