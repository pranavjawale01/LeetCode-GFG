class Solution {
    private int[] parent;
    private int[] rank;

    private int find(int x) {
        if (x == parent[x])
            return x;
        return parent[x] = find(parent[x]);
    }

    private void union(int x, int y) {
        int xParent = find(x);
        int yParent = find(y);

        if (xParent == yParent)
            return;

        if (rank[xParent] > rank[yParent]) {
            parent[yParent] = xParent;
        } else if (rank[xParent] < rank[yParent]) {
            parent[xParent] = yParent;
        } else {
            parent[xParent] = yParent;
            rank[yParent]++;
        }
    }

    public int minCostConnectPoints(int[][] points) {
        int V = points.length;
        parent = new int[V];
        rank = new int[V];
        for (int i = 0; i < V; i++) {
            parent[i] = i;
            rank[i] = 0;
        }

        List<int[]> edges = new ArrayList<>();
        for (int i = 0; i < V; i++) {
            for (int j = i + 1; j < V; j++) {
                int x1 = points[i][0];
                int y1 = points[i][1];
                int x2 = points[j][0];
                int y2 = points[j][1];
                int d = Math.abs(x1 - x2) + Math.abs(y1 - y2);
                edges.add(new int[]{i, j, d});
            }
        }

        edges.sort((a, b) -> a[2] - b[2]);

        int sum = 0;
        for (int[] edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            if (find(u) != find(v)) {
                union(u, v);
                sum += wt;
            }
        }

        return sum;
    }
}






// class Solution {
//     static class Pair {
//         int weight, node;
//         Pair(int weight, int node) {
//             this.weight = weight;
//             this.node = node;
//         }
//     }
    
//     public int prims(List<List<Pair>> adj, int V) {
//         PriorityQueue<Pair> pq = new PriorityQueue<>(Comparator.comparingInt(p -> p.weight));
//         pq.offer(new Pair(0, 0));
//         boolean[] vis = new boolean[V];
//         int sum = 0;
        
//         while (!pq.isEmpty()) {
//             Pair p = pq.poll();
//             int w = p.weight;
//             int u = p.node;
//             if (vis[u]) {
//                 continue;
//             }
//             vis[u] = true;
//             sum += w;
//             for (Pair v : adj.get(u)) {
//                 int nei = v.node;
//                 int nwt = v.weight;
//                 if (!vis[nei]) {
//                     pq.offer(new Pair(nwt, nei));
//                 }
//             }
//         }
//         return sum;
//     }
    
//     public int minCostConnectPoints(int[][] points) {
//         int V = points.length;
//         List<List<Pair>> adj = new ArrayList<>();
//         for (int i = 0; i < V; i++) {
//             adj.add(new ArrayList<>());
//         }
//         for (int i = 0; i < V; i++) {
//             for (int j = i + 1; j < V; j++) {
//                 int x1 = points[i][0];
//                 int y1 = points[i][1];
//                 int x2 = points[j][0];
//                 int y2 = points[j][1];
                
//                 int d = Math.abs(x1 - x2) + Math.abs(y1 - y2);
//                 adj.get(i).add(new Pair(d, j));
//                 adj.get(j).add(new Pair(d, i));
//             }
//         }
//         return prims(adj, V);
//     }
// }