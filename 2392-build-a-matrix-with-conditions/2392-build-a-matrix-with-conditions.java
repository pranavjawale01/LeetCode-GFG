class Solution {
    public void dfs(int node, Map<Integer, List<Integer>> adj, int[] vis, Stack<Integer> st, boolean[] hasCycle) {
        vis[node] = 1;
        for (int x : adj.getOrDefault(node, new ArrayList<>())) {
            if (vis[x] == 0) {
                dfs(x, adj, vis, st, hasCycle);
            } else if (vis[x] == 1) {
                hasCycle[0] = true;
                return;
            }
        }
        vis[node] = 2;
        st.push(node);
    }

    public List<Integer> topoSort(int[][] edges, int n) {
        Map<Integer, List<Integer>> adj = new HashMap<>();
        Stack<Integer> st = new Stack<>();
        List<Integer> order = new ArrayList<>();
        int[] vis = new int[n + 1];
        boolean[] hasCycle = {false};

        for (int[] edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj.computeIfAbsent(u, k -> new ArrayList<>()).add(v);
        }

        for (int i = 1; i <= n; i++) {
            if (vis[i] == 0) {
                dfs(i, adj, vis, st, hasCycle);
                if (hasCycle[0]) {
                    return new ArrayList<>();
                }
            }
        }

        while (!st.isEmpty()) {
            order.add(st.pop());
        }

        return order;
    }

    public int[][] buildMatrix(int k, int[][] rowConditions, int[][] colConditions) {
        List<Integer> orderRows = topoSort(rowConditions, k);
        List<Integer> orderCols = topoSort(colConditions, k);

        if (orderRows.isEmpty() || orderCols.isEmpty()) {
            return new int[0][];
        }

        int[][] matrix = new int[k][k];
        Map<Integer, Integer> rowPos = new HashMap<>();
        Map<Integer, Integer> colPos = new HashMap<>();

        for (int i = 0; i < k; i++) {
            rowPos.put(orderRows.get(i), i);
            colPos.put(orderCols.get(i), i);
        }

        for (int i = 1; i <= k; i++) {
            int r = rowPos.get(i);
            int c = colPos.get(i);
            matrix[r][c] = i;
        }

        return matrix;
    }
}