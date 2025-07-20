class Solution {
    private void bellmanFord(int n, int[][] edges, int[] result, int s) {
        result[s] = 0;
        for (int i = 1; i < n; i++) {
            for (int[] edge : edges) {
                int u = edge[0];
                int v = edge[1];
                int w = edge[2];
                if (result[u] != Integer.MAX_VALUE && result[u] + w < result[v]) {
                    result[v] = result[u] + w;
                }
                if (result[v] != Integer.MAX_VALUE && result[v] + w < result[u]) {
                    result[u] = result[v] + w;
                }
            }
        }
    }

    private int findResultCity(int n, int[][] spm, int distanceThreshold) {
        int resultCity = -1;
        int leastReachCount = Integer.MAX_VALUE;
        for (int i = 0; i < n; i++) {
            int countReach = 0;
            for (int j = 0; j < n; j++) {
                if (i != j && spm[i][j] <= distanceThreshold) {
                    countReach++;
                }
            }
            if (countReach < leastReachCount || (countReach == leastReachCount && i > resultCity)) {
                leastReachCount = countReach;
                resultCity = i;
            }
        }
        return resultCity;
    }

    public int findTheCity(int n, int[][] edges, int distanceThreshold) {
        int[][] spm = new int[n][n];
        for (int i = 0; i < n; i++) {
            Arrays.fill(spm[i], Integer.MAX_VALUE);
            spm[i][i] = 0;
        }
        for (int[] edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            spm[u][v] = w;
            spm[v][u] = w;
        }
        for (int i = 0; i < n; i++) {
            bellmanFord(n, edges, spm[i], i);
        }
        return findResultCity(n, spm, distanceThreshold);
    }
}












// class Solution {
//     private void dijkstra(int n, Map<Integer, List<Pair<Integer, Integer>>> mp, int[] result, int s) {
//         PriorityQueue<Pair<Integer, Integer>> pq = new PriorityQueue<>(Comparator.comparingInt(Pair::getKey));
//         pq.add(new Pair<>(0, s));
//         result[s] = 0;
//         while (!pq.isEmpty()) {
//             Pair<Integer, Integer> top = pq.poll();
//             int d = top.getKey();
//             int node = top.getValue();
//             for (Pair<Integer, Integer> nei : mp.get(node)) {
//                 int adjNode = nei.getKey();
//                 int dist = nei.getValue();
//                 if (d + dist < result[adjNode]) {
//                     result[adjNode] = d + dist;
//                     pq.add(new Pair<>(d + dist, adjNode));
//                 }
//             }
//         }
//     }

//     private int findResultCity(int n, int[][] spm, int d) {
//         int resultCity = -1;
//         int leastReachCount = Integer.MAX_VALUE;
//         for (int i = 0; i < n; i++) {
//             int countReach = 0;
//             for (int j = 0; j < n; j++) {
//                 if (i != j && spm[i][j] <= d) {
//                     countReach++;
//                 }
//             }
//             if (countReach <= leastReachCount) {
//                 leastReachCount = countReach;
//                 resultCity = i;
//             }
//         }
//         return resultCity;
//     }

//     public int findTheCity(int n, int[][] edges, int distanceThreshold) {
//         int[][] spm = new int[n][n];
//         Map<Integer, List<Pair<Integer, Integer>>> mp = new HashMap<>();
//         for (int i = 0; i < n; i++) {
//             Arrays.fill(spm[i], Integer.MAX_VALUE);
//             spm[i][i] = 0;
//             mp.put(i, new ArrayList<>());
//         }
//         for (int[] x : edges) {
//             int u = x[0];
//             int v = x[1];
//             int w = x[2];
//             mp.get(u).add(new Pair<>(v, w));
//             mp.get(v).add(new Pair<>(u, w));
//         }
//         for (int i = 0; i < n; i++) {
//             dijkstra(n, mp, spm[i], i);
//         }
//         return findResultCity(n, spm, distanceThreshold);
//     }
// }