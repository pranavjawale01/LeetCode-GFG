class Solution {
    public void dfs(List<List<Pair<Integer, Integer>>> adj, boolean[] visited, int[] minChange, int currCity) {
        visited[currCity] = true;
        for (Pair<Integer, Integer> neighbourCity : adj.get(currCity)) {
            if (!visited[neighbourCity.getKey()]) {
                if (neighbourCity.getValue() == 1) {
                    minChange[0]++;
                }
                dfs(adj, visited, minChange, neighbourCity.getKey());
            }
        }
    }
    
    public int minReorder(int n, int[][] connections) {
        List<List<Pair<Integer, Integer>>> adj = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            adj.add(new ArrayList<>());
        }
        for (int[] connection : connections) {
            adj.get(connection[0]).add(new Pair<>(connection[1], 1));
            adj.get(connection[1]).add(new Pair<>(connection[0], -1));
        }
        boolean[] visited = new boolean[n];
        int[] minChange = new int[1];
        dfs(adj, visited, minChange, 0);
        return minChange[0];
    }
}