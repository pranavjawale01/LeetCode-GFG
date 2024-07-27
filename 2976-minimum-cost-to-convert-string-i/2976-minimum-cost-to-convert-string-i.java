class Solution {
    private void dijkstra(long[][] arr, int s) {
        PriorityQueue<long[]> pq = new PriorityQueue<>(Comparator.comparingLong(a -> a[0]));
        long[] dist = new long[26];
        Arrays.fill(dist, Long.MAX_VALUE);
        dist[s] = 0;
        pq.offer(new long[]{0, s});

        while (!pq.isEmpty()) {
            long[] curr = pq.poll();
            long d = curr[0];
            int n = (int) curr[1];

            if (d > dist[n]) continue;

            for (int v = 0; v < 26; v++) {
                if (arr[n][v] != Long.MAX_VALUE && dist[v] > d + arr[n][v]) {
                    dist[v] = d + arr[n][v];
                    pq.offer(new long[]{dist[v], v});
                }
            }
        }

        for (int i = 0; i < 26; i++) {
            arr[s][i] = dist[i];
        }
    }

    public long minimumCost(String source, String target, char[] original, char[] changed, int[] cost) {
        Map<Character, List<int[]>> adj = new HashMap<>();
        for (int i = 0; i < original.length; i++) {
            adj.computeIfAbsent(original[i], k -> new ArrayList<>()).add(new int[]{changed[i], cost[i]});
        }

        long[][] arr = new long[26][26];
        for (long[] row : arr) {
            Arrays.fill(row, Long.MAX_VALUE);
        }

        for (char c = 'a'; c <= 'z'; c++) {
            if (adj.containsKey(c)) {
                for (int[] edge : adj.get(c)) {
                    arr[c - 'a'][edge[0] - 'a'] = edge[1];
                }
            }
        }

        for (int i = 0; i < 26; i++) {
            dijkstra(arr, i);
        }

        int n = target.length();
        long ans = 0;
        for (int i = 0; i < n; i++) {
            int u = source.charAt(i) - 'a';
            int v = target.charAt(i) - 'a';
            if (arr[u][v] == Long.MAX_VALUE) {
                return -1;
            }
            ans += arr[u][v];
        }
        return ans;
    }
}









// class Solution {
//     private void bellmanFord(long[][] arr, int s) {
//         int V = arr.length;
//         long[] dist = new long[V];
//         Arrays.fill(dist, Integer.MAX_VALUE);
//         dist[s] = 0;
//         for (int i = 0; i < V - 1; i++) {
//             for (int u = 0; u < V; u++) {
//                 for (int v = 0; v < V; v++) {
//                     if (dist[u] != Integer.MAX_VALUE && dist[u] + arr[u][v] < dist[v]) {
//                         dist[v] = dist[u] + arr[u][v];
//                     }
//                 }
//             }
//         }
//         for (int i = 0; i < V; i++) {
//             arr[s][i] = dist[i];
//         }
//     }
//     public long minimumCost(String source, String target, char[] original, char[] changed, int[] cost) {
//         long[][] arr = new long[26][26];
//         for (int i = 0; i < 26; i++) {
//             Arrays.fill(arr[i], Integer.MAX_VALUE);
//         }
//         int n = original.length;
//         for (int i = 0; i < n; i++) {
//             int u = original[i] - 'a';
//             int v = changed[i] - 'a';
//             arr[u][v] = Math.min((long)(cost[i]), arr[u][v]);
//         }
//         for (int i = 0; i < 26; i++) {
//             arr[i][i] = 0;
//         }
//         for (int i = 0; i < 26; i++) {
//             bellmanFord(arr, i);
//         }
//         n = target.length();
//         long ans = 0;
//         for (int i = 0; i < n; i++) {
//             int u = source.charAt(i) - 'a';
//             int v = target.charAt(i) - 'a';
//             if (arr[u][v] == Integer.MAX_VALUE) {
//                 return -1;
//             }
//             ans += arr[u][v];
//         }
//         return ans;
//     }
// }










// class Solution {
//     private void floydWarshall(long[][] arr) {
//         long val = Integer.MAX_VALUE;
//         for (int via = 0; via < 26; via++) {
//             for (int i = 0; i < 26; i++) {
//                 for (int j = 0; j < 26; j++) {
//                     if (arr[i][via] < val && arr[via][j] < val) {
//                         arr[i][j] = Math.min(arr[i][j], arr[i][via] + arr[via][j]);
//                     }
//                 }
//             }
//         }
//     }
//     public long minimumCost(String source, String target, char[] original, char[] changed, int[] cost) {
//         long[][] arr = new long[26][26];
//         for (int i = 0; i < 26; i++) {
//             Arrays.fill(arr[i], Integer.MAX_VALUE);
//         }
//         int n = original.length;
//         for (int i = 0; i < n; i++) {
//             int u = original[i] - 'a';
//             int v = changed[i] - 'a';
//             arr[u][v] = Math.min((long)(cost[i]), arr[u][v]);
//         }
//         for (int i = 0; i < 26; i++) {
//             arr[i][i] = 0;
//         }
//         floydWarshall(arr);
//         n = target.length();
//         long ans = 0;
//         for (int i = 0; i < n; i++) {
//             int u = source.charAt(i) - 'a';
//             int v = target.charAt(i) - 'a';
//             if (arr[u][v] == Integer.MAX_VALUE) {
//                 return -1;
//             }
//             ans += arr[u][v];
//         }
//         return ans;
//     }
// }