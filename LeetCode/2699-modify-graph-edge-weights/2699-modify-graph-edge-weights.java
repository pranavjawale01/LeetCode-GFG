class Solution {
    private static final int INF = (int) 2e9;

    private int dijkstra(int n, int src, int dest, List<List<int[]>> adj) {
        int[] dist = new int[n];
        Arrays.fill(dist, INF);
        dist[src] = 0;
        PriorityQueue<int[]> pq = new PriorityQueue<>(Comparator.comparingInt(a -> a[0]));
        pq.add(new int[]{0, src});
        
        while (!pq.isEmpty()) {
            int[] top = pq.poll();
            int d = top[0];
            int u = top[1];
            
            if (d > dist[u]) {
                continue;
            }
            
            for (int[] neighbor : adj.get(u)) {
                int v = neighbor[0];
                int w = neighbor[1];
                
                if (w + d < dist[v]) {
                    dist[v] = w + d;
                    pq.add(new int[]{dist[v], v});
                }
            }
        }
        
        return dist[dest];
    }

    public int[][] modifiedGraphEdges(int n, int[][] edges, int source, int destination, int target) {
        List<List<int[]>> adj = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            adj.add(new ArrayList<>());
        }
        
        for (int[] x : edges) {
            int a = x[0], b = x[1], c = x[2];
            if (c != -1) {
                adj.get(a).add(new int[]{b, c});
                adj.get(b).add(new int[]{a, c});
            }
        }
        
        int initialDist = dijkstra(n, source, destination, adj);
        if (initialDist < target) {
            return new int[][]{};
        }
        
        boolean flag = target == initialDist;
        for (int[] x : edges) {
            int a = x[0], b = x[1];
            int c = x[2];
            
            if (c == -1) {
                x[2] = flag ? INF : 1;
                if (!flag) {
                    adj.get(a).add(new int[]{b, x[2]});
                    adj.get(b).add(new int[]{a, x[2]});
                    
                    int newShortDist = dijkstra(n, source, destination, adj);
                    if (newShortDist <= target) {
                        flag = true;
                        x[2] += target - newShortDist;
                    }
                }
            }
        }
        
        if (!flag) {
            return new int[][]{};
        }
        
        return edges;
    }
}