class Solution {
    public void DFS(Map<Integer, List<Integer>> adj, int i, boolean[] visited) {
        visited[i] = true;
        for (int v : adj.get(i)) {
            if (!visited[v]) {
                DFS(adj, v, visited);
            }
        }
    }

    public int findCircleNum(int[][] isConnected) {
        int count = 0;
        int n = isConnected.length;
        boolean[] visited = new boolean[n];
        Map<Integer, List<Integer>> adj = new HashMap<>();
        for (int i = 0; i < n; i++) {
            adj.put(i, new ArrayList<>());
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1) {
                    if (!adj.containsKey(i)) {
                        adj.put(i, new ArrayList<>());
                    }
                    adj.get(i).add(j);
                    if (!adj.containsKey(j)) {
                        adj.put(j, new ArrayList<>());
                    }
                    adj.get(j).add(i);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                DFS(adj, i, visited);
                count++;
            }
        }
        return count;
    }
}