class Solution {
    public int[] shortestAlternatingPaths(int n, int[][] redEdges, int[][] blueEdges) {
        List<List<Pair<Integer, Integer>>> adj = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            adj.add(new ArrayList<>());
        }
        
        for (int[] it : redEdges) {
            adj.get(it[0]).add(new Pair<>(it[1], 0));
        }
        
        for (int[] it : blueEdges) {
            adj.get(it[0]).add(new Pair<>(it[1], 1));
        }
        
        int[] ans = new int[n];
        Arrays.fill(ans, -1);
        boolean[][] visited = new boolean[n][2];
        Queue<List<Integer>> q = new LinkedList<>();
        q.offer(Arrays.asList(0, 0, -1));
        visited[0][0] = true;
        visited[0][1] = true;
        ans[0] = 0;
        
        while (!q.isEmpty()) {
            List<Integer> curr = q.poll();
            int node = curr.get(0), steps = curr.get(1), preColor = curr.get(2);

            for (Pair<Integer, Integer> pair : adj.get(node)) {
                int neighbor = pair.getKey();
                int color = pair.getValue();
                if (!visited[neighbor][color] && color != preColor) {
                    visited[neighbor][color] = true;
                    q.offer(Arrays.asList(neighbor, steps + 1, color));
                    if (ans[neighbor] == -1) {
                        ans[neighbor] = steps + 1;
                    }
                }
            }
        }
        return ans;
    }
}